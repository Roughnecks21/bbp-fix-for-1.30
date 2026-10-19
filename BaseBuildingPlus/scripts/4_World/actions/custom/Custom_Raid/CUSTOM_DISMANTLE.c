class ActionDismantleBBPCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		ItemBase item = m_ActionData.m_MainItem;

		if (item && item.isBBPAdminTool())
        {
            m_ActionData.m_ActionComponent = new CAContinuousTime(0.1);
            return;
        }
		else
		{
			int dismantleTime = getBaseDismantleTimeBBP();
			m_ActionData.m_ActionComponent = new CAContinuousTime( dismantleTime );
		}
	}

	int getBaseDismantleTimeBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_DismantleTime;
		}
		else
		{
			return 60;
		}
	}
};

class ActionDismantleBBP: ActionContinuousBase
{
	void ActionDismantleBBP()
	{
		m_CallbackClass = ActionDismantleBBPCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;

		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#dismantle";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;//CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	private string customText = "ERROR";

    void SetCustomText(string text)
    {
        customText = "#dismantle " + text;
    }

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();

		if (targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
			if(bbpbase.CanCloseFence())
			{
				customText = "CLOSE THE DAMN DOOR TO DISMANTLE!";
			}

			m_Text = customText;
		}
		else
		{
			customText = "ERROR";
		}
	}

	override string GetText()
	{
		if(customText != "ERROR")
		{
			return customText;
		}
		return "ERROR";
	}

	bool HasDismantleToolBBP(ItemBase item_in_hands, ActionTarget target)
	{
		if(item_in_hands && item_in_hands.isBBPAdminTool())
		{
			return true;
		}

		TStringArray j_dismantleTools = GetDayZGame().GetBBPDismantleTools();
		foreach (string tool : j_dismantleTools)
		{
			if ( item_in_hands && item_in_hands.IsKindOf(tool))
			{
				return true;
			}
		}
		return false;
	}

	override bool CanBeUsedLeaning()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();

		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
            if (bbpbase && bbpbase.IsBBPGate() && bbpbase.obfm_BBPIsSecured()) return false;
			if(bbpbase && bbpbase.PartGetBBP() == "ERROR")
			{
				return false;
			}

			if(bbpbase && bbpbase.BBPGetTier() == 0 && HasDismantleToolBBP(item, target))
			{
				SetCustomText(bbpbase.PartGetBBP());
				return true;
			}

			if ( getDisableDismantleBBP() == 1 )
			{
				return false;
			}

			if (bbpbase && bbpbase.isDismantle() && HasDismantleToolBBP(item, target))
			{
				SetCustomText("");
				return true;
			}

