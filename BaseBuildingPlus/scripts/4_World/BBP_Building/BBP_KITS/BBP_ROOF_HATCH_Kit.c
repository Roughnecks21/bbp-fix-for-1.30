class BBP_Roof_Hatch_Kit extends BBP_KIT_BASE
{
	void BBP_Roof_Hatch_Kit()
	{
		setCanSnapFloorBBP(true);
		setCanCycleSize(true);
		setCanCyclePart(true);
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
		}
	}
	
	override bool isDoor()
	{
		return true;
	}
	
	override bool isFloor()
	{
		return true;
	}

	//Kit item and hologram
	string BBPItem(int BBP_SIZE_T)
	{
		return "BBP_Roof_Hatch";
	}

	override string NeededHologram()
	{
		return "BBP_Roof_Hatch_Hologram";
	}

	//Define snapping width
	override bool canSnap600()
	{
		return true;
	}

	override bool canSnap150()
	{
		return false;
	}
};

