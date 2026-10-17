class ActionGetBBPHP: ActionSingleUseBase
{	
	private string customText = "Get HP";
	private bool bbp_timer_check = false;


	void ActionGetBBPHP()
	{
		m_Text = "Get HP";
	}
	
	override void CreateConditionComponents() 
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override string GetText()
	{	
		return customText;
	}
	
	void SetCustomText(string text)
    {
		if(text == "Current HP: 0")
		{
			text = "Server disabled raiding on this object!";
		}
		
        customText = text;
    }

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		
		if ( item && item.IsInherited(BBP_TapeMeasure))
		{
			if (targetObject && targetObject.IsInherited(BBP_BASE))
			{
				BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
				if(bbpbase && bbpbase.BBPGetTier() != 0 && bbpbase.BBPGetTier() != 69)
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		Object targetObject = action_data.m_Target.GetObject();
		
		if(!bbp_timer_check)
		{
			if (targetObject && targetObject.IsInherited(BBP_BASE))
			{			
				BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
				string damage_zone;
				int my_health = 0;
				
				if(bbpbase && bbpbase.BBP_HasDoor())
				{
					if(bbpbase.BBPGetTier() == 3)
					{
						if (bbpbase.GetConstruction().IsPartConstructed( "t3_door" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t3_door",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
					}
					
					if(bbpbase.BBPGetTier() == 2)
					{
						if (bbpbase.GetConstruction().IsPartConstructed( "t2_door" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t2_door",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_door" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_door",damage_zone))
							{
								my_health = my_health + bbpbase.GetHealth(damage_zone,"Health");
							}
						}
					}
					
					if(bbpbase.BBPGetTier() == 1)
					{
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_door" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_door",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
					}
				}
				
				if(bbpbase && !bbpbase.BBP_HasDoor())
				{
					if(bbpbase.BBPGetTier() == 3)
					{
						if (bbpbase.GetConstruction().IsPartConstructed( "t3_wall_concrete_bricks_2" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t3_wall_concrete_bricks_2",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						if (bbpbase.GetConstruction().IsPartConstructed( "t3_wall_concrete_bricks" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t3_wall_concrete_bricks",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
					}
					if(bbpbase.BBPGetTier() == 2)
					{
						if (bbpbase.GetConstruction().IsPartConstructed( "t2_metal_2" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t2_metal_2",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						if (bbpbase.GetConstruction().IsPartConstructed( "t2_metal" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t2_metal",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_wall_logs_horizontal",damage_zone))
							{
								my_health = my_health + bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_planks" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_wall_planks",damage_zone))
							{
								my_health = my_health + bbpbase.GetHealth(damage_zone,"Health");
							}
						}
					}
					if(bbpbase.BBPGetTier() == 1)
					{
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal_2" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_wall_logs_horizontal_2",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_wall_logs_horizontal",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
						if (bbpbase.GetConstruction().IsPartConstructed( "t1_wall_planks" ))
						{
							if(DamageSystem.GetDamageZoneFromComponentName(bbpbase,"t1_wall_planks",damage_zone))
							{
								my_health = bbpbase.GetHealth(damage_zone,"Health");
							}
						}
					}
				}
				
				string convert;
				convert = "Current HP: " + my_health.ToString();
				bbpbase.SetCustomName(convert);
			}
			//Param1<string> Msgparam1 = new Param1<string>(string.Format("Current HP: %1", my_health));
			//GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam1, true, player.GetIdentity());
			//Print("My RPC got called with " + my_health);
		}
	}
	
	override void OnEndClient( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		
		if(!bbp_timer_check)
		{
			if (targetObject && targetObject.IsInherited(BBP_BASE))
			{			
				BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);
				SetCustomText(bbpbase.returnBBP_HP());
				int resetme = 2 * 1000;
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( UpdateHP_BBP, resetme, false );
				bbp_timer_check = true;
			}
		}
	}
	
	void UpdateHP_BBP()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "resetme");  // Never used RemoveByName before, but pretty sure this is correct syntax. Should also be an easy fix if its wrong.
		SetCustomText("Get HP");
		bbp_timer_check = false;
	}
};