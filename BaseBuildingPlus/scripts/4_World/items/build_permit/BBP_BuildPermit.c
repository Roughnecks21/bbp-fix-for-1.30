class BBP_BuildPermit extends ItemBase 
{
	
};

class BBP_TapeMeasure extends ItemBase 
{
	override void SetActions() 
	{
		super.SetActions();
		AddAction(ActionGetBBPHP);
	}
};
