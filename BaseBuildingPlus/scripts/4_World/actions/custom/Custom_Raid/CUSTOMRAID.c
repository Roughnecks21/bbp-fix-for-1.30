class ActionDestroyBBPCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		Object targetObject = m_ActionData.m_Target.GetObject();
		BaseBuildingBase m_target = BaseBuildingBase.Cast(targetObject);
		int raidTime = GetRaidTimeBBP();
		m_ActionData.m_ActionComponent = new CAContinuousTime( raidTime );
		ItemBase item = m_ActionData.m_MainItem;
        if (item && item.isBBPAdminTool())
        {
            m_ActionData.m_ActionComponent = new CAContinuousTime(0.1);
			return;
        }
	}

	int GetRaidTimeBBP()
	{
		BaseBuildingBase targetObject = BaseBuildingBase.Cast( m_ActionData.m_Target.GetObject() );
		BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
		PlayerBase BBP_player = m_ActionData.m_Player;
		//Concrete
		if ( bbpbase.BBPGetTier() == 3 )
		{
			return getBaseDestroyTimeT3();
		}
		//Metal
		else if ( bbpbase.BBPGetTier() == 2)
		{
			return getBaseDestroyTimeT2();
		}
		//Wood
		else if ( bbpbase.BBPGetTier() == 1)
		{
			return getBaseDestroyTimeT1();
		}
		
		//frame
		else
		{
			return 5;
		}
		//Default
		return getBaseDestroyTimeT1();
	}

	int getBaseDestroyTimeT3()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_Tier3RaidTime;
		}
		else
		{
			return 1200;
		}
	}
	int getBaseDestroyTimeT2()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_Tier2RaidTime;
		}
		else
		{
			return 300;
		}
	}
	int getBaseDestroyTimeT1()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_Tier1RaidTime;
		}
		else
		{
			return 600;
		}
	}
};

