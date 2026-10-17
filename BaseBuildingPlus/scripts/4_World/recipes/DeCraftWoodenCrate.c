modded class DeCraftWoodenCrate
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ItemBase crate;
		Class.CastTo(crate, ingredients[0]);

		if ( crate.GetInventory().CountInventory() > 1 )
			return false;

		if ( crate.IsInherited(BBP_Workbench) || crate.IsInherited(BBP_Concrete_Brick_Pile) || crate.IsInherited(BBP_Cement) )
			return false;

		return true;
	}
};
