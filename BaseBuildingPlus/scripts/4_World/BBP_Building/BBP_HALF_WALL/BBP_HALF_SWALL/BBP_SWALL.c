class BBP_Half_Swall extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Half_Wall_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Half Small Wall";
	}
	
	override bool isSmall()
	{
		return true;
	}
};
