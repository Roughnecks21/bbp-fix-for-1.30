class BBP_Mesh_Gate extends BBP_BASE
{	
	const string SOUND_GATE_OPEN_START2					= "BBP_METAL_Open_SoundSet";
	const string SOUND_GATE_CLOSE_START2				= "BBP_METAL_Close_SoundSet";
	const string SOUND_GATE_CLOSE_END2					= "";

	override void SoundGateOpenStart()
	{
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundGate_Start, SOUND_GATE_OPEN_START2, 0.1, 0.1 );
		}
	}

	override void SoundGateCloseStart()
	{
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundGate_Start, SOUND_GATE_CLOSE_START2, 0.1, 0.1 );
		}
	}

	override void SoundGateCloseEnd()
	{
		//client or single player
		if ( !GetGame().IsDedicatedServer() )
		{
			PlaySoundSet( m_SoundGate_End, SOUND_GATE_CLOSE_END2, 0.1, 0.1 );
		}
	}	
	
	override string GetConstructionKitType()
	{
		return "BBP_Mesh_Gate_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Chain Link Gate";
	}

	override bool IsBBPGate()
	{
		return true;
	}
	
		override void UpdateVisuals()
	{
		if (GetConstruction().IsPartConstructed( "t2_metal_2" ))
		{
			CreateAreaDamage( "Wall_Barbedwire_1_Mounted" );
		}
		else
		{
			DestroyAreaDamage( "Wall_Barbedwire_1_Mounted" );
		}
		
		GetConstruction().UpdateVisuals();
	}
		
	override void CreateAreaDamage( string slot_name, float rotation_angle = 0 )
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			//destroy area damage if some already exists
			DestroyAreaDamage( "Wall_Barbedwire_1_Mounted" );
			
			//create new area damage
			AreaDamageLoopedDeferred_NoVehicle area_damage = new AreaDamageLoopedDeferred_NoVehicle( this );
			area_damage.SetDamageComponentType(AreaDamageComponentTypes.HITZONE);
			
			//Print("BBB | area_damage: " + area_damage + " | slot_name: " + slot_name);
			
			vector min_max[2];
			if ( MemoryPointExists( "wall_barbedwire_1_mounted_min" ) )
			{
				min_max[0] = GetMemoryPointPos( "wall_barbedwire_1_mounted_min" );
			}
			if ( MemoryPointExists( "wall_barbedwire_1_mounted_max" ) )
			{
				min_max[1] = GetMemoryPointPos( "wall_barbedwire_1_mounted_max" );
			}
			
			//get proper trigger extents (min<max)
			vector extents[2];
			GetConstruction().GetTriggerExtents( min_max, extents );
			
			//get box center
			vector center;
			center = GetConstruction().GetBoxCenter( min_max );
			center = ModelToWorld( center );
			
			//rotate center if needed
			vector orientation = GetOrientation();;
			CalcDamageAreaRotation( rotation_angle, center, orientation );
			
			area_damage.SetExtents( extents[0], extents[1] );
			area_damage.SetAreaPosition( center );
			area_damage.SetAreaOrientation( orientation );
			area_damage.SetLoopInterval( 0.5 );
			area_damage.SetDeferDuration( 0.2 );
			area_damage.SetHitZones( { "Torso","LeftHand","LeftLeg","LeftFoot","RightHand","RightLeg","RightFoot" } );
			area_damage.SetAmmoName( "BarbedWireHit" );
			area_damage.Spawn();
			
			m_DamageTriggers.Insert( slot_name, area_damage );
		}
	}
	
	//BarbedWire update
	override void UpdateBarbedWireAreaDamagePos(float rotation_angle = 0, bool to_delete = false )
	{
		int slot_id;
		string slot_name;
		string slot_name_mounted;
		if (GetConstruction().IsPartConstructed( "t2_metal_2" ))
		{
			slot_name_mounted = "Wall_Barbedwire_1_Mounted";
			if (to_delete)
			{
				DestroyAreaDamage( slot_name_mounted );
			}
			else
			{
				super.CreateAreaDamage( slot_name_mounted, rotation_angle );
			}
		}
	}
	
	override void OpenFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = GATE_ROTATION_ANGLE_DEG;
			SetAnimationPhase( "Wall_Interact_Rotate", 			value );
			SetAnimationPhase( "T2_Door_Rotate", 				value );
			SetAnimationPhase( "T2_Metal_Rotate", 				value );
			
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
			SetAnimationPhase( "Wall_Interact_Rotate", 			value );
			SetAnimationPhase( "T2_Door_Rotate", 				value );
			SetAnimationPhase( "T2_Metal_Rotate", 				value );


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
