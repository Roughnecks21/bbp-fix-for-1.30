modded class ActionTogglePlaceObject
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if(snappingEnabled)
		{
			if(item.IsKindOf("BBP_KIT_BASE") && !player.IsPlacingLocal())
			{
				if(player.GetItemInHands())
				{
					player.PlacingStartLocal(item);
					return false;
				}
			}
		}
		return super.ActionCondition(player, target, item);
	}
};