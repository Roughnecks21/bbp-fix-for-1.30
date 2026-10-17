// SNAPPING
static int snappingWallPointIndex = 0;
static int snappingWallPointIndex150 = 0;
static int snappingFlatPointIndex150 = 0;
static int snappingWallPointIndex600 = 0;
static int snappingFlatPointIndex600 = 0;
static int snappingFloorPointIndex150 = 0;
static int snappingFloorFlatPointIndex150 = 0;
static int snappingFloorPointIndex600 = 0;
static int snappingFloorFlatPointIndex600 = 0;
static int snappingPillarPointIndex = 0;
static int snappingFoundationPointIndex150 = 0;
static int snappingFoundationPointIndex600 = 0;

static bool snappingEnabled  = false;
static bool snappingEnabled_By_Looking  = false;
static bool sanppinghologram = true;
static bool changeHoloIndex = true;
//static bool auto_snapper = false;
static bool roll_rot_ = true; //x=roll 0 
static bool pitch_rot_ = false; //y=pitch 1 
static bool yaw_rot_ = false; //z=yaw 2
static bool height_rot_ = false; //y=raise/lower 1
static bool reset_rot_ = false;
static bool align_to_terrain = false;
static bool BBP_Hide = false;
static bool BBP_Rotate = false;
static bool BBP_Freeze = false;

static bool BBP_For_Back_ = false;
static bool BBP_Up_Down_ = true;
static bool BBP_Left_Right_ = false;

static int BBP_CYCLE_SIZE = 1;

static float holoMove = 0.02;
//static vector holoOffset = "0 0 0";
static float holoOffset = 0;
static float holoOffset_1 = 0;
static float holoOffset_2 = 0;

vector HologramOrientation = "0 0 0";

//////////////////////////////////CYCLE SNAPPING NEXT///////////////////////////////////////
static void cycleSnappingNextWall_150()  //WALL SNAPPING TO WALL (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_WALL_150;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_WALL_150 = 7;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_WALL_150 = 11;
	}
	
	snappingWallPointIndex150 = snappingWallPointIndex150 + 1;
	if (snappingWallPointIndex150 > MAX_SNAPPOINTS_WALL_150)
	{
		snappingWallPointIndex150 = 0;
	}
}
static void cycleSnappingNextWall_600()  //WALL SNAPPING TO WALL (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_WALL_600;
	
	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_WALL_600 = 9;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_WALL_600 = 7;
	}
	
	snappingWallPointIndex600 = snappingWallPointIndex600 + 1;
	if (snappingWallPointIndex600 > MAX_SNAPPOINTS_WALL_600)
	{
		snappingWallPointIndex600 = 0;
	}
}
static void cycleSnappingNextFlat_150()  //WALL SNAPPING TO FLOOR (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_150;
	
	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_150 = 3;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_150 = 19;
	}
	
	snappingFloorPointIndex150 = snappingFloorPointIndex150 + 1;
	if (snappingFloorPointIndex150 > MAX_SNAPPOINTS_FLAT_150)
	{
		snappingFloorPointIndex150 = 0;
	}
}
static void cycleSnappingNextFlat_600()  //WALL SNAPPING TO FLOOR (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_600;
	
	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_600 = 11;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_600 = 3;
	}
	
	snappingFloorPointIndex600 = snappingFloorPointIndex600 + 1;
	if (snappingFloorPointIndex600 > MAX_SNAPPOINTS_FLAT_600)
	{
		snappingFloorPointIndex600 = 0;
	}
}

static void cycleSnappingNextFlatWall_150()  //FLOOR SNAPPING TO WALL (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLOOR_150;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLOOR_150 = 3;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLOOR_150 = 19;
	}
	
	snappingFlatPointIndex150 = snappingFlatPointIndex150 + 1;
	if (snappingFlatPointIndex150 > MAX_SNAPPOINTS_FLOOR_150)
	{
		snappingFlatPointIndex150 = 0;
	}
}

static void cycleSnappingNextFlatWall_600()  //FLOOR SNAPPING TO WALL (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLOOR_600;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLOOR_600 = 11;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLOOR_600 = 3;
	}

	snappingFlatPointIndex600 = snappingFlatPointIndex600 + 1;
	if (snappingFlatPointIndex600 > MAX_SNAPPOINTS_FLOOR_600)
	{
		snappingFlatPointIndex600 = 0;
	}
}

