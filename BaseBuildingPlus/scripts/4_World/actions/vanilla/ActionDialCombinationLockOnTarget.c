modded class ActionDialCombinationLockOnTarget
{
    override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object targetObject = target.GetObject();
        BBP_BASE bbpbase = BBP_BASE.Cast( targetObject);
        
        if ( bbpbase && bbpbase.GetCombinationLock() && bbpbase.GetCombinationLock().IsLocked() )
        {
            string selection = bbpbase.GetActionComponentName( target.GetComponentIndex() );
            
            ConstructionActionData construction_action_data = player.GetConstructionActionData();
            construction_action_data.SetCombinationLock( bbpbase.GetCombinationLock() );
            
            return true;
        }
        //return false;
		return super.ActionCondition ( player, target, item );
    }

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data || !action_data.m_Target || !action_data.m_Player) return;
		BBP_BASE bbpGate = BBP_BASE.Cast(action_data.m_Target.GetObject());
		if (!bbpGate)
		{
			super.OnFinishProgressServer(action_data);
			return;
		}
		CombinationLock attachedLock = bbpGate.GetCombinationLock();
		if (!attachedLock) return;
		attachedLock.DialNextNumber();
		if (!attachedLock.IsLocked()) attachedLock.UnlockOnServer(action_data.m_Player, bbpGate);
	}
}
