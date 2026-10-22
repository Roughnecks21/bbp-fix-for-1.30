modded class ItemBase	// extends InventoryItem
{
	//Old snapping
	bool BBP_canSnap = false;
	bool BBP_canSnapFloor = false;
	//New snapping
	bool BBP_canSnapBBP = false;
	bool BBP_canSnapFloorBBP = false;
	bool BBP_canSnapPillarBBP = false;
	bool BBP_canSnap150 = false;
	bool BBP_canSnap600 = false;
	//Kit cycling
	bool BBP_canCycleSize = false;
	bool BBP_canCyclePart = false;

	bool isFlag()
	{
		return false;
	}
	bool isSmall()
	{
		return false;
	}
	bool isSlopeRoof()
	{
		return false;
	}
	
	bool isDismantle()
	{
		return false;
	}
	
	bool isBBP_Object()
	{
		return false;
	}
	
	bool isBBPAdminTool()
	{
		return false;
	}
	bool isflat()
	{
		return false;
	}
	bool isSlope()
	{
		return false;
	}
	bool isWindow()
	{
		return false;
	}
	bool isDiagonal()
	{
		return false;
	}
	bool isCorner()
	{
		return false;
	}
	bool isPillar()
	{
		return false;
	}
	bool isRoof()
	{
		return false;
	}
	bool isFloor()
	{
		return false;
	}
	bool isTriangle()
	{
		return false;
	}
	bool isRamp()
	{
		return false;
	}
	bool isFoundation()
	{
		return false;
	}
	bool isDoor()
	{
		return false;
	}
	bool isBBPDoor()
	{
		return false;
	}
	bool isStaircase()
	{
		return false;
	}
	bool height600()
	{
		return false;
	}
	bool height150()
	{
		return false;
	}
	bool canSnap()
	{
		return BBP_canSnap;
	}
	bool canSnapFloor()
	{
		return BBP_canSnapFloor;
	}
	bool canSnapBBP()
	{
		return BBP_canSnapBBP;
	}
	bool canSnapFloorBBP()
	{
		return BBP_canSnapFloorBBP;
	}
	bool canSnapPillarBBP()
	{
		return BBP_canSnapPillarBBP;
	}
	bool canSnap150()
	{
		return BBP_canSnap150;
	}
	bool canSnap600()
	{
		return BBP_canSnap600;
	}

	bool canCycleParts()
	{
		return BBP_canCyclePart;
	}

	void setCanSnap(bool a)
	{
		BBP_canSnap = a;
	}

	void setCanCycleSize(bool a)
	{
		BBP_canCycleSize = a;
	}
	void setCanCyclePart(bool a)
	{
		BBP_canCyclePart = a;
	}

	void setCanSnapFloor(bool a)
	{
		BBP_canSnapFloor = a;
	}

	void setCanSnapBBP(bool a)
	{
		BBP_canSnapBBP = a;
	}
	void setCanSnapFloorBBP(bool a)
	{
		BBP_canSnapFloorBBP = a;
	}
	void setCanSnapPillarBBP(bool a)
	{
		BBP_canSnapPillarBBP = a;
	}
	void setCanSnap150(bool a)
	{
		BBP_canSnap150 = a;
	}
	void setCanSnap600(bool a)
	{
		BBP_canSnap600 = a;
	}
	
	vector getSnappingPointWall() //Old Snapping
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		
		switch(snappingWallPointIndex)
		{
			case 0:
			pos = GetMemoryPointPos("snapping1"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos("snapping2"); //left
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos("snapping3"); //corner1
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos("snapping4"); //corner2
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			return ModelToWorld( pos );
			break;
			
			case 4:
			pos = GetMemoryPointPos("snapping5"); //corner3
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			return ModelToWorld( pos );
			break;
			
			case 5:
			pos = GetMemoryPointPos("snapping6"); //corner4
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;

			return ModelToWorld( pos );
			break;
			
			case 6:
			pos = GetMemoryPointPos("snapping7"); //top
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;
			
			case 7:
			pos = GetMemoryPointPos("snappingfloor1"); //outside
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 8:
			pos = GetMemoryPointPos("snappingfloor2"); //inside
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 9:
			pos = GetMemoryPointPos("snappingroof1"); //outside
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;
			
			case 10:
			pos = GetMemoryPointPos("snappingroof2"); //inside
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 11:
			pos = GetMemoryPointPos("snapping8");
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;
			
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snapping7");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}

	vector getSnappingPointWall_150()  //WALL SNAPPING TO WALL (1.5m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		switch(snappingWallPointIndex150)
		{
			case 0:
			pos = GetMemoryPointPos("snappingwall_150_right"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos("snappingwall_150_left"); //left
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos("snappingwall_150_corner1"); //corner1
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos("snappingwall_150_corner2"); //corner2
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			return ModelToWorld( pos );
			break;
			
			case 4:
			pos = GetMemoryPointPos("snappingwall_150_corner3"); //corner3
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			return ModelToWorld( pos );
			break;
			
			case 5:
			pos = GetMemoryPointPos("snappingwall_150_corner4"); //corner4
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;

			return ModelToWorld( pos );
			break;

			case 6:
			pos = GetMemoryPointPos("snappingwall_150_bottom"); //bottom
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 7:
			pos = GetMemoryPointPos("snappingwall_top"); //top
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 8:
			pos = GetMemoryPointPos("snappingwall_150_top1"); //top1
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 9:
			pos = GetMemoryPointPos("snappingwall_150_top2"); //top2
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 10:
			pos = GetMemoryPointPos("snappingwall_150_top3"); //top3
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 11:
			pos = GetMemoryPointPos("snappingwall_150_top4"); //top4
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingwall_top");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}

	vector getSnappingPointWall_600()  //WALL SNAPPING TO WALL (6m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		
		switch(snappingWallPointIndex600)
		{
			case 0:
			pos = GetMemoryPointPos("snappingwall_600_right"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos("snappingwall_600_left"); //left
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos("snappingwall_600_corner1"); //corner1
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos("snappingwall_600_corner2"); //corner2
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			return ModelToWorld( pos );
			break;
			
			case 4:
			pos = GetMemoryPointPos("snappingwall_600_corner3"); //corner3
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			return ModelToWorld( pos );
			break;
			
			case 5:
			pos = GetMemoryPointPos("snappingwall_600_corner4"); //corner4
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;

			return ModelToWorld( pos );
			break;

			case 7:
			pos = GetMemoryPointPos("snappingwall_top"); //top
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 8:
			pos = GetMemoryPointPos("snappingwall_600_top1"); //top1
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 9:
			pos = GetMemoryPointPos("snappingwall_600_top2"); //top2
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingwall_top");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}

	vector getSnappingPointFlat_150()  //FLOOR SNAPPING TO WALL (1.5m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;
		if(player)
		{
			if(player.GetHumanInventory())
			{
				if(player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		switch(snappingFlatPointIndex150)
		{
			case 0:
			pos = GetMemoryPointPos("snappingfloor_150_outside"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos("snappingfloor_150_inside"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 2:
			pos = GetMemoryPointPos("snappingroof_150_outside"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos("snappingroof_150_inside"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;
			
			case 4:
			pos = GetMemoryPointPos("snappingfloor_150_outside1"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 5:
			pos = GetMemoryPointPos("snappingfloor_150_outside2"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 6:
			pos = GetMemoryPointPos("snappingroof_150_outside1"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 7:
			pos = GetMemoryPointPos("snappingroof_150_outside2"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 8:
			pos = GetMemoryPointPos("snappingfloor_150_inside1"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 9:
			pos = GetMemoryPointPos("snappingfloor_150_inside2"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 10:
			pos = GetMemoryPointPos("snappingroof_150_inside1"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 11:
			pos = GetMemoryPointPos("snappingroof_150_inside2"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 12:
			pos = GetMemoryPointPos("snappingfloor_150_outside3"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 13:
			pos = GetMemoryPointPos("snappingfloor_150_outside4"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 14:
			pos = GetMemoryPointPos("snappingroof_150_outside3"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 15:
			pos = GetMemoryPointPos("snappingroof_150_outside4"); //outside
			if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					bbp_normal = "0 -1.5 0";
					pos = pos + bbp_normal;
				}
				else
				{
					bbp_normal = "0 -3 0.2";
					pos = pos + bbp_normal;
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			if (iteminhands && iteminhands.isRoof())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 16:
			pos = GetMemoryPointPos("snappingfloor_150_inside3"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 17:
			pos = GetMemoryPointPos("snappingfloor_150_inside4"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 18:
			pos = GetMemoryPointPos("snappingroof_150_inside3"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;

			case 19:
			pos = GetMemoryPointPos("snappingroof_150_inside4"); //inside
			if (iteminhands && iteminhands.isDiagonal())
			{
				if (!iteminhands.isRoof())
				{
					if (iteminhands.height150())
					{
						bbp_normal = "0 -1.5 -0.2";
						pos = pos + bbp_normal;
					}
					else
					{
						bbp_normal = "0 -3 -0.2";
						pos = pos + bbp_normal;
					}
				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			if (iteminhands && iteminhands.isRoof())
			{
				if (iteminhands.height150())
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingfloor_150_inside");
		if (iteminhands && iteminhands.isDiagonal() && !iteminhands.isRoof())
		{
			if (iteminhands.height150())
			{
				bbp_normal = "0 -1.5 -0.2";
				pos = pos + bbp_normal;
			}
			else
			{
				bbp_normal = "0 -3 -0.2";
				pos = pos + bbp_normal;
			}
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
		}
		else
		{
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		}
		return ModelToWorld( pos );
	}

	vector getSnappingPointFlat_600()  //FLOOR SNAPPING TO WALL (6m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-180 0 0"; //xd
		vector bbp_right = "180 0 0";
		vector bbp_right_2 = "90 0 0";
		vector bbp_left_2 = "-90 0 0";
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;
		if(player)
		{
			if(player.GetHumanInventory())
			{
				if(player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		switch(snappingFlatPointIndex600)
		{
			case 0:
			if(iteminhands && iteminhands.isTriangle())
			{
				pos = GetMemoryPointPos("snappingfloor_600_outside"); //triangle
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else if (iteminhands && iteminhands.isRamp())
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
	
			else
			{
				pos = GetMemoryPointPos("snappingfloor_600_outside"); //outside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			if (iteminhands && iteminhands.isTriangle())
			{
				pos = GetMemoryPointPos("snappingfloor_600_inside"); //triangle
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else if (iteminhands && iteminhands.isRamp())
			{
				pos = GetMemoryPointPos("snappingroof_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingroof_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
	
			else
			{
				pos = GetMemoryPointPos("snappingfloor_600_inside"); //triangle
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			
			return ModelToWorld( pos );
			break;
			
			case 2:
			if (iteminhands && iteminhands.isRamp())
			{
				pos = GetMemoryPointPos("snappingroof_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				pos = GetMemoryPointPos("snappingroof_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 3:
			if (iteminhands && iteminhands.isRamp())
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //outside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingroof_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else if(iteminhands && iteminhands.isTriangle())
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //triangle
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}				
			else
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //outside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
		}
		
		pos = GetMemoryPointPos("snappingroof_600_inside");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}

	vector getSnappingPointFloor_150()  //WALL SNAPPING TO FLOOR (1.5m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		switch(snappingFloorPointIndex150)
		{
			case 0:
			pos = GetMemoryPointPos("snappingwall_back"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos("snappingwall_right"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos("snappingwall_front"); //front
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos("snappingwall_left"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 4:
			pos = GetMemoryPointPos("snappingwall_150_back1"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 5:
			pos = GetMemoryPointPos("snappingwall_150_back2"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 6:
			pos = GetMemoryPointPos("snappingwall_150_right1"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 7:
			pos = GetMemoryPointPos("snappingwall_150_right2"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 8:
			pos = GetMemoryPointPos("snappingwall_150_front1"); //front
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 9:
			pos = GetMemoryPointPos("snappingwall_150_front2"); //front
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 10:
			pos = GetMemoryPointPos("snappingwall_150_left1"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 11:
			pos = GetMemoryPointPos("snappingwall_150_left2"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 12:
			pos = GetMemoryPointPos("snappingwall_150_back3"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 13:
			pos = GetMemoryPointPos("snappingwall_150_back4"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 14:
			pos = GetMemoryPointPos("snappingwall_150_right3"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 15:
			pos = GetMemoryPointPos("snappingwall_150_right4"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 16:
			pos = GetMemoryPointPos("snappingwall_150_front3"); //front
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 17:
			pos = GetMemoryPointPos("snappingwall_150_front4"); //front
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			return ModelToWorld( pos );
			break;

			case 18:
			pos = GetMemoryPointPos("snappingwall_150_left3"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 19:
			pos = GetMemoryPointPos("snappingwall_150_left4"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingwall_front");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}

	vector getSnappingPointFloor_600()  //WALL SNAPPING TO FLOOR (6m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		vector bbp_right_tri = "240 0 0";
		vector bbp_left_tri = "-240 0 0";
		switch(snappingFloorPointIndex600)
		{
			case 0:
			if (AUTO_BBP_SNAPPING_OBJECT.isTriangle())
			{
				pos = GetMemoryPointPos("snappingwall_front"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else if (AUTO_BBP_SNAPPING_OBJECT.isRamp())
			{
				pos = GetMemoryPointPos("snappingwall_back"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				pos = GetMemoryPointPos("snappingwall_back"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			if (AUTO_BBP_SNAPPING_OBJECT.isTriangle())
			{
				pos = GetMemoryPointPos("snappingwall_right"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right_tri;
			}
			else if (AUTO_BBP_SNAPPING_OBJECT.isRamp())
			{
				pos = GetMemoryPointPos("snappingwall_front"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				pos = GetMemoryPointPos("snappingwall_right"); //right
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
			}
			return ModelToWorld( pos );
			break;
			
			case 2:
			if (AUTO_BBP_SNAPPING_OBJECT.isTriangle())
			{
				pos = GetMemoryPointPos("snappingwall_front"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else if (AUTO_BBP_SNAPPING_OBJECT.isRamp())
			{
				pos = GetMemoryPointPos("snappingwall_back"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				pos = GetMemoryPointPos("snappingwall_front"); //front
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			if (AUTO_BBP_SNAPPING_OBJECT.isTriangle())
			{
				pos = GetMemoryPointPos("snappingwall_left"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left_tri;
			}
			else if (AUTO_BBP_SNAPPING_OBJECT.isRamp())
			{
				pos = GetMemoryPointPos("snappingwall_back"); //back
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				pos = GetMemoryPointPos("snappingwall_left"); //left
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
			}
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingwall_front");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}
	
	vector getSnappingPointFloorFlat_150()  //FLOOR SNAPPING TO FLOOR (1.5m)
	{
		
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;
		if (player)
		{
			if (player.GetHumanInventory())
			{
				if (player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		switch(snappingFloorFlatPointIndex150)
		{
			case 0:
			pos = GetMemoryPointPos("snappingfloor_150_back"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 1:
			pos = GetMemoryPointPos("snappingfloor_150_right"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 2:
			pos = GetMemoryPointPos("snappingfloor_150_front"); //front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			pos = GetMemoryPointPos("snappingfloor_150_left"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 4:
			pos = GetMemoryPointPos("snappingfloor_150_back1"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}
						}
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 5:
			pos = GetMemoryPointPos("snappingfloor_150_back2"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 6:
			pos = GetMemoryPointPos("snappingfloor_150_right1"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 7:
			pos = GetMemoryPointPos("snappingfloor_150_right2"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 8:
			pos = GetMemoryPointPos("snappingfloor_150_front1"); //front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 9:
			pos = GetMemoryPointPos("snappingfloor_150_front2"); //front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 10:
			pos = GetMemoryPointPos("snappingfloor_150_left1"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 11:
			pos = GetMemoryPointPos("snappingfloor_150_left2"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 12:
			pos = GetMemoryPointPos("snappingfloor_150_back3"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 13:
			pos = GetMemoryPointPos("snappingfloor_150_back4"); //back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 14:
			pos = GetMemoryPointPos("snappingfloor_150_right3"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 15:
			pos = GetMemoryPointPos("snappingfloor_150_right4"); //right
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 16:
			pos = GetMemoryPointPos("snappingfloor_150_front3"); //front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 17:
			pos = GetMemoryPointPos("snappingfloor_150_front4"); //front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 18:
			pos = GetMemoryPointPos("snappingfloor_150_left3"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;

			case 19:
			pos = GetMemoryPointPos("snappingfloor_150_left4"); //left
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
				}
				if (AUTO_BBP_SNAPPING_OBJECT.isCorner())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 -1.5 0";
								pos = pos + bbp_normal;
							}

						}
						
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							if (AUTO_BBP_SNAPPING_OBJECT.height150())
							{
								bbp_normal = "0 0 0";
								pos = pos + bbp_normal;
							}

						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
				if (!AUTO_BBP_SNAPPING_OBJECT.isCorner() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (iteminhands && iteminhands.isDiagonal())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 -1.5 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
					}
					if (iteminhands && iteminhands.isCorner())
					{
						if (iteminhands.height150())
						{
							bbp_normal = "0 0 0";
							pos = pos + bbp_normal;
						}

						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
					}
					if (iteminhands && !iteminhands.isDiagonal() && !iteminhands.isCorner())
					{
						bbp_normal = "0 0 0";
						pos = pos + bbp_normal;
						HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
					}
				}
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingfloor_150_front");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}
	
	vector getSnappingPointFloorFlat_600()  //FLOOR SNAPPING TO FLOOR (6m)
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		vector bbp_right_tri = "60 0 0";
		vector bbp_left_tri = "-60 0 0";
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;
			
		if (player)
		{
			if (player.GetHumanInventory())
			{
				if (player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		switch(snappingFloorFlatPointIndex600)
		{		
			case 0:
			if (iteminhands && iteminhands.isTriangle())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_front"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_front"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
			}
			
			if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingfloor_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			
			if (iteminhands && !iteminhands.isTriangle() && !iteminhands.isSlopeRoof() && !iteminhands.isRamp())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_front"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left + bbp_left;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_back"); //right
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
			}
			
			if(iteminhands && iteminhands.isRamp())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isRamp())
				{
					pos = GetMemoryPointPos("snappingfloor_600_back"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_back"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left + bbp_left;
				}
			}
			
			return ModelToWorld( pos );
			break;
			
			case 1:
			if (iteminhands && iteminhands.isTriangle())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right_tri;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
				}
			}
			
			if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingfloor_600_outside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			
			if (iteminhands && !iteminhands.isTriangle() && !iteminhands.isSlopeRoof() && !iteminhands.isRamp())
			{			
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right_tri;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //right
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
			}
			
			if(iteminhands && iteminhands.isRamp())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isRamp())
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
				}
			}
			return ModelToWorld( pos );
			break;
			
			
			
			case 2:
			if (iteminhands && iteminhands.isTriangle())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_front"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_back"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
			}
			
			if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingroof_600_inside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			
			if (iteminhands && !iteminhands.isTriangle() && !iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingfloor_600_front"); //right
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			break;
			
			case 3:
			if (iteminhands && iteminhands.isTriangle())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_left"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left_tri;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_left"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left;
				}
			}
			
			if (iteminhands && iteminhands.isSlopeRoof())
			{
				pos = GetMemoryPointPos("snappingroof_600_outside"); //inside
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			
			if (iteminhands && !iteminhands.isTriangle() && !iteminhands.isSlopeRoof()&& !iteminhands.isRamp())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isTriangle())
				{
					pos = GetMemoryPointPos("snappingfloor_600_left"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_left_tri;
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_left"); //right
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
			}
			
			if(iteminhands && iteminhands.isRamp())
			{
				if(AUTO_BBP_SNAPPING_OBJECT.isRamp())
				{
					pos = GetMemoryPointPos("snappingfloor_600_right"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
				}
				else
				{
					pos = GetMemoryPointPos("snappingfloor_600_left"); //triangle
					HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right;
				}
			}
			return ModelToWorld( pos );
			break;
		}
		pos = GetMemoryPointPos("snappingfloor_600_back");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}

	vector getSnappingPointPillar() //Pillar Snapping
	{
		vector pos = "0 0 0";
		vector bbp_normal = "0 0 0";
		vector bbp_left = "-90 0 0";
		vector bbp_right = "90 0 0";
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;
		if (player)
		{
			if (player.GetHumanInventory())
			{
				if (player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		switch(snappingPillarPointIndex)
		{
			case 0:
			pos = GetMemoryPointPos("snappingpillar_01"); //corner1 back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (iteminhands && iteminhands.height150() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					bbp_normal = "0 1.5 0";
					pos = pos + bbp_normal;
				}

				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			
			case 1:
			pos = GetMemoryPointPos("snappingpillar_02"); //corner2 back
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (iteminhands && iteminhands.height150() && !AUTO_BBP_SNAPPING_OBJECT.isDiagonal())
				{
					if (!AUTO_BBP_SNAPPING_OBJECT.isCorner())
					{
						bbp_normal = "0 1.5 0";
						pos = pos + bbp_normal;
					}
				}

				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				if (AUTO_BBP_SNAPPING_OBJECT.isPillar())
				{
					if (iteminhands && iteminhands.height150())
					{
						bbp_normal = "0 1.5 0";
						pos = pos + bbp_normal;
					}

				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();	
			}
			return ModelToWorld( pos );
			
			case 2:
			pos = GetMemoryPointPos("snappingpillar_03"); //corner3 front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (iteminhands && iteminhands.height150())
				{
					bbp_normal = "0 1.5 0";
					pos = pos + bbp_normal;
				}

				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				if (!AUTO_BBP_SNAPPING_OBJECT.isPillar())
				{
					if (iteminhands && iteminhands.height150())
					{
						bbp_normal = "0 1.5 0";
						pos = pos + bbp_normal;
					}

				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			
			case 3:
			pos = GetMemoryPointPos("snappingpillar_04"); //corner4 front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				if (iteminhands && iteminhands.height150())
				{
					bbp_normal = "0 1.5 0";
					pos = pos + bbp_normal;
				}

				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				if (!AUTO_BBP_SNAPPING_OBJECT.isPillar())
				{
					if (iteminhands && iteminhands.height150())
					{
						bbp_normal = "0 1.5 0";
						pos = pos + bbp_normal;
					}

				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			
			case 4:
			pos = GetMemoryPointPos("snappingpillar_05"); //corner1 top back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			
			case 5:
			pos = GetMemoryPointPos("snappingpillar_06"); //corner2 top back
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
			
			case 6:
			pos = GetMemoryPointPos("snappingpillar_07"); //corner3 top front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				if (!AUTO_BBP_SNAPPING_OBJECT.isPillar())
				{
					if (iteminhands && iteminhands.height150())
					{
						bbp_normal = "0 1.5 0";
						pos = pos + bbp_normal;
					}

				}
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );

			case 7:
			pos = GetMemoryPointPos("snappingpillar_08"); //corner4 top front
			if (AUTO_BBP_SNAPPING_OBJECT.isflat())
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation() + bbp_right + bbp_right;
			}
			else
			{
				HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			}
			return ModelToWorld( pos );
		}
		pos = GetMemoryPointPos("snappingpillar_01");
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld( pos );
	}
	
	vector getSnappingPointFoundation_150()  // Use the standard 1.5m floor grid on foundations.
	{
		return getSnappingPointFloorFlat_150();
	}

	vector getSnappingPointFoundation_600()  // 6m foundations and floors: snap beside an edge.
	{
		ItemBase iteminhands;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player && player.GetHumanInventory())
		{
			iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
		}

		// Foundations and large floor kits extend from the foundation edges; other kits remain centered.
		if (!iteminhands || (!iteminhands.IsInherited(BBP_Foundation_Kit) && !iteminhands.IsInherited(BBP_Floor_Kit)))
		{
			HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
			vector center = (GetMemoryPointPos("snappingfloor_600_front") + GetMemoryPointPos("snappingfloor_600_back")) * 0.5;
			return ModelToWorld(center);
		}

		vector pos;
		switch (snappingFloorFlatPointIndex600)
		{
			case 0: pos = GetMemoryPointPos("snappingfloor_600_back"); break;
			case 1: pos = GetMemoryPointPos("snappingfloor_600_right"); break;
			case 2: pos = GetMemoryPointPos("snappingfloor_600_front"); break;
			case 3: pos = GetMemoryPointPos("snappingfloor_600_left"); break;
			default: pos = GetMemoryPointPos("snappingfloor_600_back"); break;
		}
		HologramOrientation = AUTO_BBP_SNAPPING_OBJECT.GetOrientation();
		return ModelToWorld(pos);
	}
}
