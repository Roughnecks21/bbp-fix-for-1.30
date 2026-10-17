class BBP_Floor_Mesh extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Floor_Mesh_Kit";
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
		return "BBP Floor Mesh";
	}
};
