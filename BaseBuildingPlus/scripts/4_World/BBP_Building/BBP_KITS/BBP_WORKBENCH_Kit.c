class BBP_Workbench_Kit extends BBP_KIT_BASE
{
	void BBP_Workbench_Kit()
	{
		setCanCycleSize(true);
		setCanCyclePart(true);
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		if (GetGame().IsServer())
		{
			//BBP_Workbench bbp_bench = BBP_Workbench.Cast( GetGame().CreateObject( "BBP_Workbench", position ) );
			BBP_Workbench bbp_bench = BBP_Workbench.Cast( GetGame().CreateObjectEx( "BBP_Workbench", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			bbp_bench.SetPosition( position );
			bbp_bench.SetOrientation( orientation );
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			SetIsDeploySound( true );
			
			if (m_AdminLog)
			{            
				m_AdminLog.OnPlacementComplete( player, this);
			}
		}
	}
	
	//Kit item and hologram
	string BBPItem(int BBP_SIZE_T)
	{
		return "BBP_Workbench";
	}

	override string NeededHologram()
	{
		return "BBP_Workbench_Hologram";
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
