modded class ActionDestroyPart
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		
		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			return false;
		}
		
		return super.ActionCondition(player,target,item);
	}

}