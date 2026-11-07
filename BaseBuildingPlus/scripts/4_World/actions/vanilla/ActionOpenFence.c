modded class ActionOpenFence
{
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask)
	{
		if (target)
		{
			BBP_BASE gate = BBP_BASE.Cast(target.GetObject());
			if (gate)
			{
				DigitalCodeLock codeLock = gate.GetCodeLock();
				if (codeLock)
				{
					// Configured vanilla locks use ActionBBPTrustedOpen.
					if (codeLock.HasPIN()) return false;
					// Unconfigured locks retain the vanilla action, only on the panel.
					if (!gate.BBPCanInteractDoor(target)) return false;
				}
#ifdef EXPANSIONMODBASEBUILDING
				// Expansion skips BBP's ActionCondition for its locks.
				if (!codeLock && gate.isBBPDoor() && gate.ExpansionGetCodeLock() && !gate.BBPCanInteractDoor(target)) return false;
#endif
			}
		}
		return super.Can(player, target, item, condition_mask);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		BBP_BASE bbpbase = BBP_BASE.Cast( target.GetObject() );
		
		if(bbpbase != null)
		{
			if (!bbpbase.BBPCanInteractDoor(target)) return false;
			if ( bbpbase && bbpbase.CanCloseFence() )
			{
				return false;
			}
			
			if ( bbpbase && bbpbase.BBPGetTier() == 0 || bbpbase.BBPGetTier() == 69 )
			{
				if(bbpbase.IsBBPGate() && !bbpbase.isBBPDoor())
				{
					return false;
				}
			}
			
			if(bbpbase && !bbpbase.BBP_HasDoor())
			{
				if(!bbpbase.IsBBPGate())
				{
					return false;
				}
			}
			
			if ( bbpbase && bbpbase.CanOpenFence() )
			{
				if ( bbpbase.isWindow() && !bbpbase.isSmall())
				{
					if(!bbpbase.BBP_HasDoor())
					{
						return false;
					}
					
					if ( !bbpbase.HasProperDistanceBBPWindow( "inside2", player ) )
					{
						return false;
					}
				}
				if ( bbpbase.isWindow() && bbpbase.isSmall())
				{
					if(!bbpbase.BBP_HasDoor())
					{
						return false;
					}
					
					if ( bbpbase.HasProperDistanceBBP( "inside", player ) )
					{
						return true;
					}
					return false;
				}
				
				if ( bbpbase && bbpbase.isBBPDoor() && !bbpbase.isWindow())
				{
					if(!bbpbase.BBP_HasDoor())
					{
						return false;
					}
					
					if(bbpbase.BBP_HasDoor())
					{
						return true;
					}
				}
				
				return true;
			}
		}
		return super.ActionCondition(player, target, item);
	}
}