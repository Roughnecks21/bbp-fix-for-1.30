// BBP-only interaction for DayZ 1.30 DigitalCodeLock when its model cannot be targeted.
// Uses the vanilla DigitalCodeLockUIBase / CodeLockComponent for PIN networking and persistence.
class obfc_ActionBBPDigitalCodeLock : ActionInteractCodeLockBase
{
    void obfc_ActionBBPDigitalCodeLock()
    {
        m_Text = "#STR_SET_CODE";
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINone();
        m_ConditionTarget = new CCTCursorInherited({BBP_BASE}, UAMaxDistances.DEFAULT);
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!super.ActionCondition(player, target, item) || !target)
            return false;

        BBP_BASE obfv_gate = BBP_BASE.Cast(target.GetObject());
        if (!obfv_gate || !obfv_gate.IsBBPGate())
            return false;

        DigitalCodeLock obfv_lock = obfv_gate.GetCodeLock();
        if (!obfv_lock || !obfv_lock.HasEnergy())
            return false;

        if (!obfv_lock.HasPIN())
        {
            if (!obfv_lock.CanSetCode())
                return false;
            m_Text = "#STR_SET_CODE";
            return true;
        }

        if (obfv_lock.IsLocked())
        {
            if (!obfv_lock.CanBeUnlocked() || obfv_lock.HasBruteForceProtection())
                return false;
            m_Text = "#STR_ENTER_CODE";
            return true;
        }

        if (obfv_lock.CanBeLocked() && !obfv_gate.IsOpened())
        {
            m_Text = "#STR_LOCK_CODELOCK";
            return true;
        }

        return false;
    }

    override void OnExecuteClient(ActionData action_data)
    {
        if (!action_data || !action_data.m_Target)
            return;

        BBP_BASE obfv_gate = BBP_BASE.Cast(action_data.m_Target.GetObject());
        if (!obfv_gate)
            return;

        DigitalCodeLock obfv_lock = obfv_gate.GetCodeLock();
        if (!obfv_lock || !obfv_lock.HasEnergy())
            return;

        if (!obfv_lock.HasPIN() || obfv_lock.IsLocked())
        {
#ifndef NO_GUI
            DigitalCodeLockUIBase obfv_ui = DigitalCodeLockUIBase.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_DIGITAL_CODELOCK, null));
            if (obfv_ui)
                obfv_ui.SetTargetLock(obfv_lock.GetCodeLockComponent());
#endif
        }
    }

    override void OnExecuteServer(ActionData action_data)
    {
        if (!action_data || !action_data.m_Target || !action_data.m_Player)
            return;

        BBP_BASE obfv_gate = BBP_BASE.Cast(action_data.m_Target.GetObject());
        if (!obfv_gate || !obfv_gate.IsBBPGate() || obfv_gate.IsOpened())
            return;

        DigitalCodeLock obfv_lock = obfv_gate.GetCodeLock();
        if (!obfv_lock || !obfv_lock.HasEnergy())
            return;

        if (obfv_lock.HasPIN() && !obfv_lock.IsLocked() && obfv_lock.CanBeLocked())
            obfv_lock.SetLockState(true);
    }

    override void OnExecute(ActionData action_data)
    {
        if (!GetGame().IsMultiplayer())
        {
            OnExecuteServer(action_data);
            OnExecuteClient(action_data);
        }
    }
}
