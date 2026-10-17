class ActionTurnOnBBPMixer: ActionInteractBase
{	
	vector position;
	
	void ActionTurnOnBBPMixer()
	{
	}

	override string GetText()
	{
		return "#switch_on";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if (targetObject.IsInherited(BBP_Cement_Mixer))
		{
			BBP_Cement_Mixer BBPCementMixer = BBP_Cement_Mixer.Cast( targetObject );
			if ( BBPCementMixer  &&  BBPCementMixer.HasEnergyManager()  &&  BBPCementMixer.GetCompEM().CanSwitchOn()  &&  BBPCementMixer.GetCompEM().CanWork() )
			{
				if ( BBPCementMixer.Craft_Concrete_Bricks(player) )
				{
					return true;
				}
				return false;
			}
		}
		if (targetObject.IsInherited(BBP_Cement_Mixer_Static))
		{
			BBP_Cement_Mixer_Static BBPCementMixer_2 = BBP_Cement_Mixer_Static.Cast( targetObject );
			if ( BBPCementMixer_2  &&  BBPCementMixer_2.HasEnergyManager()  &&  BBPCementMixer_2.GetCompEM().CanSwitchOn()  &&  BBPCementMixer_2.GetCompEM().CanWork() )
			{
				if ( BBPCementMixer_2.Craft_Concrete_Bricks(player) )
				{
					return true;
				}
				return false;
			}
		}
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject.IsInherited(BBP_Cement_Mixer))
		{
			BBP_Cement_Mixer bbpmixer = BBP_Cement_Mixer.Cast( targetObject );
			bbpmixer.GetCompEM().SwitchOn();
		}
		
		if (targetObject.IsInherited(BBP_Cement_Mixer_Static))
		{
			BBP_Cement_Mixer_Static bbpmixer_2 = BBP_Cement_Mixer_Static.Cast( targetObject );
			bbpmixer_2.GetCompEM().SwitchOn();
		}		
	}
};
