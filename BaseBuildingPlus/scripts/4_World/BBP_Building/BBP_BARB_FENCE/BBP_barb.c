class BBP_Barbwire_Fence extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Barbwire_Fence_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Barbwire Fence";
	}
	
	override void UpdateVisuals()
	{
		if (GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
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
		if (GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
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
};
