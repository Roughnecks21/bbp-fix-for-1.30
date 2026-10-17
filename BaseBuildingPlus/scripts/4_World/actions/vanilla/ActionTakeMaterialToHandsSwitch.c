modded class ActionTakeMaterialToHandsSwitch
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		if ( target_entity && target_entity.CanUseConstruction() )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			
			string main_part_name = target_entity.GetActionComponentName( target.GetComponentIndex() );
			construction_action_data.RefreshAttachmentsToDetach( target_entity, main_part_name );
			
			if ( construction_action_data.GetAttachmentsToDetachCount() > 1 )
			{
				BBP_BASE bbpbase = BBP_BASE.Cast( target.GetObject() );
				if ( bbpbase )
				{
					if ( !bbpbase.isflat() && bbpbase.IsFacingPlayer( player, "BBP_BASE" ) )
					{
						return false;
					}
				}
			}
		}
		
		return super.ActionCondition(player, target, item);
	}
}
