modded class ActionBuildPartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		ItemBase item = m_ActionData.m_MainItem;
        if (item && item.isBBPAdminTool())
        {
            m_ActionData.m_ActionComponent = new CAContinuousTime(0.1);
            return;
        }

		int buildTime = GetDayZGame().getBBPBuildTime();
		m_ActionData.m_ActionComponent = new CAContinuousTime( buildTime );
        return;
	}
};

modded class ActionBuildPart: ActionContinuousBase
{
	bool HasBuildTool(ItemBase item_in_hands, ActionTarget target)
	{
		TStringArray j_buildTools = GetDayZGame().GetBBPBuildTools();
		foreach (string tool : j_buildTools)
		{
			if ( item_in_hands && item_in_hands.IsKindOf(tool) )
			{
				return true;
			}
			if ( target.GetObject().CanUseHandConstruction() )
			{
				return true;
			}
		}
		return false;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if (targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
			if(bbpbase.CanCloseFence())
			{
				m_Text = "CLOSE THE DAMN DOOR TO BUILD!";
			}

			else
			{
				super.OnActionInfoUpdate(player,target,item);
			}
		}
		else
		{
			super.OnActionInfoUpdate(player,target,item);
		}
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();

		if ( player.IsPlacingLocal() || player.IsPlacingServer() )
			return false;

		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;

		if (targetObject.IsInherited(BBP_BASE))
		{
			if ( (!GetGame().IsDedicatedServer()) )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				int start_index = construction_action_data.m_PartIndex;
				if ( construction_action_data.GetConstructionPartsCount() > 0 )
				{
					for (int i = 0; i < construction_action_data.GetConstructionPartsCount(); i++)
					{
						if ( MiscGameplayFunctions.ComplexBuildCollideCheckClient(player, target, item, i) )
						{
							//Print("i: " + i + " | name: " + construction_action_data.GetCurrentBuildPart().GetPartName());
							return true;
						}
						else
						{
							construction_action_data.SetNextIndex();
						}
					}
					construction_action_data.m_PartIndex = start_index;
					//Print("fail | name: " + construction_action_data.GetCurrentBuildPart().GetPartName());
				}
				return false;
			}
		}

		return super.ActionCondition( player, target, item );
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		//super.OnFinishProgressServer(action_data);
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		string objectName = base_building.GetType();
		string part_name = BuildPartActionData.Cast(action_data).m_PartType;
		objectName.ToLower();
		part_name.ToLower();

		if ( action_data.m_MainItem.isBBPAdminTool() )
		{
			//build
			construction.AdminBuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
			action_data.m_MainItem.DecreaseHealth(0, false );
			}
			else
			{
			super.OnFinishProgressServer(action_data);
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( getBaseBuildToolDamageBBP(), false );
		}
	}

	int getBaseBuildToolDamageBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_BaseBuildToolDamage;
		}
		else
		{
			return 1;
		}
	}

	ItemBase BBPCollision( ActionTarget target )
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.2 0"; //we need to lift BBox even more, because it collides with house floors due to various reasons (probably geometry or float imperfections)
		Object targetObject = target.GetObject();
		vector orientation = targetObject.GetOrientation();
		vector edge_length = Vector( 0.2, 0.2, 0.2 );
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		targetObject.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = targetObject.GetPosition() + relative_ofset + absolute_ofset;
		//excluded_objects.Insert( targetObject );
		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{
			for ( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if ( obj_collided.IsInherited(BBP_BASE) )
				{
					BBP_BASE BBPbase = BBP_BASE.Cast(obj_collided);
					return BBPbase;
				}
			}
		}
		return null;
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		string partName = BuildPartActionData.Cast(action_data).m_PartType;
		ItemBase item = action_data.m_MainItem;

		if (item && item.isBBPAdminTool())
		{
			string message_BBP = string.Format("ADMIN_HAMMER USED: Built %1 on %2 with %3", partName, action_data.m_Target.GetObject().GetDisplayName(), action_data.m_MainItem.GetDisplayName() );
			return message_BBP;
		}
		else
		{
			string message = string.Format("Built %1 on %2 with %3", partName, action_data.m_Target.GetObject().GetDisplayName(), action_data.m_MainItem.GetDisplayName() );
			return message;
		}
	}
}
