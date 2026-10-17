class BBP_Triangle_Broof extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Triangle_Roof_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Triangle Roof";
	}
	
	override bool isflat()
	{
		return true;
	}

	override bool HasClutterCutter()
	{
		return true;
	}
	
	override bool isTriangle()
	{
		return true;
	}
};
