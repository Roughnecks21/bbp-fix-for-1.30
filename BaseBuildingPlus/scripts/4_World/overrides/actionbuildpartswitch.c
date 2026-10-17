modded class ActionBuildPartSwitch: ActionSingleUseBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//hack solution
		if ((!GetGame().IsDedicatedServer()) )
		{
			ActionBase ab = ActionManagerClient.Cast(player.GetActionManager()).GetPossibleAction(ContinuousDefaultActionInput);
			if (ab && ab.Type() != ActionBuildPart)
			{
				return false;
			}
			
			//Action not allowed if player has broken legs
			if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
				return false;
			
			//hack - gate
			if (target.GetObject() && (!target.GetObject().CanUseConstructionBuild() || target.GetObject().CanUseHandConstruction()))
				return false;
		}
		
		if ( player && !player.IsLeaning() )
		{
			Object target_object = target.GetObject();
			if ( target_object && target_object.CanUseConstruction() )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetTarget( target_object );
				
				string main_part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
				construction_action_data.RefreshPartsToBuild( main_part_name, item, !target_object.CanUseHandConstruction() );
				
				if ( base_building.isBBP_Object() )
				{
					int valid_recipes_BBP = 0;
					for (int bbp = 0; bbp < construction_action_data.GetConstructionPartsCount(); bbp++)
					{
						if ( MiscGameplayFunctions.ComplexBuildCollideCheckClient(player, target, item, bbp) )
						{
							valid_recipes_BBP++;
						}
					}
					
					if (valid_recipes_BBP > 1)
					{
						return true;
					}
				}
				
				if ( construction_action_data.GetConstructionPartsCount() > 1 )
				{
					if ( base_building.IsPlayerInside( player, main_part_name ) && !player.GetInputController().CameraIsFreeLook() )
					{
/*
						//Camera check (client-only)
						if ( (!GetGame().IsDedicatedServer()) && base_building.IsFacingCamera( main_part_name ))
							return false;
*/
						//Check validity of recipes
						int valid_recipes = 0;
						for (int i = 0; i < construction_action_data.GetConstructionPartsCount(); i++)
						{
							if ( MiscGameplayFunctions.ComplexBuildCollideCheckClient(player, target, item, i) )
							{
								valid_recipes++;
							}
						}
						
						if (valid_recipes > 1)
						{
							return true;
						}
					}
				}
			}
		}
		
		return false;
	}	
}