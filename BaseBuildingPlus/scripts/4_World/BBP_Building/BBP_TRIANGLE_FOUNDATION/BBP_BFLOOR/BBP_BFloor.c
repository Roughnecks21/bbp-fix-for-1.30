class BBP_Triangle_Foundation extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Triangle_Foundation_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Triangle Foundation";
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
