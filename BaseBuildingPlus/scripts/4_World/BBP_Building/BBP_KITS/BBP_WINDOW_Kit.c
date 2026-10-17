class BBP_Window_Kit extends BBP_KIT_BASE
{
	void BBP_Window_Kit()
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
	
	override bool isDoor()
	{
		return true;
	}

	//Kit item and hologram
	string BBPItem(int BBP_SIZE_T)
	{
		//Sizes
		if(BBP_SIZE_T == 1)
		{	
			return "BBP_BWindow";
		}
		if(BBP_SIZE_T == 2)
		{	
			return "BBP_SWindow";
		}
		
		return "BBP_BWindow";
	}

	override string NeededHologram()
	{
		//Sizes
		if(BBP_CYCLE_SIZE == 1)
		{	
			return "BBP_BWindow_Hologram";
		}
		if(BBP_CYCLE_SIZE == 2)
		{	
			return "BBP_SWindow_Hologram";
		}
		
		return "BBP_BWindow_Hologram";
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
