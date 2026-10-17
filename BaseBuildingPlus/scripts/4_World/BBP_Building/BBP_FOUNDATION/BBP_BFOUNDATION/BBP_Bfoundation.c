class BBP_Bfoundation extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Foundation_Kit";
	}
	
	override bool isFoundation()
	{
		return true;
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
		return "BBP Foundation";
	}		
};
