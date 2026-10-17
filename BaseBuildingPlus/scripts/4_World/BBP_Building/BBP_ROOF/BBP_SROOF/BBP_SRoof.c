class BBP_Sroof extends BBP_BASE
{
	//Construction Kit
	override bool isflat()
	{
		return true;
	}
	
	override string GetConstructionKitType()
	{
		return "BBP_Roof_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Small Roof";
	}
};
