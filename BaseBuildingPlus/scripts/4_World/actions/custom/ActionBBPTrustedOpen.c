// Native Digital Code Lock access for BBP gates.
// The code lock remains locked while trusted players open or close the door.
class ActionBBPTrustedOpen : ActionInteractCodeLockBase
{
    void ActionBBPTrustedOpen()
    {
        m_Text = "Open Locked Door";
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!player || !target || !super.ActionCondition(player, target, item)) return false;

        BBP_BASE gate = BBP_BASE.Cast(target.GetObject());
        if (!gate || !gate.IsBBPGate() || !gate.HasFullyConstructedGate()) return false;

        DigitalCodeLock codeLock = gate.GetCodeLock();
        if (!codeLock || !codeLock.HasPIN() || !codeLock.HasEnergy()) return false;

        if (gate.isBBPDoor() && !gate.BBP_HasDoor()) return false;
        if (gate.isWindow())
        {
            if (!gate.BBP_HasDoor()) return false;
            if (gate.isSmall())
            {
                if (!gate.HasProperDistanceBBP("inside", player)) return false;
            }
            else if (!gate.HasProperDistanceBBPWindow("inside2", player))
            {
                return false;
            }
        }

        if (gate.IsOpened())
        {
            if (codeLock.IsLocked()) m_Text = "Close Locked Door";
            else m_Text = "Close Door";
        }
        else
        {
            if (codeLock.IsLocked()) m_Text = "Open Locked Door";
            else m_Text = "Open Door";
        }
        // Client cannot read server-only trusted IDs. Validate on server.
        return true;
    }

    override void OnStartServer(ActionData action_data)
    {
        super.OnStartServer(action_data);
        if (!action_data || !action_data.m_Player || !action_data.m_Target) return;

        PlayerBase player = action_data.m_Player;
        BBP_BASE gate = BBP_BASE.Cast(action_data.m_Target.GetObject());
        if (!gate || !gate.IsBBPGate() || !gate.HasFullyConstructedGate()) return;
        if (vector.Distance(player.GetPosition(), gate.GetPosition()) > 5.0) return;
        if (!ActionCondition(player, action_data.m_Target, action_data.m_MainItem))
        {
            return;
        }

        DigitalCodeLock codeLock = gate.GetCodeLock();
        if (!codeLock || !codeLock.HasPIN() || !codeLock.HasEnergy()) return;

        // Invalid dual-lock combinations must not be bypassed.
        if (gate.GetCombinationLock())
        {
            return;
        }
#ifdef EXPANSIONMODBASEBUILDING
        // ExpansionIsLocked() can also reflect another lock type. Only
        // reject an actual second Expansion lock on the same BBP gate.
        if (gate.ExpansionGetCodeLock())
        {
            return;
        }
#endif

        if (codeLock.IsLocked() && !BBPTrustedLock.IsTrusted(codeLock, player))
        {
            return;
        }

        if (gate.IsOpened())
        {
            gate.BBPTrustedCloseDoor();
        }
        else
        {
            gate.BBPTrustedOpenDoor();
        }
    }
}
