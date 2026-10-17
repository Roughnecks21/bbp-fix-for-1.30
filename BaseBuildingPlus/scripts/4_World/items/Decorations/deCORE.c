class BBP_WallPaper extends ItemBase
{
	void BBP_WallPaper()
	{
		//synchronized variables
		//RegisterNetSyncVariableBool( "m_IsMounted" );
		ShowSelection("folded");
		HideSelection("unfolded_1");
		HideSelection("unfolded_2");
		HideSelection("unfolded_3");
		HideSelection("unfolded_4");
		HideSelection("unfolded_5");
		HideSelection("unfolded_6");
	}
	
	void ~BBP_WallPaper()
	{
	}
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		
	}
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
				
		//set mounted state based on locked slot after everything is loaded
		//SetMountedState( GetSlotLockedState() );
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		
		
		if (parent.IsInherited(BBP_BDoor))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			ShowSelection("unfolded_2");
			HideSelection("unfolded_3");
			HideSelection("unfolded_4");
			HideSelection("unfolded_5");
			HideSelection("unfolded_6");
			HideSelection("unfolded_7");
		}
		
		if (parent.IsInherited(BBP_Bwall))
		{
			HideSelection("folded");
			ShowSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
			HideSelection("unfolded_4");
			HideSelection("unfolded_5");
			HideSelection("unfolded_6");
			HideSelection("unfolded_7");
		}
		
		if (parent.IsInherited(BBP_BWindow))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			ShowSelection("unfolded_3");
			HideSelection("unfolded_4");
			HideSelection("unfolded_5");
			HideSelection("unfolded_6");
			HideSelection("unfolded_7");
		}
		
		if (parent.IsInherited(BBP_Half_Bwall))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
			ShowSelection("unfolded_4");
			HideSelection("unfolded_5");
			HideSelection("unfolded_6");
			HideSelection("unfolded_7");
		}
		if (parent.IsInherited(BBP_Left_Slope_Wall))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
			HideSelection("unfolded_4");
			ShowSelection("unfolded_5");
			HideSelection("unfolded_6");
			HideSelection("unfolded_7");
		}
		if (parent.IsInherited(BBP_Right_Slope_Wall))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
			HideSelection("unfolded_4");
			HideSelection("unfolded_5");
			ShowSelection("unfolded_6");
			HideSelection("unfolded_7");
		}
		if (parent.IsInherited(BBP_Swall))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
			HideSelection("unfolded_4");
			HideSelection("unfolded_5");
			HideSelection("unfolded_6");
			ShowSelection("unfolded_7");
		}
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		
		ShowSelection("folded");
		HideSelection("unfolded_1");
		HideSelection("unfolded_2");
		HideSelection("unfolded_3");
		HideSelection("unfolded_4");
		HideSelection("unfolded_5");
		HideSelection("unfolded_6");
		HideSelection("unfolded_7");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
	}
}

class BBP_WallPaper_Mural extends ItemBase
{
	void BBP_WallPaper_Mural()
	{
		//synchronized variables
		//RegisterNetSyncVariableBool( "m_IsMounted" );
		ShowSelection("folded");
		HideSelection("unfolded_1");
	}
	
	void ~BBP_WallPaper_Mural()
	{
	}
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		
	}
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
				
		//set mounted state based on locked slot after everything is loaded
		//SetMountedState( GetSlotLockedState() );
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		
		if (parent.IsInherited(BBP_Bwall))
		{
			HideSelection("folded");
			ShowSelection("unfolded_1");
		}	
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		
		ShowSelection("folded");
		HideSelection("unfolded_1");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
	}
}

class BBP_Carpet extends ItemBase
{
	void BBP_Carpet()
	{
		//synchronized variables
		//RegisterNetSyncVariableBool( "m_IsMounted" );
		ShowSelection("folded");
		HideSelection("unfolded_1");
		HideSelection("unfolded_2");
		HideSelection("unfolded_3");
	}
	
	void ~BBP_Carpet()
	{
	}
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		
	}
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
				
		//set mounted state based on locked slot after everything is loaded
		//SetMountedState( GetSlotLockedState() );
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		
		if (parent.IsInherited(BBP_Bfloor) || parent.IsInherited(BBP_Bfoundation))
		{
			HideSelection("folded");
			ShowSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
		}
		
		if (parent.IsInherited(BBP_Floor_Hatch))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			ShowSelection("unfolded_2");
			HideSelection("unfolded_3");
		}
		
		if (parent.IsInherited(BBP_Triangle_Bfloor) || parent.IsInherited(BBP_Triangle_Foundation))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			ShowSelection("unfolded_3");
		}
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		
		ShowSelection("folded");
		HideSelection("unfolded_1");
		HideSelection("unfolded_2");
		HideSelection("unfolded_3");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
	}
}
class BBP_Plaster extends ItemBase
{
	void BBP_Plaster()
	{
		//synchronized variables
		//RegisterNetSyncVariableBool( "m_IsMounted" );
		ShowSelection("folded");
		HideSelection("unfolded_1");
		HideSelection("unfolded_2");
		HideSelection("unfolded_3");
	}
	
	void ~BBP_Plaster()
	{
	}
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		
	}
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
				
		//set mounted state based on locked slot after everything is loaded
		//SetMountedState( GetSlotLockedState() );
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		
		if (parent.IsInherited(BBP_Bfloor) || parent.IsInherited(BBP_Broof))
		{
			HideSelection("folded");
			ShowSelection("unfolded_1");
			HideSelection("unfolded_2");
			HideSelection("unfolded_3");
		}
		
		if (parent.IsInherited(BBP_Floor_Hatch) || parent.IsInherited(BBP_Roof_Hatch))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			ShowSelection("unfolded_2");
			HideSelection("unfolded_3");
		}
		
		if (parent.IsInherited(BBP_Triangle_Bfloor) || parent.IsInherited(BBP_Triangle_Broof))
		{
			HideSelection("folded");
			HideSelection("unfolded_1");
			HideSelection("unfolded_2");
			ShowSelection("unfolded_3");
		}
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		
		ShowSelection("folded");
		HideSelection("unfolded_1");
		HideSelection("unfolded_2");
		HideSelection("unfolded_3");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
	}
}