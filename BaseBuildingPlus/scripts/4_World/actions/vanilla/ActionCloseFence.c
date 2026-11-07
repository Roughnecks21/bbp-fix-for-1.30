modded class ActionCloseFence
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
			}
		}
		return super.Can(player, target, item, condition_mask);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		BBP_BASE bbpbase = BBP_BASE.Cast( target.GetObject() );
		if (bbpbase && !bbpbase.BBPCanInteractDoor(target)) return false;
		if ( bbpbase && bbpbase.CanCloseFence() )
		{
			return true;
		}
		return super.ActionCondition( player, target, item );
	}
}
