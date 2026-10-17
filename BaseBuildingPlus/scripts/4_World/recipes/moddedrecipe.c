modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new BBPCraftWorkbench);
		RegisterRecipe(new BBPCraftWorkbenchPermit);
		RegisterRecipe(new BBPDismantleCementMixer);
		RegisterRecipe(new BBPCraftStepLadder);
	}
}
