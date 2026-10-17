class BBP_Metal_Stair_Kit extends BBP_KIT_BASE
{
	void BBP_Metal_Stair_Kit()
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
	
	override bool isRamp()
	{
		return true;
	}

	//Kit item and hologram
	string BBPItem(int BBP_SIZE_T)
	{
		return "BBP_Metal_Stair";
	}

	override string NeededHologram()
	{
		return "BBP_Metal_stair_Hologram";
	}

	//Define snapping width small stair hack 
	override bool canSnap600()
	{
		if (BBP_CYCLE_SIZE == 1 )
		{	
			return true;
		}
		if (BBP_CYCLE_SIZE == 2)
		{	
			if(AUTO_BBP_SNAPPING_OBJECT.isRamp())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	override bool canSnap150()
	{
		return false;
	}
};