static void cycleSnappingNextFlatFloor_150()  //FLOOR SNAPPING TO FLOOR (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_FLOOR_150;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_150 = 3;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_150 = 19;
	}
	
	snappingFloorFlatPointIndex150 = snappingFloorFlatPointIndex150 + 1;
	if (snappingFloorFlatPointIndex150 > MAX_SNAPPOINTS_FLAT_FLOOR_150)
	{
		snappingFloorFlatPointIndex150 = 0;
	}
}

static void cycleSnappingNextFlatFloor_600()  //FLOOR SNAPPING TO FLOOR (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_FLOOR_600;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_600 = 11;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_600 = 3;
	}

	snappingFloorFlatPointIndex600 = snappingFloorFlatPointIndex600 + 1;
	if (snappingFloorFlatPointIndex600 > MAX_SNAPPOINTS_FLAT_FLOOR_600)
	{
		snappingFloorFlatPointIndex600 = 0;
	}
}

static void cycleSnappingNextPillar()  //PILLAR SNAPPING
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_PILLAR;

	MAX_SNAPPOINTS_PILLAR = 7;

	snappingPillarPointIndex = snappingPillarPointIndex + 1;
	if (snappingPillarPointIndex > MAX_SNAPPOINTS_PILLAR)
	{
		snappingPillarPointIndex = 0;
	}
}

static void cycleSnappingNextFoundation_150()  //FOUNDATION SNAPPING (1.5m)
{
	int MAX_SNAPPOINTS_FOUNDATION_150 = 4;
	snappingFoundationPointIndex150 = snappingFoundationPointIndex150 + 1;
	if (snappingFoundationPointIndex150 > MAX_SNAPPOINTS_FOUNDATION_150)
	{
		snappingFoundationPointIndex150 = 0;
	}
}

////////////////////////////////CYCLE SNAPPING PREVIOUS/////////////////////////////////////

static void cycleSnappingPrevWall_150()  //WALL SNAPPING TO WALL (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_WALL_150;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_WALL_150 = 7;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_WALL_150 = 11;
	}
	
	snappingWallPointIndex150 = snappingWallPointIndex150 - 1;
	if (snappingWallPointIndex150 < 0)
	{
		snappingWallPointIndex150 = MAX_SNAPPOINTS_WALL_150;
	}
}
static void cycleSnappingPrevWall_600()  //WALL SNAPPING TO WALL (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_WALL_600;
	
	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_WALL_600 = 9;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_WALL_600 = 7;
	}
	
	snappingWallPointIndex600 = snappingWallPointIndex600 - 1;
	if (snappingWallPointIndex600 < 0)
	{
		snappingWallPointIndex600 = MAX_SNAPPOINTS_WALL_600;
	}
}
static void cycleSnappingPrevFlat_150()  //WALL SNAPPING TO FLOOR (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_150;
	
	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_150 = 3;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_150 = 19;
	}
	
	snappingFloorPointIndex150 = snappingFloorPointIndex150 - 1;
	if (snappingFloorPointIndex150 < 0)
	{
		snappingFloorPointIndex150 = MAX_SNAPPOINTS_FLAT_150;
	}
}
static void cycleSnappingPrevFlat_600()  //WALL SNAPPING TO FLOOR (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_600;
	
	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_600 = 11;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_600 = 3;
	}
	
	snappingFloorPointIndex600 = snappingFloorPointIndex600 - 1;
	if (snappingFloorPointIndex600 < 0)
	{
		snappingFloorPointIndex600 = MAX_SNAPPOINTS_FLAT_600;
	}
}

static void cycleSnappingPrevFlatWall_150()  //FLOOR SNAPPING TO WALL (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLOOR_150;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLOOR_150 = 3;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLOOR_150 = 19;
	}
	
	snappingFlatPointIndex150 = snappingFlatPointIndex150 - 1;
	if (snappingFlatPointIndex150 < 0)
	{
		snappingFlatPointIndex150 = MAX_SNAPPOINTS_FLOOR_150;
	}
}

static void cycleSnappingPrevFlatWall_600()  //FLOOR SNAPPING TO WALL (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLOOR_600;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLOOR_600 = 11;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLOOR_600 = 3;
	}

	snappingFlatPointIndex600 = snappingFlatPointIndex600 - 1;
	if (snappingFlatPointIndex600 < 0)
	{
		snappingFlatPointIndex600 = MAX_SNAPPOINTS_FLOOR_600;
	}
}