			if (bbpbase && bbpbase.BBPGetTier() != 0 && bbpbase.BBPGetTier() != 69 && HasDismantleToolBBP(item, target))
			{
				#ifdef BASICTERRITORIES
				//perm check for dismantle
				if (player)
				{
					string theGUID = "";
					if ( player.GetIdentity() )
					{
						theGUID = player.GetIdentity().GetId();
					}
					if (!TerritoryFlag.HasTerritoryPermAtPos(theGUID, TerritoryPerm.DISMANTLE, bbpbase.GetPosition()))
					{
						GetBasicTerritoriesConfig().SendNotification(GetBasicTerritoriesConfig().DismantleWarningMessage, TerritoryIcons.DismantleWarning);
						return false;
					}
				}
				/* //allow dismantle anywhere for base members/owners
				if (player)
				{
					string theGUID_2 = "";
					if ( player.GetIdentity() )
					{
						theGUID_2 = player.GetIdentity().GetId();
					}

					if (TerritoryFlag.HasTerritoryPermAtPos(theGUID_2, TerritoryPerm.DISMANTLE, bbpbase.GetPosition()))
					{
						TerritoryFlag theFlag;
						if(theFlag.IsTerritoryOwner(theGUID_2) || heFlag.IsTerritoryMember(theGUID_2)
						{
							SetCustomText(bbpbase.PartGetBBP());
							return true;
						}
					}
				} */
				#endif

				#ifdef EXPANSIONMODBASEBUILDING
				//DismantleOutsideTerritory
				//0 = You cannot dismantle anything outside your own territory.
				//1 = You can dismantle everything unless if it's inside the territory of someone else.
				if ( !GetExpansionSettings().GetBaseBuilding().DismantleOutsideTerritory )
				{
					if ( !player.IsInTerritory() && !player.IsInsideOwnTerritory() )
					{
						return false;
					}

					else if ( player.IsInTerritory() && !player.IsInsideOwnTerritory() )
					{
						return false;
					}
				}

				//DismantleInsideTerritory
				//0 = You cannot dismantle anything inside the territories you don't own.
				//1 = You can dismantle inside the territory of everyone.
				if ( !GetExpansionSettings().GetBaseBuilding().DismantleInsideTerritory )
				{
					if ( player.IsInTerritory() && !player.IsInsideOwnTerritory() )
					{
						return false;
					}
				}

				//DismantleAnywhere
				//0 = You need to be on the soft side of the object to have the dismantle action.
				//1 = The dismantle action will be available from anywhere. If you are in the territory of someone else, you won't be able to dismantle.
				if ( GetExpansionSettings().GetBaseBuilding().DismantleAnywhere )
				{
					if (player.IsInTerritory() && player.IsInsideOwnTerritory() )
					{
							SetCustomText(bbpbase.PartGetBBP());
							return true;
					}
				}
				#endif

				if(bbpbase && bbpbase.isflat())
				{
					if (bbpbase && bbpbase.HasProperDistanceFlatBBP( "inside", player ))
					{
						SetCustomText(bbpbase.PartGetBBP());
						return true;
					}

					return false;
				}

				if(bbpbase && !bbpbase.isflat())
				{
					if (bbpbase && bbpbase.HasProperDistanceBBP( "inside", player ))
					{
						SetCustomText(bbpbase.PartGetBBP());
						return true;
					}
				}
				return false;
			}
			return false;
		}
		return false;
	}

	override bool ActionConditionContinue( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			return true;
		}
		else
		{
			customText = "ERROR";
			return false;
		}
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();

		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
            if (!bbpbase || (bbpbase.IsBBPGate() && bbpbase.obfm_BBPIsSecured())) return;
			Construction construction = bbpbase.GetConstruction();

			if (GetGame().IsServer())
			{
				string PlayerName = action_data.m_Player.GetIdentity().GetName();
				string PlayerPlainID = action_data.m_Player.GetIdentity().GetPlainId();
				m_AdminLog.LogPrint("[BBP] '" + PlayerName + "' (" + PlayerPlainID + ") DISMANTLED " + action_data.m_Target.GetObject().GetDisplayName() + " using " + action_data.m_MainItem.GetDisplayName() + " LOCATION:" + action_data.m_Player.GetPosition());
				//m_AdminLog.LogPrint("[BBP] '" + PlayerName + "' (" + PlayerPlainID + ") DISMANTLED " + action_data.m_Target.GetObject().GetDisplayName() + " using " + action_data.m_MainItem.GetDisplayName());
			}

			//frame
			if (bbpbase.GetConstruction().IsPartConstructed( "frame" ) && bbpbase.BBPGetTier() == 0)
			{
				construction.DismantlePartServerEx( action_data.m_Player, "frame" , AT_DISMANTLE_PART );

				ItemBase construction_kit = ItemBase.Cast(GetGame().CreateObjectEx(bbpbase.GetConstructionKitType(), targetObject.GetPosition(), ECE_PLACE_ON_SURFACE));
				construction_kit.SetPosition(action_data.m_Player.GetPosition()); //spawn kit

				//GetGame().ObjectDelete(action_data.m_Target.GetObject()); //delete
			}

			if(bbpbase.CanCloseFence())
			{
				construction.DismantlePartServerEx( action_data.m_Player, "frame" , AT_DISMANTLE_PART );
			}

			if(!bbpbase.BBP_HasDoor())
			{
				if (bbpbase.GetConstruction().IsPartConstructed( "t3_wall_concrete_bricks_2" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t3_wall_concrete_bricks_2" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t3_wall_concrete_bricks" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t3_wall_concrete_bricks" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "window_bars" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "window_bars" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t2_metal" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t2_metal" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t2_metal_2" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t2_metal_2" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t1_wall_logs_horizontal" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal_2" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t1_wall_logs_horizontal_2" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_planks" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t1_wall_planks" , AT_DISMANTLE_PART );
				}
			}

			if(bbpbase.BBP_HasDoor())
			{
				if (bbpbase.GetConstruction().IsPartConstructed( "t3_door" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t3_door" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t2_door" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t2_door" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "t1_door" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "t1_door" , AT_DISMANTLE_PART );
				}

				if (bbpbase.GetConstruction().IsPartConstructed( "window_bars" ))
				{
					construction.DismantlePartServerEx( action_data.m_Player, "window_bars" , AT_DISMANTLE_PART );
				}
			}

			//GetGame().ObjectDelete(action_data.m_Target.GetObject()); //delete

			if (!action_data.m_MainItem.isBBPAdminTool())
				action_data.m_MainItem.DecreaseHealth( getBaseDismantleToolDamageBBP(), false );
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight ); //add tool dmg
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		string PlayerName = action_data.m_Player.GetIdentity().GetName();
		string PlayerPlainID = action_data.m_Player.GetIdentity().GetPlainId();

		//logging dismantle message
		string message = ("[BBP] '" + PlayerName + "' (" + PlayerPlainID + ") DISMANTLED " + action_data.m_Target.GetObject().GetDisplayName() + " using " + action_data.m_MainItem.GetDisplayName() + " LOCATION " + action_data.m_Player.GetPosition());
		return message;
	}

	int getBaseDismantleToolDamageBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_BaseDismantleToolDamage;
		}
		return 0;
	}

	bool getDisableDismantleBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_DisableDismantle;
		}
		return false;
	}
}