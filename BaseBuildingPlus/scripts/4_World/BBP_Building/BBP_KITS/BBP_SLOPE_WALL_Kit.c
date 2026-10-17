class BBP_Slope_Wall_Kit extends BBP_KIT_BASE
{
	void BBP_Slope_Wall_Kit()
	{
		setCanSnapBBP(true);
		setCanCycleSize(true);
		setCanCyclePart(true);
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if ( GetGame().IsServer() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			BBP_BASE bbpitem = BBP_BASE.Cast( GetGame().CreateObject( this.BBPItem(player_base.returnSize()), position) );
			bbpitem.SetPosition( position );
			bbpitem.SetOrientation( orientation );
			bbpitem.SetAnimationPhase( "Hologram", 0 );
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

	//Kit item and hologram
	string BBPItem(int BBP_SIZE_T)
	{
		//Sizes
		if(BBP_SIZE_T == 1)
		{	
			return "BBP_Right_Slope_Wall";
		}
		if(BBP_SIZE_T == 2)
		{	
			return "BBP_Left_Slope_Wall";
		}
		
		return "BBP_Right_Slope_Wall";
	}

	override string NeededHologram()
	{
		//Sizes
		if(BBP_CYCLE_SIZE == 1)
		{	
			return "BBP_Right_Slope_Wall_Hologram";
		}
		if(BBP_CYCLE_SIZE == 2)
		{	
			return "BBP_Left_Slope_Wall_Hologram";
		}
		
		return "BBP_Right_Slope_Wall_Hologram";
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

