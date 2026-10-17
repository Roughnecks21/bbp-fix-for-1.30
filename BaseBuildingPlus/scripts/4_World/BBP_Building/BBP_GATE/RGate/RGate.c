class BBP_RGate extends BBP_BASE
{	
	override string GetConstructionKitType()
	{
		return "BBP_Gate_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Right Gate";
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
			SetAnimationPhase( "T3_Wall_Concrete_Bricks_Rotate", 				value );
			SetAnimationPhase( "Wall_Interact_Rotate", 							value );
			SetAnimationPhase( "T2_Metal_Rotate", 								value );
			
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
			SetAnimationPhase( "T3_Wall_Concrete_Bricks_Rotate", 				value );
			SetAnimationPhase( "Wall_Interact_Rotate", 							value );
			SetAnimationPhase( "T2_Metal_Rotate", 								value );


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
