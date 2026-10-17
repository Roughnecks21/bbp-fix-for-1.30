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
		BBP_BASE obfv_bbp = BBP_BASE.Cast(action_data.m_Target.GetObject());
		if (!obfv_bbp)
		{
			super.OnFinishProgressServer(action_data);
			return;
		}
		CombinationLock obfv_lock = obfv_bbp.GetCombinationLock();
		if (!obfv_lock) return;
		obfv_lock.DialNextNumber();
		if (!obfv_lock.IsLocked()) obfv_lock.UnlockOnServer(action_data.m_Player, obfv_bbp);
	}
}
