class ActionTurnOffBBPMixer: ActionInteractBase
{	
	void ActionTurnOffBBPMixer()
	{
	}

	override string GetText()
	{
		return "#switch_off";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if (targetObject.IsInherited(BBP_Cement_Mixer))
		{
			BBP_Cement_Mixer BBPCementMixer = BBP_Cement_Mixer.Cast( targetObject );

			if ( BBPCementMixer  &&  BBPCementMixer.HasEnergyManager()  &&  BBPCementMixer.GetCompEM().CanSwitchOff()  &&  BBPCementMixer.GetCompEM().CanWork() )
			{
				return true;
			}
		}
		if (targetObject.IsInherited(BBP_Cement_Mixer_Static))
		{
			BBP_Cement_Mixer_Static BBPCementMixer_2 = BBP_Cement_Mixer_Static.Cast( targetObject );

			if ( BBPCementMixer_2  &&  BBPCementMixer_2.HasEnergyManager()  &&  BBPCementMixer_2.GetCompEM().CanSwitchOff()  &&  BBPCementMixer_2.GetCompEM().CanWork() )
			{
				return true;
			}
		}
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if ( targetObject )
		{
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			target_EAI.GetCompEM().SwitchOff();
			
			//Timer temporarily removed
			/*if (BBP_ItemSpawn.IsRunning())
			{
				BBP_ItemSpawn = 		new Timer( CALL_CATEGORY_SYSTEM );
			}*/
		}
	}
};