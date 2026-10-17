class BBP_DGate extends BBP_BASE
{	
	string SOUND_GATE_OPEN_START2;
	string SOUND_GATE_CLOSE_START2;
	string SOUND_GATE_CLOSE_END2;
	
	override void SoundGateOpenStart()
	{
		if(GetConstruction().IsPartConstructed("t3_wall_concrete_bricks") || GetConstruction().IsPartConstructed("t2_metal"))
		{
			SOUND_GATE_OPEN_START2					= "BBP_METAL_GATE_Open_SoundSet";
		}
		else
		{
			SOUND_GATE_OPEN_START2					= "DoorWoodTowerOpen_SoundSet";
		}
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundGate_Start, SOUND_GATE_OPEN_START2, 0.1, 0.1 );
		}
	}

	override void SoundGateCloseStart()
	{
		if(GetConstruction().IsPartConstructed("t3_wall_concrete_bricks") || GetConstruction().IsPartConstructed("t2_metal"))
		{
			SOUND_GATE_CLOSE_START2					= "BBP_METAL_GATE_Close_SoundSet";
		}
		else
		{
			SOUND_GATE_CLOSE_START2					= "DoorWoodTowerClose_start_SoundSet";
		}
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundGate_Start, SOUND_GATE_CLOSE_START2, 0.1, 0.1 );
		}
	}

	override void SoundGateCloseEnd()
	{
		if(GetConstruction().IsPartConstructed("t3_wall_concrete_bricks") || GetConstruction().IsPartConstructed("t2_metal"))
		{
			SOUND_GATE_CLOSE_END2					= "";
		}
		else
		{
			SOUND_GATE_CLOSE_END2					= "DoorWoodTowerClose_end_SoundSet";
		}
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundGate_End, SOUND_GATE_CLOSE_END2, 0.1, 0.1 );
		}
	}	
	override string GetConstructionKitType()
	{
		return "BBP_SGate_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Double Garage Door";
	}

	override bool IsBBPGate()
	{
		return true;
	}
	
	override void OpenFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = GATE_ROTATION_ANGLE_DEG;
			SetAnimationPhase( "T1_Frame_Rotate", 								value );
			SetAnimationPhase( "T1_Wall_Logs_Horizontal_Rotate", 				value );
			SetAnimationPhase( "T1_Wall_Logs_Horizontal_2_Rotate", 				value );
			SetAnimationPhase( "T3_Wall_Concrete_Bricks_Rotate", 				value );
			SetAnimationPhase( "T3_Wall_Concrete_Bricks_2_Rotate", 				value );
			SetAnimationPhase( "Wall_Interact_Rotate", 							value );
			SetAnimationPhase( "T2_Metal_Rotate", 								value );
			SetAnimationPhase( "T2_Metal_2_Rotate", 							value );
			
			SetOpenedState( true );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		super.OpenFence();
	}
	
	override void CloseFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{		
			float value = 0;
			SetAnimationPhase( "T1_Frame_Rotate", 								value );
			SetAnimationPhase( "T1_Wall_Logs_Horizontal_Rotate", 				value );
			SetAnimationPhase( "T1_Wall_Logs_Horizontal_2_Rotate", 				value );
			SetAnimationPhase( "T3_Wall_Concrete_Bricks_Rotate", 				value );
			SetAnimationPhase( "T3_Wall_Concrete_Bricks_2_Rotate", 				value );
			SetAnimationPhase( "Wall_Interact_Rotate", 							value );
			SetAnimationPhase( "T2_Metal_Rotate", 								value );
			SetAnimationPhase( "T2_Metal_2_Rotate", 							value );


			SetOpenedState( false );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		super.CloseFence();
	}

	override void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Wall_Interact_Rotate" ) == 0 )			//animation closed
		{
			//play sound
			if ( this ) SoundGateCloseEnd();
			
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDialCombinationLockOnTarget);
		AddAction(ActionNextCombinationLockDialOnTarget);
		AddAction(ActionOpenFence);
		AddAction(ActionCloseFence);
	}
}
