//BASE BUILDING BASE
modded class BaseBuildingBase
{
	bool IsFancyBBPItem()
	{
		return false;
	}

	bool IsRaidable()
	{
		return true;
	}

	bool DisableDestroyBBP()
	{
		return false;
	}

	string GetBBPTier()
	{
		return "Tier1";
	}
	
	bool HasProperDistanceBBP( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance <= 0.8 ) //0.07
			{
				return true;
			}
		}
		return false;
	}
	
	bool HasProperDistanceFlatBBP( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 2.25 )
			{
				return false;
			}
		}
		return true;
	}
	
	bool HasProperDistanceFlatInvBBP( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 3.1 )
			{
				return false;
			}
		}
		return true;
	}

	bool HasProperDistanceBBPWindow( string selection, PlayerBase player )
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			float distance = vector.Distance( selection_pos, player.GetPosition() );
			if ( distance >= 2.4 )
			{
				return false;
			}
		}
		return true;
	}
}
