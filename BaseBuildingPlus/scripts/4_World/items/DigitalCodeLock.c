// BBP-only power rule for the DayZ 1.30 Digital Code Lock.
// Vanilla doors and fences retain their original battery requirement.
modded class DigitalCodeLock
{
    protected bool BBP_BatteryOptional()
    {
        BBP_BASE door = BBP_BASE.Cast(GetHierarchyParent());
        if (!door || !door.IsBBPGate())
            return false;

        BBPConfig config = GetDayZGame().getBBPGlobals();
        if (!config && GetGame().IsServer())
            config = BBPGlobals.Get();

        return config && !config.BBP_RequireVanillaCodeLockBattery;
    }

    override bool NeedBattery()
    {
        if (BBP_BatteryOptional())
            return false;
        return super.NeedBattery();
    }

    override bool HasBattery()
    {
        if (BBP_BatteryOptional())
            return true;
        return super.HasBattery();
    }

    override bool HasEnergy()
    {
        if (BBP_BatteryOptional())
            return true;
        return super.HasEnergy();
    }

    protected void BBP_UpdateBatterylessStage()
    {
        if (!m_CodeLockComponent || GetStage() >= CodeLockStage.PROTECTION_STAGE_ONE)
            return;

        if (HasPIN())
            m_CodeLockComponent.SetStage(CodeLockStage.NORMAL);
        else
            m_CodeLockComponent.SetStage(CodeLockStage.SETTING);

        SetSynchDirty();
        ForceFullVisualsUpdate();
    }

    override void OnWasAttached(EntityAI parent, int slot_id)
    {
        super.OnWasAttached(parent, slot_id);
        if ((GetGame().IsServer() || !GetGame().IsMultiplayer()) && BBP_BatteryOptional())
            BBP_UpdateBatterylessStage();
    }

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        CodeLockStage previousStage = GetStage();
        super.EEItemDetached(item, slot_name);

        if (slot_name != "BatteryD" || !BBP_BatteryOptional())
            return;

        if (!GetGame().IsServer() && GetGame().IsMultiplayer())
            return;

        if (previousStage >= CodeLockStage.PROTECTION_STAGE_ONE)
        {
            m_CodeLockComponent.SetStage(previousStage);
            SetSynchDirty();
        }
        else
            BBP_UpdateBatterylessStage();
    }

    override void OnWorkStop()
    {
        if (!BBP_BatteryOptional())
            super.OnWorkStop();
    }

    override void OnWork(float consumed_energy)
    {
        if (!BBP_BatteryOptional())
            super.OnWork(consumed_energy);
    }
}
