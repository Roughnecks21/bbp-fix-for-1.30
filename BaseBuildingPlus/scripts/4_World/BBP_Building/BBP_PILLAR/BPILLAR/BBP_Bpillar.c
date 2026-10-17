class BBP_Bpillar extends BBP_BASE_LIGHT
{
	//Construction Kit
	override string GetConstructionKitType()
	{
		return "BBP_Pillar_Kit";
	}
	
	override bool isDismantle()
	{
		return true;
	}
	
	 override bool IsFacingPlayer( PlayerBase player, string selection )
	{
		return false;
	}
	
	override bool IsFacingCamera( string selection )
	{
		return false;
	}
	
	override bool HasProperDistance( string selection, PlayerBase player )
	{
		return true;
	}
	
	override string GetBBPType()
	{
		return "BBP Tall Pillar";
	}
};
