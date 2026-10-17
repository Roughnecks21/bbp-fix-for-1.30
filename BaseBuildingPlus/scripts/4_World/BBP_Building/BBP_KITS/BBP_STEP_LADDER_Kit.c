class BBP_Step_Ladder_Kit extends BBP_KIT_BASE
{
	void BBP_Step_Ladder_Kit()
	{
		setCanSnapFloorBBP(false);
		setCanCycleSize(false);
		setCanCyclePart(false);
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
		return "BBP_Step_Ladder";
	}

	override string NeededHologram()
	{
		return "BBP_Step_Ladder_Hologram";
	}

	//Define snapping width
	override bool canSnap600()
	{
		return false;
	}

	override bool canSnap150()
	{
		return false;
	}
};
