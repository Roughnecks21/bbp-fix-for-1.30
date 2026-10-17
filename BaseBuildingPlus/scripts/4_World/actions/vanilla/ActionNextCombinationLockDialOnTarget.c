modded class ActionNextCombinationLockDialOnTarget
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			BBP_BASE bbpbase = BBP_BASE.Cast( targetObject);
			
			if ( bbpbase && bbpbase.IsLocked() && !player.GetItemInHands() )
			{
				string selection = bbpbase.GetActionComponentName( target.GetComponentIndex() );
				
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetCombinationLock( bbpbase.GetCombinationLock() );
				
				return true;
			}
		}
		
		//return false;
		return super.ActionCondition ( player, target, item );
	}
}
