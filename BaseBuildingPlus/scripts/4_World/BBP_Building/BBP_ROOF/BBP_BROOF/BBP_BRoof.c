class BBP_Broof extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Roof_Kit";
	}
	
	override bool isflat()
	{
		return true;
	}

	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetBBPType()
	{
		return "BBP Roof";
	}
};
