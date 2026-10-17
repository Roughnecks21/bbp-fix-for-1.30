modded class Hologram
{

	BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
	
	vector freeze_pos = "0 0 0";

	override protected vector GetProjectionEntityPosition ( PlayerBase player )
	{
		if (!player || !m_Player)
		{
			return vector.Zero;
		}
		if (!m_Player.GetHumanInventory())
		{
			return super.GetProjectionEntityPosition(player);
		}
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (!item_in_hands)
		{
			return super.GetProjectionEntityPosition(player);
		}
		BBP_BASE otherSnappingObject;
		otherSnappingObject = AUTO_BBP_SNAPPING_OBJECT;
		
		if (item_in_hands)
		{
			if (item_in_hands.isBBP_Object())
			{
				if(BBP_Rotate && !BBP_Freeze)
				{
					freeze_pos = m_Projection.GetPosition();
				}
				
				else if(BBP_Rotate && BBP_Freeze)
				{
					vector offset = freeze_pos;
					offset[0] = offset[0] + holoOffset;
					offset[1] = offset[1] + holoOffset_1;
					offset[2] = offset[2] + holoOffset_2;
					return offset;
				}
			}
		}
		
		if ( item_in_hands.canSnap() || item_in_hands.canSnapFloor() )
		{
			if ( snappingEnabled && otherSnappingObject != NULL )
			{
				if ( !align_to_terrain )
				{
					m_AlignToTerrain = false;
				}
				SetIsFloating( false );
				vector holoPosition_old = otherSnappingObject.getSnappingPointWall();
				holoPosition_old[0] = holoPosition_old[0] + holoOffset;
				holoPosition_old[1] = holoPosition_old[1] + holoOffset_1;
				holoPosition_old[2] = holoPosition_old[2] + holoOffset_2;
				return holoPosition_old;
			}
		}
		
		if ( item_in_hands.canSnapBBP() )
		{	
			if ( snappingEnabled && otherSnappingObject != NULL )
			{
				if ( item_in_hands.canSnap150() )
				{
					if ( !otherSnappingObject.isflat() )
					{
						vector holoPosition1 = otherSnappingObject.getSnappingPointWall_150();
						holoPosition1[0] = holoPosition1[0] + holoOffset;
						holoPosition1[1] = holoPosition1[1] + holoOffset_1;
						holoPosition1[2] = holoPosition1[2] + holoOffset_2;
						return holoPosition1;
					}
					if ( otherSnappingObject.isflat() )
					{
						vector holoPosition2 = otherSnappingObject.getSnappingPointFloor_150();
						holoPosition2[0] = holoPosition2[0] + holoOffset;
						holoPosition2[1] = holoPosition2[1] + holoOffset_1;
						holoPosition2[2] = holoPosition2[2] + holoOffset_2;
						return holoPosition2;
					}
				}
				if ( item_in_hands.canSnap600() )
				{
					if ( !otherSnappingObject.isflat() )
					{
						vector holoPosition5 = otherSnappingObject.getSnappingPointWall_600();
						holoPosition5[0] = holoPosition5[0] + holoOffset;
						holoPosition5[1] = holoPosition5[1] + holoOffset_1;
						holoPosition5[2] = holoPosition5[2] + holoOffset_2;
						return holoPosition5;
					}
					if ( otherSnappingObject.isflat() )
					{
						vector holoPosition6 = otherSnappingObject.getSnappingPointFloor_600();
						holoPosition6[0] = holoPosition6[0] + holoOffset;
						holoPosition6[1] = holoPosition6[1] + holoOffset_1;
						holoPosition6[2] = holoPosition6[2] + holoOffset_2;
						return holoPosition6;
					}
				}
				SetIsFloating( false );
				m_AlignToTerrain = false;
			}
		}

		if ( item_in_hands.canSnapFloorBBP() )
		{	
			if ( snappingEnabled && otherSnappingObject != NULL )
			{
				if ( item_in_hands.canSnap150() )
				{
					if ( !otherSnappingObject.isflat() )
					{
						vector holoPositionf1 = otherSnappingObject.getSnappingPointFlat_150();
						holoPositionf1[0] = holoPositionf1[0] + holoOffset;
						holoPositionf1[1] = holoPositionf1[1] + holoOffset_1;
						holoPositionf1[2] = holoPositionf1[2] + holoOffset_2;
						return holoPositionf1;
					}
					if ( otherSnappingObject.isflat() )
					{
						if (otherSnappingObject.isFoundation() && item_in_hands.isFloor())
						{
							vector holoPositionf2 = otherSnappingObject.getSnappingPointFoundation_150();
							holoPositionf2[0] = holoPositionf2[0] + holoOffset;
							holoPositionf2[1] = holoPositionf2[1] + holoOffset_1;
							holoPositionf2[2] = holoPositionf2[2] + holoOffset_2;
							return holoPositionf2;
						}
						else
						{
							vector holoPositionf3 = otherSnappingObject.getSnappingPointFloorFlat_150();
							holoPositionf3[0] = holoPositionf3[0] + holoOffset;
							holoPositionf3[1] = holoPositionf3[1] + holoOffset_1;
							holoPositionf3[2] = holoPositionf3[2] + holoOffset_2;
							return holoPositionf3;
						}
					}
				}
				if ( item_in_hands.canSnap600() )
				{
					if ( !otherSnappingObject.isflat() )
					{
						vector holoPositionf7 = otherSnappingObject.getSnappingPointFlat_600();
						holoPositionf7[0] = holoPositionf7[0] + holoOffset;
						holoPositionf7[1] = holoPositionf7[1] + holoOffset_1;
						holoPositionf7[2] = holoPositionf7[2] + holoOffset_2;
						return holoPositionf7;
					}
					if ( otherSnappingObject.isflat() )
					{
						if (otherSnappingObject.isFoundation() && item_in_hands.isFloor())
						{
							vector holoPositionf8 = otherSnappingObject.getSnappingPointFoundation_600();
							holoPositionf8[0] = holoPositionf8[0] + holoOffset;
							holoPositionf8[1] = holoPositionf8[1] + holoOffset_1;
							holoPositionf8[2] = holoPositionf8[2] + holoOffset_2;
							return holoPositionf8;
						}
						else
						{
							vector holoPositionf9 = otherSnappingObject.getSnappingPointFloorFlat_600();
							holoPositionf9[0] = holoPositionf9[0] + holoOffset;
							holoPositionf9[1] = holoPositionf9[1] + holoOffset_1;
							holoPositionf9[2] = holoPositionf9[2] + holoOffset_2;
							return holoPositionf9;
						}
					}
				}
				SetIsFloating( false );
				m_AlignToTerrain = false;
			}
		}

		if ( item_in_hands.canSnapPillarBBP() )
		{	
			if ( snappingEnabled && otherSnappingObject != NULL )
			{
				SetIsFloating( false );
				vector holoPositionp1 = otherSnappingObject.getSnappingPointPillar();
				holoPositionp1[0] = holoPositionp1[0] + holoOffset;
				holoPositionp1[1] = holoPositionp1[1] + holoOffset_1;
				holoPositionp1[2] = holoPositionp1[2] + holoOffset_2;
				return holoPositionp1;
			}
		}

		//return super.GetProjectionEntityPosition(player);
		vector holoPosition = super.GetProjectionEntityPosition( player );
		if ( item_in_hands.IsInherited(BBP_KIT_BASE) )
		{
			if ( !align_to_terrain )
			{
				m_AlignToTerrain = false;
			}
			holoPosition[0] = holoPosition[0] + holoOffset;
			holoPosition[1] = holoPosition[1] + holoOffset_1;
			holoPosition[2] = holoPosition[2] + holoOffset_2;
		}
		return holoPosition;
	}
	
    override string ProjectionBasedOnParent()
    {
        BBP_KIT_BASE item_in_hands = BBP_KIT_BASE.Cast(m_Player.GetHumanInventory().GetEntityInHands());
      
        if ( item_in_hands )
            return item_in_hands.NeededHologram();
		
        return super.ProjectionBasedOnParent();
    }
	
    override void EvaluateCollision(ItemBase action_item = null)
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		BBP_BASE otherSnappingObject;
		otherSnappingObject = BBP_SNAPPING_OBJECT;
		
		if (item_in_hands && item_in_hands.IsInherited(BBP_KIT_BASE))
        {
			if(getBaseBuildAnywhereBBP() == 1)
			{
				SetIsColliding(false);
				return;
			}
		}

		if (item_in_hands && item_in_hands.IsInherited(BBP_Step_Ladder_Kit))
        {
			if (STOP_STACKING_STAIRS(action_item))
            {
                SetIsColliding(true);
                return;
            }
		}
		
		if (IsCollidingBBPFloor(action_item) || getTentBuildAnywhereBBP() == 1)
		{
			if (item_in_hands && (item_in_hands.IsInherited(TentBase) || item_in_hands.IsInherited(ShelterKit))) //Tent & Shelter
			{
				if (HeightPlacementCheck() && !IsCollidingAngle() && !IsUnderwater() && !IsCollidingTentBBP(action_item))
				{
					SetIsColliding(false);
					return;
				}
			}
		}
		if (getVanillaBuildAnywhereBBP() == 1)
		{
			if (item_in_hands && (item_in_hands.IsInherited(FenceKit) || item_in_hands.IsInherited(WatchtowerKit))) //Fence & Watchtower
			{
				if (HeightPlacementCheck() && !IsCollidingTentBBP(action_item))
				{
					SetIsColliding(false);
					return;
				}
			}
		}
		if (getFlagBuildAnywhereBBP() == 1)
		{
			if (item_in_hands && (item_in_hands.IsInherited(TerritoryFlagKit))) //Flag
			{
				if (!IsCollidingAngle() && !IsUnderwater() && !IsCollidingTentBBP(action_item))
				{
					SetIsColliding(false);
					return;
				}
			}
		}
		if (item_in_hands && item_in_hands.IsInherited(BBP_KIT_BASE))
        {
			if (otherSnappingObject != NULL || item_in_hands.IsBeingPlaced())
			{
				if (!item_in_hands.isFloor() && !item_in_hands.isRoof() && !item_in_hands.isRamp() && !item_in_hands.isStaircase())
				{
					if (!IsCollidingBBPBBox(action_item))
					{
						SetIsColliding(false);
						return;
					}
					else if (item_in_hands.IsInherited(BBP_Pillar_Kit))
					{
						SetIsColliding(false);
						return;
					}
					else if (getBaseBuildAnywhereBBP() == 1)
					{
						SetIsColliding(false);
						return;
					}
					else 
					{
						SetIsColliding(true);
						return;
					}
				}
				if (item_in_hands.isFloor() || item_in_hands.isRoof() || item_in_hands.isRamp() || item_in_hands.isStaircase())
				{
					if (item_in_hands.isFloor())
					{
						if (!IsCollidingBBPFloorBBox(action_item))
						{
							SetIsColliding(false);
							return;
						}
						else if (getBaseBuildAnywhereBBP() == 1)
						{
							SetIsColliding(false);
							return;
						}
						else
						{
							SetIsColliding(true);
							return;
						}
					}
					if (item_in_hands.isRoof() || item_in_hands.isRamp())
					{
						if (!IsCollidingBBPRoofBBox(action_item))
						{
							SetIsColliding(false);
							return;
						}
						else if (getBaseBuildAnywhereBBP() == 1)
						{
							SetIsColliding(false);
							return;
						}
						else
						{
							SetIsColliding(true);
							return;
						}
					}
					if (item_in_hands.isStaircase())
					{
						if (!IsCollidingBBPStairsBBox(action_item))
						{
							SetIsColliding(false);
							return;
						}
						else if (getBaseBuildAnywhereBBP() == 1)
						{
							SetIsColliding(false);
							return;
						}
						else
						{
							SetIsColliding(true);
							return;
						}
					}
				}
			}
			if (otherSnappingObject == NULL && !item_in_hands.IsBeingPlaced())
			{
				if (item_in_hands.isStaircase() || item_in_hands.isRamp() || item_in_hands.isRoof())
				{
					SetIsColliding(true);
					return;
				}
				if (item_in_hands.IsInherited(BBP_Foundation_Kit))
				{
					if (!IsCollidingBBPFloorBBox(action_item))
					{
						SetIsColliding(false);
						return;
					}
				}
				// Place BBP objects anywhere unless colliding with another BBP object
				else if (getBaseBuildAnywhereBBP() == 1)
				{
					if (item_in_hands && item_in_hands.IsInherited(BBP_KIT_BASE))
					{
						SetIsColliding(false);
						return;
					}
				}
			}
        }
		if (item_in_hands && (item_in_hands.IsInherited(Inventory_Base) || item_in_hands.IsInherited(ItemBase)))
        {
            if (IsCollidingBBPFloor(action_item))
            {
                SetIsColliding(false);
                return;
            }
        }
        super.EvaluateCollision(action_item);
    }

