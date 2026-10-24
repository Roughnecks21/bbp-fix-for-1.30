class BBP_Workbench extends ItemBase 
{
    void BBP_Workbench() 
    {
    }
    
    override bool IsHeavyBehaviour() 
    {
        return true;
    }
    
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }
    
    override bool IsDeployable() 
    {
        return false;
    }
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		if ( item.IsKindOf ( "Nail" ) ) 
		{
			SetAnimationPhase( "Nails", 0 );
		}
		if ( item.IsKindOf ( "WoodenLog" ) ) 
		{
			SetAnimationPhase( "Logs", 0 );
		}
		if ( item.IsKindOf ( "WoodenPlank" ) ) 
		{
			SetAnimationPhase( "Planks", 0 );
		}
		if ( item.IsKindOf ( "MetalPlate" ) ) 
		{
			SetAnimationPhase( "Metal", 0 );
		}
		if ( item.IsKindOf ( "BBP_TapeMeasure" ) ) 
		{
			SetAnimationPhase( "Tape", 0 );
		}
		if ( item.IsKindOf ( "HandSaw" ) ) 
		{
			SetAnimationPhase( "HandSaw", 0 );
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if ( item.IsKindOf ( "Nail" ) ) 
		{
			SetAnimationPhase( "Nails", 1 );
		}
		if ( item.IsKindOf ( "WoodenLog" ) ) 
		{
			SetAnimationPhase( "Logs", 1 );
		}
		if ( item.IsKindOf ( "WoodenPlank" ) ) 
		{
			SetAnimationPhase( "Planks", 1 );
		}
		if ( item.IsKindOf ( "MetalPlate" ) ) 
		{
			SetAnimationPhase( "Metal", 1 );
		}
		if ( item.IsKindOf ( "BBP_TapeMeasure" ) ) 
		{
			SetAnimationPhase( "Tape", 1 );
		}
		if ( item.IsKindOf ( "HandSaw" ) ) 
		{
			SetAnimationPhase( "HandSaw", 1 );
		}
	}
	
	bool DeductMats_check( string title, float quantity )
    {
        if ( title == "Nail" )
		{
			title = "Material_Nails";
		}
		else if ( title == "WoodenLog" )
		{
			title = "Truck_01_WoodenLogs";
		}
		else if ( title == "WoodenPlank" )
		{
			title = "Material_WoodenPlanks";
		}
		else if ( title == "BBP_Cement" )
		{
			title = "Material_Cement";
		}
		else if ( title == "BBP_Mortar_Mix" )
		{
			title = "Material_Mortar";
		}
		else if ( title == "BBP_Concrete_Brick_Pile" )
		{
			title = "Material_BBP_Concrete_Brick_Pile";
		}
		else if ( title == "MetalPlate" )
		{
			title = "Material_MetalSheets";
		}
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString(title);
		ItemBase item = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		if ( item && item.GetQuantity() >= quantity )
		{
			//item.AddQuantity( -quantity );
			return true;
		}
		return false;
    }
	
	void DeductMats( string title, float quantity )
    {
        if ( title == "Nail" )
		{
			title = "Material_Nails";
		}
		else if ( title == "WoodenLog" )
		{
			title = "Truck_01_WoodenLogs";
		}
		else if ( title == "WoodenPlank" )
		{
			title = "Material_WoodenPlanks";
		}
		else if ( title == "BBP_Cement" )
		{
			title = "Material_Cement";
		}
		else if ( title == "BBP_Mortar_Mix" )
		{
			title = "Material_Mortar";
		}
		else if ( title == "BBP_Concrete_Brick_Pile" )
		{
			title = "Material_BBP_Concrete_Brick_Pile";
		}
		else if ( title == "MetalPlate" )
		{
			title = "Material_MetalSheets";
		}
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString(title);
		ItemBase item = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		if ( item && item.GetQuantity() >= quantity )
		{
			item.AddQuantity( -quantity );
			//return true;
		}
		//return false;
    }
	
	BBP_CRAFTINGBOOK_BASE GetCraftingBook(){
	
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Blueprint");
		BBP_CRAFTINGBOOK_BASE bbpblueprint = BBP_CRAFTINGBOOK_BASE.Cast( GetInventory().FindAttachment(slot_id) );
		return bbpblueprint;
	}
	
	bool Has_BluePrint()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Blueprint");
		BBP_CRAFTINGBOOK_BASE bbpblueprint = BBP_CRAFTINGBOOK_BASE.Cast( GetInventory().FindAttachment(slot_id) );
		
		if ( bbpblueprint )
		{
			return true;
		}
		
		return false;
	}
	
	bool Has_Tools()
	{
		// Keep the existing client/server crafting checks compatible; no tool is required.
		return true;
	}
	
		override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionFoldBBP);
		AddAction(ActionReadCraftingBookOnWB);
	}
}
