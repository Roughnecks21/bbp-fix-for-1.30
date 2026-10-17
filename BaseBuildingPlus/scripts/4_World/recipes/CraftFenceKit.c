modded class CraftFenceKit extends RecipeBase
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		if ( ingredients[0].GetInventory().IsAttachment() )
			return false;
		if ( ingredients[1].GetInventory().IsAttachment() )
			return false;
		if ( BBPgetDisableCraftVanillaFence() == true )
			return false;
		return true;
	}
	
	bool BBPgetDisableCraftVanillaFence()
	{
		BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
		if (bbp_config)
		{
			return bbp_config.BBP_DisableCraftVanillaFence;
		}
		return false;
	}
};
