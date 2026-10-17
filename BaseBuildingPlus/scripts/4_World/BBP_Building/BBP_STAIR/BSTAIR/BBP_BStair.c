class BBP_Bstair extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Stair_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Large Stair";
	}

	
	override bool isDismantle()
	{
		return true;
	}
	
	override string GetDisplayName()
	{
		if (BBPGetTier() == 69)
		{
			return "[Hologram] " + "Large Stair";
		}

		return "Large Stair";
	}
};
