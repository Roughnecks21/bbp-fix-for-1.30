modded class ActionCloseFence
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		BBP_BASE bbpbase = BBP_BASE.Cast( target.GetObject() );
		if ( bbpbase && bbpbase.CanCloseFence() )
		{
			return true;
		}
		return super.ActionCondition( player, target, item );
	}
}
