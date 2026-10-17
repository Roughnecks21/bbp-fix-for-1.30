modded class ActionTakeMaterialToHands
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		if ( target_entity && target_entity.CanUseConstruction() )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			string main_part_name = target_entity.GetActionComponentName( target.GetComponentIndex() );
			
			if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
			{
				construction_action_data.RefreshAttachmentsToDetach( target_entity, main_part_name );
			}
			EntityAI attachment = construction_action_data.GetActualAttachmentToDetach();
			
			if ( attachment && player.GetInventory().CanAddEntityIntoHands( attachment ) && attachment.GetHierarchyRootPlayer() != player )
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