/*	override void EvaluateCollision(ItemBase action_item = null)
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		BBP_BASE otherSnappingObject;
		otherSnappingObject = BBP_SNAPPING_OBJECT;
		
		if (item_in_hands && item_in_hands.IsInherited(BBP_Step_Ladder_Kit))
        {
			if (STOP_STACKING_STAIRS(action_item))
            {
                SetIsColliding(true);
                return;
            }
		}
		
		if (item_in_hands && item_in_hands.IsInherited(BBP_KIT_BASE))
        {
			SetIsColliding(false);
			return;
		}
		

		if (item_in_hands && (item_in_hands.IsInherited(Inventory_Base) || item_in_hands.IsInherited(ItemBase)))
        {
            if (IsCollidingBBPBase(action_item))
            {
                SetIsColliding(false);
                return;
            }
        }
        super.EvaluateCollision(action_item);
    } */

	bool IsCollidingBBPBase(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		
		bool isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_BASE));		
		return isTrue;
	}
	
	bool STOP_STACKING_STAIRS(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		
		bool isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_Step_Ladder));		
		return isTrue;
	}

	bool IsCollidingBBPFloor(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		
		bool isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_Bfloor) || collided_objects[0].IsInherited(BBP_Sfloor) || collided_objects[0].IsInherited(BBP_Bfoundation) || collided_objects[0].IsInherited(BBP_Broof) || collided_objects[0].IsInherited(BBP_Sroof));		
		return isTrue;
	}

	bool IsCollidingTentBBP(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		
		bool isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(TentBase));		
		return isTrue;
	}

	bool IsCollidingBBPBBox(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		//vector absolute_ofset = "0 0.2 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector absolute_ofset = "0 0.3 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		if (action_item)
		{
			excluded_objects.Insert( action_item );
		}
		//add is construction check
		// Base building objects behave in a way that causes this test to generate false positives
		bool isTrue;
		if (getBaseBuildAnywhereBBP() == 0)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (!collided_objects[0].IsInherited(BBP_Bstair) && !collided_objects[0].IsInherited(BBP_Sstair) && !collided_objects[0].IsInherited(BBP_Slope_Roof) && !collided_objects[0].IsInherited(BBP_Bramp));
		}
		if (getBaseBuildAnywhereBBP() == 1)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_Bwall) || collided_objects[0].IsInherited(BBP_Swall) || collided_objects[0].IsInherited(BBP_Half_Bwall) || collided_objects[0].IsInherited(BBP_Half_Swall) || collided_objects[0].IsInherited(BBP_BDoor) || collided_objects[0].IsInherited(BBP_SDoor) || collided_objects[0].IsInherited(BBP_LGate) || collided_objects[0].IsInherited(BBP_RGate) || collided_objects[0].IsInherited(BBP_BWindow) || collided_objects[0].IsInherited(BBP_SWindow));
		}
		return isTrue;
	}
	
	bool IsCollidingBBPFloorBBox(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		if (action_item)
		{
			excluded_objects.Insert( action_item );
		}
		//add is construction check
		// Base building objects behave in a way that causes this test to generate false positives
		bool isTrue;
		if (getBaseBuildAnywhereBBP() == 0)
		{
			//isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (!collided_objects[0].IsInherited(BBP_Wall) && !collided_objects[0].IsInherited(BBP_Low_Wall) && !collided_objects[0].IsInherited(BBP_Door) && !collided_objects[0].IsInherited(BBP_Gate) && !collided_objects[0].IsInherited(BBP_Window) && !collided_objects[0].IsInherited(BBP_Window_Small) && !collided_objects[0].IsInherited(BBP_Bpillar) && !collided_objects[0].IsInherited(BBP_Spillar));
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects )/* && (collided_objects[0].IsInherited(BBP_Floor) || collided_objects[0].IsInherited(BBP_Ceiling) || collided_objects[0].IsInherited(BBP_Foundation))*/;
		}
		if (getBaseBuildAnywhereBBP() == 1)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_Bfloor) || collided_objects[0].IsInherited(BBP_Sfloor) || collided_objects[0].IsInherited(BBP_Broof) || collided_objects[0].IsInherited(BBP_Sroof) || collided_objects[0].IsInherited(BBP_Bfoundation));
		}
		return isTrue;
	}

	bool IsCollidingBBPRoofBBox(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.2 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		if (action_item)
		{
			excluded_objects.Insert( action_item );
		}
		//add is construction check
		// Base building objects behave in a way that causes this test to generate false positives
		bool isTrue;
		if (getBaseBuildAnywhereBBP() == 0)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (!collided_objects[0].IsInherited(BBP_Bwall) || !collided_objects[0].IsInherited(BBP_Swall) || !collided_objects[0].IsInherited(BBP_Half_Bwall) || !collided_objects[0].IsInherited(BBP_Half_Swall) || !collided_objects[0].IsInherited(BBP_BDoor) || !collided_objects[0].IsInherited(BBP_SDoor) || !collided_objects[0].IsInherited(BBP_LGate) || !collided_objects[0].IsInherited(BBP_RGate) || !collided_objects[0].IsInherited(BBP_BWindow) || !collided_objects[0].IsInherited(BBP_SWindow) && !collided_objects[0].IsInherited(BBP_Bpillar) && !collided_objects[0].IsInherited(BBP_Spillar));		
		}
		if (getBaseBuildAnywhereBBP() == 1)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_Slope_Roof) || collided_objects[0].IsInherited(BBP_Sstair) || collided_objects[0].IsInherited(BBP_Bramp));
		}
		return isTrue;
	}

	bool IsCollidingBBPStairsBBox(ItemBase action_item = null)
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.2 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		GetProjectionCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );
		excluded_objects.Insert( m_Player );
		if (action_item)
		{
			excluded_objects.Insert( action_item );
		}
		//add is construction check
		// Base building objects behave in a way that causes this test to generate false positives
		bool isTrue;
		if (getBaseBuildAnywhereBBP() == 0)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (!collided_objects[0].IsInherited(BBP_Bwall) || !collided_objects[0].IsInherited(BBP_Swall) || !collided_objects[0].IsInherited(BBP_Half_Bwall) || !collided_objects[0].IsInherited(BBP_Half_Swall) || !collided_objects[0].IsInherited(BBP_BDoor) || !collided_objects[0].IsInherited(BBP_SDoor) || !collided_objects[0].IsInherited(BBP_LGate) || !collided_objects[0].IsInherited(BBP_RGate) || !collided_objects[0].IsInherited(BBP_BWindow) || !collided_objects[0].IsInherited(BBP_SWindow) && !collided_objects[0].IsInherited(BBP_Bpillar) && !collided_objects[0].IsInherited(BBP_Spillar));
		}
		if (getBaseBuildAnywhereBBP() == 1)
		{
			isTrue = GetGame().IsBoxCollidingGeometry( center, orientation, edge_length, ObjIntersectView, ObjIntersectGeom, excluded_objects, collided_objects ) && (collided_objects[0].IsInherited(BBP_Bstair) || collided_objects[0].IsInherited(BBP_Sstair));
		}
		return isTrue;
	}

	int getBBP_AdvancedRotation()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_AdvancedRotation;
		}
		else
		{
			return 1;
		}
	}
	
	int getBaseBuildAnywhereBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_BaseBuildAnywhere;
		}
		else
		{
			return 1;
		}
	}

	int getFlagBuildAnywhereBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_FlagBuildAnywhere;
		}
		else
		{
			return 0;
		}
	}

	int getVanillaBuildAnywhereBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_VanillaBuildAnywhere;
		}
		else
		{
			return 0;
		}
	}

	int getTentBuildAnywhereBBP()
	{
		BBPConfig BBP_config = GetDayZGame().getBBPGlobals();
		if (BBP_config)
		{
			return BBP_config.BBP_TentBuildAnywhere;
		}
		else
		{
			return 0;
		}
	}

	override void SetProjectionOrientation( vector orientation ) 
	{
		
		if(reset_rot_)
		{
			vector BBP_reset = "0 0 0";
			m_Rotation = BBP_reset;
			reset_rots();
		}
		
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		
		if (item_in_hands.IsInherited(BBP_KIT_BASE) && (snappingEnabled) || item_in_hands.IsInherited(BBP_KIT_BASE) && BBP_Rotate)
		{
			if(!BBP_Rotate && AUTO_BBP_SNAPPING_OBJECT != NULL)
			{
				m_Rotation = HologramOrientation;
			}
			
			m_Projection.SetOrientation( m_Rotation );
		} 
		
		else
		{
			super.SetProjectionOrientation(orientation);
		}
	}
	
	void reset_rots()
	{
		reset_rot_ = false;
		//auto_snapper = false;
		roll_rot_ = true;
		pitch_rot_ = false;
		yaw_rot_ = false;
		holoOffset = 0;
		holoOffset_1 = 0;
        holoOffset_2 = 0;
		//height_rot_ = false;
	}
	
	#ifdef SIMPLEBASE
	override vector GetProjectionRotation()
	{
		return super.GetProjectionRotation();
	}

	override void AddProjectionRotation( float addition )
	{
		super.AddProjectionRotation(addition)
	}
	override void SubtractProjectionRotation( float subtraction )
	{
		super.SubtractProjectionRotation(subtraction)
	}

	#else
	override vector GetProjectionRotation()
	{
		return m_Rotation;
	}

	override void AddProjectionRotation( float addition )
	{
		//vector height_axis = m_Projection.GetPosition();
		//vector height_add = "0 0.1 0";
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (item_in_hands.IsInherited(BBP_KIT_BASE))
		{
			if ( roll_rot_ )
			{
				m_Rotation[0] = m_Rotation[0] + (addition / 6 ) ;
			}

			/*if ( height_rot_ )
			{
				SetIsFloating( false );
				m_AlignToTerrain = false;
				m_Projection.SetPosition( height_axis + height_add );
			}*/
			
			if (getBBP_AdvancedRotation())
			{
				if ( pitch_rot_ )
				{
					m_Rotation[1] = m_Rotation[1] + (addition / 6 );
				}
				
				if ( yaw_rot_ )
				{
					m_Rotation[2] = m_Rotation[2] + (addition / 6 );
				} 
			}
		}

		else
		{
			m_Rotation[0] = m_Rotation[0] + addition;
		}
		
	}
	
	override void SubtractProjectionRotation( float subtraction )
	{		
		//vector height_axis = m_Projection.GetPosition();
		//vector height_sub = "0 -0.1 0";
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (item_in_hands.IsInherited(BBP_KIT_BASE))
		{
			if ( roll_rot_ )
			{
				m_Rotation[0] = m_Rotation[0] - (subtraction / 6 );
			}

			/*if ( height_rot_ )
			{
				SetIsFloating( false );
				m_AlignToTerrain = false;
				m_Projection.SetPosition( height_axis + height_sub );
			}*/
			
			if (getBBP_AdvancedRotation())
			{
				if ( pitch_rot_ )
				{
					m_Rotation[1] = m_Rotation[1] - (subtraction / 6 );
				}
				
				if ( yaw_rot_ )
				{			
					m_Rotation[2] = m_Rotation[2] - (subtraction / 6);
				} 
			}
		}

		else
		{
			m_Rotation[0] = m_Rotation[0] - subtraction;
		}
	}
	#endif

	override bool IsFloating() 
	{
		if (!super.IsFloating())
			return false;

		bbp_config = GetDayZGame().getBBPGlobals();
		bool obfv_floatingPlacement = false;
		if (bbp_config) obfv_floatingPlacement = bbp_config.BBP_FloatingPlacement;
		if (!m_Player || !m_Player.GetHumanInventory()) return true;
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		BBP_BASE otherSnappingObject;
		otherSnappingObject = AUTO_BBP_SNAPPING_OBJECT;
		if (item_in_hands && item_in_hands.IsInherited(BBP_KIT_BASE) && sanppinghologram)
		{
			if (obfv_floatingPlacement)
			{
				return false;
			}
			
			if (item_in_hands.IsInherited(BBP_Foundation_Kit) || item_in_hands.IsInherited(BBP_Triangle_Foundation_Kit))
			{
				return false;
			}

			if (otherSnappingObject != NULL)
			{
				return false;
			}
			
			return m_IsFloating;
		} 
		else 
		{
			return m_IsFloating;
		}
	}
	
	ItemBase BBPFloorCollision()
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );

		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if( obj_collided.IsInherited(BBP_BASE) )
				{
					BBP_BASE bbpfloor = BBP_BASE.Cast(obj_collided);
					if ( bbpfloor.isflat() )
					{
						return bbpfloor;
					}
				}
			}
		}
		return null;
	}
	
	ItemBase BBPWallCollision()
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		array<Object> excluded_objects = new array<Object>;
		array<Object> collided_objects = new array<Object>;
		
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );

		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{	
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if( obj_collided.IsInherited(BBP_BASE) )
				{
					BBP_BASE bbpwall = BBP_BASE.Cast(obj_collided);
					if ( !bbpwall.isflat() )
					{
						return bbpwall;
					}
				}
			}
		}
		return null;
	}
	
	override vector AlignProjectionOnTerrain( float timeslice )
	{
		vector y_p_r;
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		BBP_BASE otherSnappingObject;
		otherSnappingObject = AUTO_BBP_SNAPPING_OBJECT;
		if (item_in_hands.IsInherited(BBP_Foundation_Kit) && (sanppinghologram))
		{
			y_p_r = GetDefaultOrientation() + GetProjectionRotation();
			if ( y_p_r[0] > 180 )
			{
				y_p_r[0] = y_p_r[0] - 360;
			}
			if ( y_p_r[0] < -180 )
			{
				y_p_r[0] = y_p_r[0] + 360;
			}
			return SmoothProjectionMovement( y_p_r, timeslice );
		}
		if (otherSnappingObject != NULL)
		{
			y_p_r = GetDefaultOrientation() + GetProjectionRotation();
			if ( y_p_r[0] > 180 )
			{
				y_p_r[0] = y_p_r[0] - 360;
			}
			if ( y_p_r[0] < -180 )
			{
				y_p_r[0] = y_p_r[0] + 360;
			}
			return SmoothProjectionMovement( y_p_r, timeslice );
		}
		else
		{
			return super.AlignProjectionOnTerrain(timeslice);
		}
	}
}
