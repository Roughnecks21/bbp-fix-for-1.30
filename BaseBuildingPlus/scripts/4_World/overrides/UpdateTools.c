modded class ItemBase
{
	override void SetActions() 
	{
		super.SetActions();
		AddAction(ActionDismantleBBP);
		AddAction(ActionDestroyBBP);
	}	
}
