class BBP_Slope_Roof extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Slope_Roof_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Slope Roof";
	}
	
	override bool isflat()
	{
		return true;
	}

	override bool HasClutterCutter()
	{
		return true;
	}
	
	 override bool IsFacingPlayer( PlayerBase player, string selection )
	{
		return false;
	}
	
	override bool IsFacingCamera( string selection )
	{
		return false;
	}
	
	override bool HasProperDistance( string selection, PlayerBase player )
	{
		return true;
	}
};
