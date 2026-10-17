modded class VicinityItemManager
{
	override bool IsObstructed (Object filtered_object)
	{
		if ( filtered_object.CanUseConstruction() )
		{
			BBP_BASE bbpbase = BBP_BASE.Cast( filtered_object );
			if ( bbpbase )
			{
				return false;
			}
		}
		return super.IsObstructed (filtered_object);
	}
}
