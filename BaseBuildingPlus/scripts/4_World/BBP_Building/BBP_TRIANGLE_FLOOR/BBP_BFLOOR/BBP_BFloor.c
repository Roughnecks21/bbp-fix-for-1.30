class BBP_Triangle_Bfloor extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Triangle_Floor_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Triangle Floor";
	}
	
	override bool isflat()
	{
		return true;
	}
	
	override bool isTriangle()
	{
		return true;
	}

	override bool HasClutterCutter()
	{
		return true;
	}
};
