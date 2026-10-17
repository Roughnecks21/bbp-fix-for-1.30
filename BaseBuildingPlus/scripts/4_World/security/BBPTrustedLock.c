// BBP remembered access for DayZ 1.30 DigitalCodeLock.
// Authorisation is granted only after vanilla CodeLockComponent accepts a PIN.
// Unpersisted locks keep access in memory until they receive a persistent ID.

class BBPTrustedUsers
{
    ref array<string> PlayerIds;

    void BBPTrustedUsers()
    {
        PlayerIds = new array<string>;
    }
}

modded class DigitalCodeLock
{
    protected ref array<string> m_BBPTrustedPlayerIds;

    bool BBPHasTrustedPlayer(string playerId)
    {
        return playerId != "" && m_BBPTrustedPlayerIds && m_BBPTrustedPlayerIds.Find(playerId) >= 0;
    }

    void BBPRememberPlayer(string playerId)
    {
        if (playerId == "") return;
        if (!m_BBPTrustedPlayerIds) m_BBPTrustedPlayerIds = new array<string>;
        if (m_BBPTrustedPlayerIds.Find(playerId) < 0) m_BBPTrustedPlayerIds.Insert(playerId);
    }

    void BBPCopyTrustedPlayers(array<string> playerIds)
    {
        if (!playerIds || !m_BBPTrustedPlayerIds) return;
        foreach (string playerId : m_BBPTrustedPlayerIds)
        {
            if (playerId != "" && playerIds.Find(playerId) < 0) playerIds.Insert(playerId);
        }
    }

    void BBPClearTrustedPlayers()
    {
        if (m_BBPTrustedPlayerIds) m_BBPTrustedPlayerIds.Clear();
    }
}

class BBPTrustedLock
{
    static const string ACCESS_DIRECTORY = "$profile:BBP_DigitalLockAccess";

    static string GetPath(DigitalCodeLock codeLock)
    {
        if (!codeLock) return "";

        int idA, idB, idC, idD;
        codeLock.GetPersistentID(idA, idB, idC, idD);
        if (idA == 0 && idB == 0 && idC == 0 && idD == 0) return "";

        return ACCESS_DIRECTORY + "\\" + idA.ToString() + "_" + idB.ToString() + "_" + idC.ToString() + "_" + idD.ToString() + ".json";
    }

    static bool IsTrusted(DigitalCodeLock codeLock, PlayerBase player)
    {
        if (!GetGame().IsServer() || !codeLock || !player || !player.GetIdentity()) return false;

        string playerId = player.GetIdentity().GetId();
        if (playerId == "") return false;
        if (codeLock.BBPHasTrustedPlayer(playerId)) return true;

        string path = GetPath(codeLock);
        if (path == "" || !FileExist(path)) return false;

        BBPTrustedUsers data = new BBPTrustedUsers;
        JsonFileLoader<BBPTrustedUsers>.JsonLoadFile(path, data);
        if (!data || !data.PlayerIds) return false;

        if (data.PlayerIds.Find(playerId) < 0) return false;
        codeLock.BBPRememberPlayer(playerId);
        return true;
    }

    static void Remember(DigitalCodeLock codeLock, PlayerIdentity identity)
    {
        if (!GetGame().IsServer() || !codeLock || !identity) return;

        BBP_BASE gate = BBP_BASE.Cast(codeLock.GetHierarchyParent());
        if (!gate || !gate.IsBBPGate()) return;

        string playerId = identity.GetId();
        if (playerId == "") return;

        // CodeLockComponent has already accepted the PIN on the server.
        // PlayerIdentity.GetPlayer() is not guaranteed to resolve during an RPC.
        Man playerEntity = identity.GetPlayer();
        if (playerEntity && vector.Distance(playerEntity.GetPosition(), gate.GetPosition()) > 5.0) return;

        if (codeLock.BBPHasTrustedPlayer(playerId)) return;
        codeLock.BBPRememberPlayer(playerId);
        SavePending(codeLock, 0);
    }

    static void SavePending(DigitalCodeLock codeLock, int attempt)
    {
        if (!GetGame().IsServer() || !codeLock) return;

        BBP_BASE gate = BBP_BASE.Cast(codeLock.GetHierarchyParent());
        if (!gate || !gate.IsBBPGate()) return;

        string path = GetPath(codeLock);
        if (path == "")
        {
            if (attempt < 20)
            {
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BBPTrustedLock.SavePending, 15000, false, codeLock, attempt + 1);
            }
            else
            {
                Print("[BBP-LOCK] Could not save remembered access: digital lock has no persistent ID.");
            }
            return;
        }

        BBPTrustedUsers data = new BBPTrustedUsers;
        if (FileExist(path)) JsonFileLoader<BBPTrustedUsers>.JsonLoadFile(path, data);
        if (!data || !data.PlayerIds) data = new BBPTrustedUsers;

        codeLock.BBPCopyTrustedPlayers(data.PlayerIds);
        MakeDirectory(ACCESS_DIRECTORY);
        JsonFileLoader<BBPTrustedUsers>.JsonSaveFile(path, data);
    }

    static void Clear(DigitalCodeLock codeLock)
    {
        if (!GetGame().IsServer() || !codeLock) return;

        codeLock.BBPClearTrustedPlayers();
        string path = GetPath(codeLock);
        if (path != "" && FileExist(path)) DeleteFile(path);
    }
}

modded class CodeLockComponent
{
    override protected void CheckCodeRequest(string pin, PlayerIdentity identity)
    {
        bool wasLocked = m_IsLocked;
        bool hadPIN = m_HasPIN;

        super.CheckCodeRequest(pin, identity);

        if (identity && m_Parent && ((!hadPIN && m_HasPIN) || (wasLocked && !m_IsLocked)))
        {
            DigitalCodeLock codeLock = DigitalCodeLock.Cast(m_Parent);
            BBPTrustedLock.Remember(codeLock, identity);
        }
    }

    override bool SetLockCode(string pin, bool sync = true)
    {
        DigitalCodeLock codeLock = DigitalCodeLock.Cast(m_Parent);
        if (m_HasPIN && pin != m_LockPIN) BBPTrustedLock.Clear(codeLock);
        return super.SetLockCode(pin, sync);
    }

    override void ResetPIN(bool sync = true)
    {
        DigitalCodeLock codeLock = DigitalCodeLock.Cast(m_Parent);
        BBPTrustedLock.Clear(codeLock);
        super.ResetPIN(sync);
    }
}
