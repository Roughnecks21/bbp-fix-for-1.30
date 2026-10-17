class BBP_Bfloor extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Floor_Kit";
	}
	
	override bool isflat()
	{
		return true;
	}
	
	override bool isFloor()
	{
		return true;
	}

	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetBBPType()
	{
		return "BBP Large Floor";
	}
};
