// BBP-only interaction for DayZ 1.30 DigitalCodeLock when its model cannot be targeted.
// Uses the vanilla DigitalCodeLockUIBase / CodeLockComponent for PIN networking and persistence.
class ActionBBPDigitalCodeLock : ActionInteractCodeLockBase
{
    void ActionBBPDigitalCodeLock()
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

        BBP_BASE bbpGate = BBP_BASE.Cast(target.GetObject());
        if (!bbpGate || !bbpGate.IsBBPGate())
            return false;
        if (!bbpGate.BBPCanInteractDoor(target))
            return false;

        DigitalCodeLock attachedLock = bbpGate.GetCodeLock();
        if (!attachedLock || !attachedLock.HasEnergy())
            return false;

        if (bbpGate.GetCombinationLock()) return false;
#ifdef EXPANSIONMODBASEBUILDING
        if (bbpGate.ExpansionGetCodeLock()) return false;
#endif

        if (!attachedLock.HasPIN())
        {
            if (!attachedLock.CanSetCode())
                return false;
            m_Text = "#STR_SET_CODE";
            return true;
        }

        if (attachedLock.IsLocked())
        {
            if (!attachedLock.CanBeUnlocked() || attachedLock.HasBruteForceProtection())
                return false;
            m_Text = "#STR_ENTER_CODE";
            return true;
        }

        if (attachedLock.CanBeLocked() && !bbpGate.IsOpened())
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

        BBP_BASE bbpGate = BBP_BASE.Cast(action_data.m_Target.GetObject());
        if (!bbpGate)
            return;

        DigitalCodeLock attachedLock = bbpGate.GetCodeLock();
        if (!attachedLock || !attachedLock.HasEnergy())
            return;

        if (bbpGate.GetCombinationLock()) return;
#ifdef EXPANSIONMODBASEBUILDING
        if (bbpGate.ExpansionGetCodeLock()) return;
#endif

        if (!attachedLock.HasPIN() || attachedLock.IsLocked())
        {
#ifndef NO_GUI
            DigitalCodeLockUIBase lockMenu = DigitalCodeLockUIBase.Cast(GetGame().GetUIManager().EnterScriptedMenu(MENU_DIGITAL_CODELOCK, null));
            if (lockMenu)
                lockMenu.SetTargetLock(attachedLock.GetCodeLockComponent());
#endif
        }
    }

    override void OnExecuteServer(ActionData action_data)
    {
        if (!action_data || !action_data.m_Target || !action_data.m_Player)
            return;

        BBP_BASE bbpGate = BBP_BASE.Cast(action_data.m_Target.GetObject());
        if (!bbpGate || !bbpGate.IsBBPGate() || bbpGate.IsOpened())
            return;
        if (!bbpGate.BBPCanInteractDoor(action_data.m_Target))
            return;

        DigitalCodeLock attachedLock = bbpGate.GetCodeLock();
        if (!attachedLock || !attachedLock.HasEnergy())
            return;

        if (bbpGate.GetCombinationLock()) return;
#ifdef EXPANSIONMODBASEBUILDING
        if (bbpGate.ExpansionGetCodeLock()) return;
#endif

        if (attachedLock.HasPIN() && !attachedLock.IsLocked() && attachedLock.CanBeLocked())
            attachedLock.SetLockState(true);
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
