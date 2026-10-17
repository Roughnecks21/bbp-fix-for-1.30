class BBP_Floor_Kit extends BBP_KIT_BASE
{
	Object 	m_ClutterCutter;
	
	void BBP_Floor_Kit()
	{
		setCanSnapFloorBBP(true);
		setCanCycleSize(true);
		setCanCyclePart(true);
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{				
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		if ( !m_ClutterCutter )
		{		
			m_ClutterCutter = GetGame().CreateObjectEx( "ClutterCutter6x6", GetPosition(), ECE_PLACE_ON_SURFACE );
			m_ClutterCutter.SetOrientation( GetOrientation() );
		}

		return true;
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if (m_ClutterCutter  &&  GetGame())
		{
			GetGame().ObjectDelete(m_ClutterCutter);
			m_ClutterCutter = NULL;
		}
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
		if (bbp_config)
		{
			bool HologramHasCollision = bbp_config.BBP_HologramHasCollision;
		}
		if ( GetGame().IsServer() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			BBP_BASE bbpitem = BBP_BASE.Cast( GetGame().CreateObject( this.BBPItem(player_base.returnSize()), position) );
			bbpitem.SetPosition( position );
			bbpitem.SetOrientation( orientation );
			bbpitem.SetAnimationPhase( "Hologram", 0 );
			if ( HologramHasCollision )
			{
				bbpitem.GetConstruction().AdminBuildPartServer( player, "hologram_collision", AT_BUILD_PART );
			}
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			BBP_PlayPlaceSound();
			ResetBBPSettings();
			if (m_AdminLog)
			{            
				m_AdminLog.OnPlacementComplete( player, this);
			}

			// To properly move the clutter cutter from spawn position, it must be deleted and created again.
			if (m_ClutterCutter)
			{
				GetGame().ObjectDelete(m_ClutterCutter);
				m_ClutterCutter = NULL;
			}
			
			if (!m_ClutterCutter)
			{		
				m_ClutterCutter = GetGame().CreateObjectEx( "ClutterCutter6x6", GetPosition(), ECE_PLACE_ON_SURFACE );
				m_ClutterCutter.SetOrientation( orientation );
			}
		}
	}
	
	override bool isFloor()
	{
		return true;
	}

	//Kit item and hologram
	string BBPItem(int BBP_SIZE_T)
	{
		//Sizes
		if(BBP_SIZE_T == 1)
		{	
			return "BBP_Bfloor";
		}
		if(BBP_SIZE_T == 2)
		{	
			return "BBP_Sfloor";
		}
		
		return "BBP_Bfloor";
	}

	override string NeededHologram()
	{
		//Sizes
		if(BBP_CYCLE_SIZE == 1)
		{	
			return "BBP_Bfloor_Hologram";
		}
		if(BBP_CYCLE_SIZE == 2)
		{	
			return "BBP_Sfloor_Hologram";
		}
		
		return "BBP_Bfloor_Hologram";
	}

	//Define snapping width
	override bool canSnap600()
	{
		if (BBP_CYCLE_SIZE == 1 )
		{	
			return true;
		}
		else
		{
			return false;
		}
	}

	override bool canSnap150()
	{
		if (BBP_CYCLE_SIZE == 2)
		{	
			return true;
		}
		else
		{
			return false;
		}
	}
};