class ActionDestroyBBP: ActionContinuousBase
{
	void ActionDestroyBBP()
	{
		m_CallbackClass = ActionDestroyBBPCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;		
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#destroy";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;//CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
	
	override bool CanBeUsedLeaning()
	{
		return false;
	}
		
	private string customText = "ERROR";
	
    void SetCustomText(string text)
    {
        customText = "#destroy " + text;
    } 
	
	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		
		if (targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
			if(bbpbase.CanCloseFence())
			{
				customText = "CLOSE THE DAMN DOOR TO RAID!";
			}
			
			m_Text = customText;
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
	
	bool HasRaidToolT1(ItemBase item_in_hands, ActionTarget target)
	{
		if(item_in_hands && item_in_hands.isBBPAdminTool())
		{
			return true;
		}
		
		TStringArray j_raidingToolsW = GetDayZGame().GetBBPRaidToolsT1();
		foreach (string toolW : j_raidingToolsW) 
		{
			if ( item_in_hands && item_in_hands.IsKindOf(toolW))
			{
				return true;
			}
		}
		return false;
	}

	bool HasRaidToolT2(ItemBase item_in_hands, ActionTarget target)
	{
		if(item_in_hands && item_in_hands.isBBPAdminTool())
		{
			return true;
		}
		
		TStringArray j_raidingToolsM = GetDayZGame().GetBBPRaidToolsT2();
		foreach (string toolM : j_raidingToolsM) 
		{
			if ( item_in_hands && item_in_hands.IsKindOf(toolM) )
			{
				return true;
			}
		}
		return false;
	}

	bool HasRaidToolT3(ItemBase item_in_hands, ActionTarget target)
	{
		if(item_in_hands && item_in_hands.isBBPAdminTool())
		{
			return true;
		}
		
		TStringArray j_raidingToolsC = GetDayZGame().GetBBPRaidToolsT3();
		foreach (string tool : j_raidingToolsC)
		{
			if ( item_in_hands && item_in_hands.IsKindOf(tool))
			{
				return true;
			}
		}
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;
		
		if (targetObject && !targetObject.IsInherited(BBP_BASE))
		{
			return false;
		}
		
		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
			
			if ( bbpbase && bbpbase.isDismantle() )
			{
				return false;
			}
			
			if ( bbpbase && bbpbase.DisableDestroyBBP() )
			{
				return false;
			}

			if ( getDisableDestroyBBP() == 1 )
			{
				return false;
			}
			
			if ( bbpbase && bbpbase.DisableDestroyBBP() )
			{
				return false;
			}
			
			if (bbpbase && bbpbase.BBPGetTier() != 69)  //frame //t1_wall_logs_horizontal //t2_metal //t3_wall_concrete_bricks //t1_door //t3_door
			{	
				if(!bbpbase.isflat() && !bbpbase.HasProperDistanceBBP( "inside", player) || (bbpbase.isflat() && !bbpbase.HasProperDistanceFlatBBP( "inside", player)))
				{
					//door dumbass logic
					if ( getBaseRaidOnlyDoorsBBP() == 1 )
					{
						if(bbpbase && bbpbase.IsBBPGate())
						{
							if(bbpbase.BBPGetTier() == 3)
							{
								if ( !HasRaidToolT3(item, target) )
								{
									return false;
								}
								
								SetCustomText(bbpbase.PartGetBBP());
								return true;
							}
							
							//t2
							else if(bbpbase.BBPGetTier() == 2)
							{
								if ( !HasRaidToolT2(item, target) )
								{
									return false;
								}
								
								SetCustomText(bbpbase.PartGetBBP());
								return true;
							}
							
							//t1
							else if(bbpbase.BBPGetTier() == 1)
							{
								if ( !HasRaidToolT1(item, target) )
								{
									return false;
								}
								
								SetCustomText(bbpbase.PartGetBBP());
								return true;
							}
							
							//door only built
							else if(bbpbase.BBPGetTier() == 0)
							{
								if ( !HasRaidToolT1(item, target) )
								{
									return false;
								}
								
								SetCustomText(bbpbase.PartGetBBP());
								return true;
							}								
						}
						return false;	
					}					

					//t3
					if(bbpbase.BBPGetTier() == 3)
					{
						if ( !HasRaidToolT3(item, target) )
						{
							return false;
						}
						
						SetCustomText(bbpbase.PartGetBBP());
						return true;
					}
					
					//t2
					else if(bbpbase.BBPGetTier() == 2)
					{
						if ( !HasRaidToolT2(item, target) )
						{
							return false;
						}
						
						SetCustomText(bbpbase.PartGetBBP());
						return true;
					}
					
					//t1
					else if(bbpbase.BBPGetTier() == 1)
					{
						if ( !HasRaidToolT1(item, target) )
						{
							return false;
						}
						
						SetCustomText(bbpbase.PartGetBBP());
						return true;
					}
					
					//door only
					else if(bbpbase.BBPGetTier() == 0)
					{
						if ( !HasRaidToolT1(item, target) )
						{
							return false;
						}
						
						SetCustomText(bbpbase.PartGetBBP());
						return true;
					}
				}
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
		
		if (targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
			Construction construction = bbpbase.GetConstruction();
			
			if (GetGame().IsServer())
			{	
				string PlayerName = action_data.m_Player.GetIdentity().GetName();
				string PlayerPlainID = action_data.m_Player.GetIdentity().GetPlainId();
				m_AdminLog.LogPrint("[BBP] '" + PlayerName + "' (" + PlayerPlainID + ") DESTROYED " + action_data.m_Target.GetObject().GetDisplayName() + " using " + action_data.m_MainItem.GetDisplayName() + " LOCATION:" + action_data.m_Player.GetPosition());

				//m_AdminLog.LogPrint("[BBP] '" + PlayerName + "' (" + PlayerPlainID + ") DESTROYED " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName());
			}
			
			if(bbpbase.BBPGetTier() == 3)
			{				
				action_data.m_MainItem.DecreaseHealth( getBaseDestroyToolDamageT3(), false );
			}
			
			//t2
			else if(bbpbase.BBPGetTier() == 2)
			{
				action_data.m_MainItem.DecreaseHealth( getBaseDestroyToolDamageT2(), false );
			}
			
			//t1
			else if(bbpbase.BBPGetTier() == 1)
			{
				action_data.m_MainItem.DecreaseHealth( getBaseDestroyToolDamageT1(), false );
			}
			
			//t1
			else if(bbpbase.BBPGetTier() == 0)
			{
				action_data.m_MainItem.DecreaseHealth( getBaseDestroyToolDamageT1(), false );
				construction.DestroyPartServer( action_data.m_Player, "frame" , AT_DESTROY_PART );
			}
			
			if (bbpbase && bbpbase.BBP_HasLock()) 
			{
				bbpbase.BBP_LockHealth();
			}
			
			if(bbpbase.CanCloseFence())
			{
				construction.DestroyPartServer( action_data.m_Player, "frame" , AT_DESTROY_PART );
			}
			
			if(!bbpbase.BBP_HasDoor())
			{			
				if (bbpbase.GetConstruction().IsPartConstructed( "t3_wall_concrete_bricks_2" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t3_wall_concrete_bricks_2" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t3_wall_concrete_bricks" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t3_wall_concrete_bricks" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "window_bars" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "window_bars" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t2_metal" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t2_metal" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t2_metal_2" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t2_metal_2" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t1_wall_logs_horizontal" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal_2" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t1_wall_logs_horizontal_2" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_planks" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t1_wall_planks" , AT_DESTROY_PART );
				}
			}
			
			if(bbpbase.BBP_HasDoor())
			{
				if (bbpbase.GetConstruction().IsPartConstructed( "t3_door" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t3_door" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t2_door" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t2_door" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "t1_door" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "t1_door" , AT_DESTROY_PART );
				}
				
				if (bbpbase.GetConstruction().IsPartConstructed( "window_bars" ))
				{
					construction.DestroyPartServer( action_data.m_Player, "window_bars" , AT_DESTROY_PART );
				}
			}
			
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
	
	int getDisableDestroyBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_DisableDestroy;
		}
		return 0;
	}
	int getBaseRaidOnlyDoorsBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_RaidOnlyDoors;
		}
		return 0;
	}
	int getBaseDestroyToolDamageT1()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_Tier1RaidToolDamage;
		}
		return 40;
	}
	int getBaseDestroyToolDamageT2()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_Tier2RaidToolDamage;
		}
		return 80;
	}
	int getBaseDestroyToolDamageT3()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_Tier3RaidToolDamage;
		}
		return 160;
	}
}