class BBP_Sstair extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Stair_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Small Stair";
	}
	
	override bool isflat()
	{
		return true;
	}
	
	override bool isRamp()
	{
		return true;
	}
	
	override bool isDismantle()
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
	
	override string GetDisplayName()
	{
		if (BBPGetTier() == 69)
		{
			return "[Hologram] " + "Small Stair";
		}

		return "Small Stair";
	}
};