static void cycleSnappingPrevFlatFloor_150()  //FLOOR SNAPPING TO FLOOR (1.5m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_FLOOR_150;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_150 = 3;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_150 = 19;
	}
	
	snappingFloorFlatPointIndex150 = snappingFloorFlatPointIndex150 - 1;
	if (snappingFloorFlatPointIndex150 < 0)
	{
		snappingFloorFlatPointIndex150 = MAX_SNAPPOINTS_FLAT_FLOOR_150;
	}
}

static void cycleSnappingPrevFlatFloor_600()  //FLOOR SNAPPING TO FLOOR (6m)
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_FLAT_FLOOR_600;

	if ( otherSnappingObject.canSnap150() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_600 = 11;
	}
	if ( otherSnappingObject.canSnap600() )
	{
		MAX_SNAPPOINTS_FLAT_FLOOR_600 = 3;
	}

	snappingFloorFlatPointIndex600 = snappingFloorFlatPointIndex600 - 1;
	if (snappingFloorFlatPointIndex600 < 0)
	{
		snappingFloorFlatPointIndex600 = MAX_SNAPPOINTS_FLAT_FLOOR_600;
	}
}

static void cycleSnappingPrevPillar()  //PILLAR SNAPPING
{
	BBP_BASE otherSnappingObject;
	otherSnappingObject = BBP_SNAPPING_OBJECT;
	int MAX_SNAPPOINTS_PILLAR;

	MAX_SNAPPOINTS_PILLAR = 7;

	snappingPillarPointIndex = snappingPillarPointIndex - 1;
	if (snappingPillarPointIndex < 0)
	{
		snappingPillarPointIndex = MAX_SNAPPOINTS_PILLAR;
	}
}

static void cycleSnappingPrevFoundation_150()  //FOUNDATION SNAPPING (1.5m)
{
	int MAX_SNAPPOINTS_FOUNDATION_150 = 4;
	snappingFoundationPointIndex150 = snappingFoundationPointIndex150 - 1;
	if (snappingFoundationPointIndex150 < 0)
	{
		snappingFoundationPointIndex150 = MAX_SNAPPOINTS_FOUNDATION_150;
	}
}
static void cycleSnappingPrevFoundation_600()  //FOUNDATION SNAPPING (6m)
{
	int MAX_SNAPPOINTS_FOUNDATION_600 = 1;
	snappingFoundationPointIndex600 = snappingFoundationPointIndex600 - 1;
	if (snappingFoundationPointIndex600 < 0)
	{
		snappingFoundationPointIndex600 = MAX_SNAPPOINTS_FOUNDATION_600;
	}
}

//Big help from the modding discord <3
Object BBP_getObjectAtCrosshair(float distance = 15.0, float radius = 0, Object with = NULL)
{
	Object BBP_Snaps = BBP_GetCursorObject();
	
	if(BBP_Snaps && BBP_Snaps.IsInherited(BBP_BASE))
	{
		return BBP_Snaps;
	}

	return NULL;
}

static Object BBP_GetCursorObject()
{
	vector rayStart = GetGame().GetCurrentCameraPosition();
	vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * 25;
	vector contact_pos;
	vector contact_dir;
	int contact_component;
	set< Object > objects = new set< Object >;
	if( DayZPhysics.RaycastRV( rayStart, rayEnd, contact_pos, contact_dir, contact_component, objects, NULL, GetGame().GetPlayer(), false, false, ObjIntersectView) )
	{
		if( objects.Count())
		{
			return objects.Get( 0 );
		}
	}

	return NULL;
}

/* static set< Object > BBP_GetObjectsAt2( vector from, vector to, Object ignore = NULL, float radius = 0, Object with = NULL )
{
    vector contact_pos;
    vector contact_dir;
    int contact_component;

    set< Object > view = new set< Object >;

    DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius );

    if ( view ) 
    {
        return view;
    }
    return NULL;
} */

BBP_BASE BBP_SNAPPING_OBJECT;
BBP_BASE AUTO_BBP_SNAPPING_OBJECT;

void BBP_SelectObject()
{
	BBP_SNAPPING_OBJECT = BBP_BASE.Cast(SnappingWithOtherWall());	
}

Object SnappingWithOtherWall()
{
	Object obj = BBP_getObjectAtCrosshair();
	if (obj && obj.IsInherited(BBP_BASE))
	{
		AUTO_BBP_SNAPPING_OBJECT = BBP_BASE.Cast(obj);
		return AUTO_BBP_SNAPPING_OBJECT;
	}
	else
	{
		AUTO_BBP_SNAPPING_OBJECT = null;
		return AUTO_BBP_SNAPPING_OBJECT;
	}
}

static void BBP_Message( PlayerBase player, string txt ) 
{

}
