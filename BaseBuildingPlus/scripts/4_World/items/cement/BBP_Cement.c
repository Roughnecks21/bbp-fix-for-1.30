class BBP_TwoHeavy extends ItemBase
{	
    override bool IsHeavyBehaviour() 
    {
        return true;
    }
    
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }
}

class BBP_Cement extends BBP_TwoHeavy
{
}

class BBP_Concrete_Brick_Pile extends BBP_TwoHeavy
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttachToConstruction);
	}
}

class BBP_Mortar_Mix extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttachToConstruction);
	}
}