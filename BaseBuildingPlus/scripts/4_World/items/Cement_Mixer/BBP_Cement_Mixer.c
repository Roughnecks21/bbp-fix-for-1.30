class BBP_Cement_Mixer extends ItemBase
{
	BBPConfig bbp_config = GetDayZGame().getBBPGlobals();

	static const string			START_SOUND = "powerGeneratorTurnOn_SoundSet";
	static const string			LOOP_SOUND = "powerGeneratorLoop_SoundSet";
	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStart;
	protected ItemBase			BBPConcreteBrickPile1;
	protected ItemBase			BBPConcreteBrickPile2;
	private bool				m_BBPIsSwitchedOff;
	protected int				CementMixerTime;

	// Let me know if the Callback system doesnt work as intended, I'm kinda rusty with all of this right now but I know it'll be an easy fix if this is wrong.
	
    void BBP_Cement_Mixer()
    {   	
    }
	
	bool Craft_Concrete_Bricks( PlayerBase player )
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Material_Cement");
		ItemBase bbpcement = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		if ( bbpcement && bbpcement.GetQuantity() == 2 )
		{
			return true;
		}
		return false;
	}

	override bool IsElectricAppliance()
	{
		return true;
	}
	
	override void OnInitEnergy()
	{
		GetCompEM().SwitchOff();
	}
	
	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		super.OnSwitchOn();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
	}	

	override void OnIsPlugged(EntityAI source_device)
	{
		GetCompEM().SwitchOff();
	}
	
	override void OnIsUnplugged( EntityAI last_energy_source )
	{
		GetCompEM().SwitchOff();
	}

	override void OnWorkStart()
	{
		if (bbp_config)
		{
			int BBPCementMixerTime = bbp_config.BBP_CementMixerTime;
		}
		if ( GetGame().IsClient()  ||  GetGame().IsMultiplayer() ) // not sure this is needed here, or maybe done differently but it works.
		{
			SetAnimationPhase("Spin",1);
			StartLoopSound();			
 			
			m_BBPIsSwitchedOff = false;

			CementMixerTime = BBPCementMixerTime; // time in seconds it will take to produce a cement block.
			int CementTime = CementMixerTime * 1000; // converting to milliseconds for Callback Queue

			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( FancyCementCallBack, CementTime, false );
		}
	}
	
	void FancyCementCallBack()
	{
		hidad();
	}

	override void OnWorkStop()
	{
		SetAnimationPhase("Spin",GetAnimationPhase("Spin"));

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).RemoveByName( this, "FancyCementCallBack");  // Never used RemoveByName before, but pretty sure this is correct syntax. Should also be an easy fix if its wrong.

		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			//Sound
			StopSoundSet(m_EngineLoop);
			m_BBPIsSwitchedOff = true;
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if ( item.IsKindOf ( "BBP_Cement" ) ) 
		{
			GetCompEM().SwitchOff();
		}
	}
	
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if ( GetCompEM().IsWorking() )
		{
			return false;
		}
		return true;
	}
	
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return false;
        }
        if ( GetNumberOfItems() == 0 )
        {
            return false;
        }
        return false;
    }
	
 	void StartLoopSound()
	{
		if ( GetCompEM().IsWorking() )
		{
			PlaySoundSetLoop( m_EngineLoop, LOOP_SOUND, 0, 0 );
		}
	}
		
	void removeConcrete()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Material_Cement");
		ItemBase bbpconcrete = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if (GetCompEM().IsWorking() )
		{
			bbpconcrete.SetQuantity(bbpconcrete.GetQuantity() - 2);
		}
    }
	
	void hidad()
	{
		vector bbp_bricks_position = this.GetPosition() + "-1 0 -1";  // not sure if this is where you want them, but Final Position can be adjusted here. In sneaky stashes I pass the position from the action but seems unneccisary in this case
		
		if (GetGame().IsServer() && GetCompEM().IsWorking() )  // not sure if this is needed, or may need to be changed. Check for IsWorking here too just to be safe
		{
			//BBPConcreteBrickPile1 = ItemBase.Cast( GetGame().CreateObject( "BBP_Concrete_Brick_Pile", bbp_bricks_position, false ));
			BBPConcreteBrickPile1 = ItemBase.Cast( GetGame().CreateObjectEx( "BBP_Concrete_Brick_Pile", bbp_bricks_position, ECE_PLACE_ON_SURFACE ) );
			BBPConcreteBrickPile1.SetQuantity(5);
			//BBPConcreteBrickPile2 = ItemBase.Cast( GetGame().CreateObject( "BBP_Concrete_Brick_Pile", bbp_bricks_position, false ));
			BBPConcreteBrickPile2 = ItemBase.Cast( GetGame().CreateObjectEx( "BBP_Concrete_Brick_Pile", bbp_bricks_position, ECE_PLACE_ON_SURFACE ) );
			BBPConcreteBrickPile2.SetQuantity(3);
			removeConcrete();
			GetCompEM().SwitchOff();
		}
	}
	
    override void SetActions()
    {
        super.SetActions();
		AddAction(ActionPlugIn);
		AddAction(ActionPlugTargetIntoThis);
		AddAction(ActionUnplugThisByCord);
		AddAction(ActionTurnOnBBPMixer);
    }
};
