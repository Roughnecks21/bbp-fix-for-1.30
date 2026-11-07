#ifdef EXPANSIONMODBASEBUILDING
modded class ActionAttachOnProxy
{
#ifndef SERVER
    override void AttachItem(AttachActionData action_data)
    {
        super.AttachItem(action_data);

        if (!action_data || !action_data.m_Target || !action_data.m_MainItem) return;
        if (!DigitalCodeLock.Cast(action_data.m_MainItem)) return;
        if (!BBP_BASE.Cast(action_data.m_Target.GetParentOrObject())) return;

        ScriptCallQueue queue = GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY);
        queue.Remove(ExpansionCodeLockUI.Open);
        queue.CallLater(ExpansionCodeLockUI.Open, 250, false, action_data.m_MainItem, 0, "", false, true);
    }
#endif
}
#endif
