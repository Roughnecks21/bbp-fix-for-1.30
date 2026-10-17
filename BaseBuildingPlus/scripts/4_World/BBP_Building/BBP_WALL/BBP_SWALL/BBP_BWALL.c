class BBP_Swall extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Wall_Kit";
	}
	
	override string GetBBPType()
	{
		return "BBP Small Wall";
	}
	
	override bool isSmall()
	{
		return true;
	}
};
