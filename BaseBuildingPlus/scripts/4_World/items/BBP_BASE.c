static const int RPC_CUSTOM_DATA = -361158;

class BBP_BASE extends Fence
{
	BBPConfig 									bbp_config;
	protected bool								m_BBP_IsSwichedOn;
	//protected bool 							m_DismantleDisabled;
	protected Object 							m_ClutterCutter;

	typename ATTACHMENT_BARBED_WIRE				= BarbedWire;
	typename ATTACHMENT_FLASHLIGHT				= Flashlight;
	const string ATTACHMENT_SLOT_BARBED_WIRE 	= "Wall_BarbedWire_1";
	protected string m_CustomName;

	void BBP_BASE()
	{
	}

	//1.23 Falling items fix
	override bool CanBeIgnoredByDroppedItem()
    {
        return false;
    }
	
	override bool isBBP_Object()
	{
		return true;
	}
	
	void ~BBP_BASE()
	{
		if ( GetGame() )
		{
			DestroyClutterCutter();
		}
	}
	
	//Hard-logic so T1 doesn't break before T2 is destroyed!
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
    {
		if(BBPGetTier() == 2)
		{
			if (GetConstruction().IsPartConstructed( "t1_wall_planks" ))
			{
				if(DamageSystem.GetDamageZoneFromComponentName(this,"t1_wall_planks",dmgZone))
				{
					this.SetHealthMax(dmgZone);
				}
			}
			
			if (GetConstruction().IsPartConstructed( "t1_wall_logs_horizontal" ))
			{
				if(DamageSystem.GetDamageZoneFromComponentName(this,"t1_wall_logs_horizontal",dmgZone))
				{
					this.SetHealthMax(dmgZone);
				}
			}
			
			if (GetConstruction().IsPartConstructed( "t1_door" ))
			{
				if(DamageSystem.GetDamageZoneFromComponentName(this,"t1_door",dmgZone))
				{
					this.SetHealthMax(dmgZone);
				}
			}
		}

        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
    }
	
	////////////////////////////////////////////////////////////////////
	
	// handle rpc for both client and server
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
            case RPC_CUSTOM_DATA:
                RPC_CustomData(sender, ctx);
            break;
        }

        super.OnRPC(sender, rpc_type, ctx);
    }

    protected void RPC_CustomData(PlayerIdentity sender, ParamsReadContext ctx)
    {
        // server
        if (sender && GetGame().IsDedicatedServer())
        {
            ScriptRPC rpc = new ScriptRPC();
            rpc.Write(m_CustomName);

            rpc.Send(this, RPC_CUSTOM_DATA, true, sender); // send to requester
            return;
        }

        //client
        ctx.Read(m_CustomName);
    }

    void RequestCustomData()
    {
        // client
        if (!GetGame().IsDedicatedServer())
        {
            // check if name has already been filled
            if (m_CustomName != string.Empty)
                return;

            ScriptRPC rpc = new ScriptRPC();
            rpc.Send(this, RPC_CUSTOM_DATA, true, null); // send to server
        }
    }
	
	string returnBBP_HP()
	{
		return m_CustomName;
	}

    void SetCustomName(string name)
    {
        if (GetGame().IsDedicatedServer())
        {
            m_CustomName = name;

            ScriptRPC rpc = new ScriptRPC();
            rpc.Write(m_CustomName);

            rpc.Send(this, RPC_CUSTOM_DATA, true, null); // send to all
        }
    }
	/////////////////////
	
	bool BBP_HasDoor()
    {
        if (GetConstruction().IsPartConstructed( "t3_door" ))
		{
			return true;
		}
		
		if (GetConstruction().IsPartConstructed( "t2_door" ))
		{
			return true;
		}
		
		if (GetConstruction().IsPartConstructed( "t1_door" ))
		{
			return true;
		}
        
        return false;
    }
    
	// Prefer Expansion's own slot when attaching a new Expansion CodeLock.
	// Existing locks in Att_CombinationLock remain supported.
#ifdef EXPANSIONMODBASEBUILDING
	override bool ExpansionFindCodeLockSlot(out string slotName = "")
	{
		if (IsBBPGate())
		{
			TStringArray slots = Expansion_GetAttachmentSlots();
			if (slots && ExpansionStatic.StringArrayContainsIgnoreCase(slots, "Att_ExpansionCodeLock"))
			{
				slotName = "Att_ExpansionCodeLock";
				return true;
			}
		}

		return super.ExpansionFindCodeLockSlot(slotName);
	}
#endif

	// One lock per BBP gate; Expansion support is optional.
	ItemBase obfm_BBPGetAttachedLock()
	{
		ItemBase obfv_lock = GetCombinationLock();
		if (!obfv_lock) obfv_lock = GetCodeLock();
#ifdef EXPANSIONMODBASEBUILDING
		if (!obfv_lock) obfv_lock = ExpansionGetCodeLock();
#endif
		return obfv_lock;
	}

	bool BBP_HasLock()
	{
		return obfm_BBPGetAttachedLock() != null;
	}

	bool obfm_BBPIsSecured()
	{
		if (IsLocked()) return true;
#ifdef EXPANSIONMODBASEBUILDING
		if (ExpansionIsLocked()) return true;
#endif
		return false;
	}

	string BBP_deleteLock()
	{
		ItemBase obfv_lock = obfm_BBPGetAttachedLock();
		if (!obfv_lock) return "Paper";
		string obfv_type = obfv_lock.GetType();
		obfv_lock.Delete();
		return obfv_type;
	}

	void BBP_LockHealth()
	{
		ItemBase obfv_lock = obfm_BBPGetAttachedLock();
		if (obfv_lock) obfv_lock.SetHealth(0);
	}

    //BRO DON'T ASK...
	int BBPGetTier()
	{   
		if (GetConstruction())
		{			
			if (GetConstruction().IsPartConstructed("t3_wall_concrete_bricks") || (GetConstruction().IsPartConstructed("t3_wall_concrete_bricks_2")))
			{
				if(isBBPDoor())
				{
					if(GetConstruction().IsPartConstructed("t3_door"))
					{
						return 3;
					}
					if(GetConstruction().IsPartConstructed("t2_door"))
					{
						return 2;
					}
					if(GetConstruction().IsPartConstructed("t1_door"))
					{
						return 1;
					}
				}
				return 3;
			}
			
			if (GetConstruction().IsPartConstructed("t2_metal") || (GetConstruction().IsPartConstructed("t2_metal_2")))
			{
				if(isBBPDoor())
				{
					if(GetConstruction().IsPartConstructed("t2_door") || GetConstruction().IsPartConstructed("t3_door"))
					{
						return 2;
					}
					if(GetConstruction().IsPartConstructed("t1_door"))
					{
						return 1;
					}
				}
				return 2;
			}

			if (GetConstruction().IsPartConstructed("t1_wall_logs_horizontal") || (GetConstruction().IsPartConstructed("t1_wall_logs_horizontal_2")) ||(GetConstruction().IsPartConstructed("t1_wall_planks")))
			{
				if(isBBPDoor())
				{
					if(GetConstruction().IsPartConstructed("t2_door") || GetConstruction().IsPartConstructed("t3_door") || (GetConstruction().IsPartConstructed("t1_door")))
					{
						return 1;
					}
				}
				return 1;
			} 
			
			if (GetConstruction().IsPartConstructed("frame")) 
			{
				return 0;
			}
			
			return 69;
		}
		
		return -1;
	}
	
	override string GetDisplayName()
	{
		string itemName = super.GetDisplayName();
		
		if (BBPGetTier() == 3)
		{
			return "[T3] " + itemName;
		}
		else if (BBPGetTier() == 2)
		{
			return "[T2] " + itemName;
		}
		else if (BBPGetTier() == 1)
		{
			return "[T1] " + itemName;
		}
		else if (BBPGetTier() == 0)
		{
			return "[Frame] " + itemName;
		}
		else if (BBPGetTier() == 69)
		{
			return "[Hologram] " + itemName;
		}
		
		return itemName;
	}
	
	//BRO DON'T ASK...
	string PartGetBBP()
	{ 
		return GetDisplayName();
	}

	override bool canSnap600()
	{
		return true;
	}
	
	void DestroyClutterCutter()
	{
		if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			if ( HasClutterCutter() && m_ClutterCutter )
			{
				GetGame().ObjectDelete( m_ClutterCutter );
			}
		}
	}

	bool IsBBPGate()
	{
		return false;
	}

	bool HasClutterCutter()
	{
		return false;
	}
	
	bool HasTinyClutterCutter()
	{
		return false;
	}

	override bool IsRaidable()
	{
		return true;
	}

	override bool IsFancyBBPItem()
	{
		return true;
	}

	override int CheckGateState()
	{
		if ( !IsBBPGate() )
		{
			int state = GATE_STATE_NONE;
			return state;
		}
		else 
		{
			return super.CheckGateState();
		}
	}
	
	void CreateClutterCutter()
	{
		if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			if ( !m_ClutterCutter )
			{
				if ( HasTinyClutterCutter() )
				{
					m_ClutterCutter = GetGame().CreateObject( "ClutterCutter2x2", GetPosition(), false );
					m_ClutterCutter.SetOrientation( GetOrientation() );
				}
				if ( !HasTinyClutterCutter() )
				{
					m_ClutterCutter = GetGame().CreateObject( "ClutterCutter6x6", GetPosition(), false );
					m_ClutterCutter.SetOrientation( GetOrientation() );
				}
			}
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if (m_ClutterCutter && HasClutterCutter() && GetGame())
		{
			GetGame().ObjectDelete(m_ClutterCutter);
			m_ClutterCutter = NULL;
		}
	}
	
	override ItemBase FoldBaseBuildingObject()
	{
		ItemBase item = CreateConstructionKit_BBP();
		DestroyConstruction();
		return item;
	}
	
	ItemBase CreateConstructionKit_BBP()
	{
		ItemBase construction_kit_bbp = ItemBase.Cast( GetGame().CreateObject( GetConstructionKitType(), GetKitSpawnPositionBBP() ) );
		if ( m_ConstructionKitHealth > 0 )
		{
			construction_kit_bbp.SetHealth( m_ConstructionKitHealth );
		}
		
		return construction_kit_bbp;
	}
	
	protected vector GetKitSpawnPositionBBP()
	{
		return GetPosition();
	}
	
	//--- CONSTRUCTION KIT
	override ItemBase CreateConstructionKit()
	{
		
	}
	
	override protected vector GetKitSpawnPosition()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		vector bbp_kit_return = "0 0 0";
		if(player)
		{
			bbp_kit_return = player.GetPosition();
		}
		
		return bbp_kit_return;
	}
	
	override string GetConstructionKitType()
	{
		return "Paper";
	}
	
	string GetBBPType()
	{
		return "Paper";
	}
	
	// --- INVENTORY
	override bool CanDisplayAttachmentSlot( int slot_id )
	{
		string slot_name = InventorySlots.GetSlotName(slot_id);
		if ( slot_name == "Material_BBP_Concrete_Brick_Pile" || slot_name == "Material_Mortar" )
		{
			if(BBPGetTier() == 1 || BBPGetTier() == 2)
			{
				return false;
			}
		}
		return true;
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		bbp_config = GetDayZGame().getBBPGlobals();
		
		bool BBPCanAttachWallpaper = true;
		bool BBPCanAttachCarpet = true;
		bool BBPCanAttachPlaster = true;
		if (bbp_config)
		{
			BBPCanAttachWallpaper = bbp_config.BBP_CanAttachWallpaper;
			BBPCanAttachCarpet = bbp_config.BBP_CanAttachCarpet;
			BBPCanAttachPlaster = bbp_config.BBP_CanAttachPlaster;
		}
		
		if ( BBP_Hide )
		{
			return false;
		}
		
		if ( category_name == "Materials" )
		{
			if(BBPGetTier() == 0 || BBPGetTier() == 69)
			{
				return true;
			}
			
			else if(BBP_HasMats())
			{
				return true;
			}
			
			else if(isflat()) //floor/roof
			{
				if ( HasProperDistanceFlatBBP( "inside", player ) )
				{
					return true;
				}
			}
			
			else if (!isflat() && isSmall())
			{
				if ( HasProperDistanceBBP( "inside", player ) )
				{
					return true;
				}
			}
			
			else if (!isflat() && !isSmall())
			{
				if (HasProperDistanceBBP( "inside", player ) )
				{
					return true;
				}
			}
		}
		
		if ( category_name == "Attachments" )
		{
			if ( !HasBase() )
			{
				return false;
			}
		}
		
		if ( category_name == "Carpet" )
		{
			if ( !HasBase() || BBPCanAttachCarpet == 0)
			{
				return false;
			}
		}
		
		if ( category_name == "Plaster")
		{
			if ( !HasBase() || BBPCanAttachPlaster == 0)
			{
				return false;
			}
		}
		
		if ( category_name == "WallPaper" )
		{
			if ( !HasBase() || BBPCanAttachWallpaper == 0)
			{
				return false;
			}
		}
		
		//wtf end
		
		if(isflat()) //floor/roof
		{
			if ( !HasProperDistanceFlatBBP( "inside", player ) )
			{
				return false;
			}
		}
		
		if (!isflat() && isSmall())
		{
			if ( !HasProperDistanceBBP( "inside", player ) )
			{
				return false;
			}
		}
		
		if (!isflat() && !isSmall())
		{
			if (!HasProperDistanceBBP( "inside", player ) )
			{
				return false;
			}
		}
		
		return true;
	}
	
	bool BBP_HasMats()
    {
		int slot_id;
		int slot_id2;
		int slot_id3;
		int slot_id4;
		int slot_id5;
		int slot_id6;
		slot_id = InventorySlots.GetSlotIdFromString("Material_Nails");
		slot_id2 = InventorySlots.GetSlotIdFromString("Material_FPole_WoodenLog2");
		slot_id3 = InventorySlots.GetSlotIdFromString("Material_WoodenPlanks");
		slot_id4 = InventorySlots.GetSlotIdFromString("Material_BBP_Concrete_Brick_Pile");
		slot_id5 = InventorySlots.GetSlotIdFromString("Material_Mortar");
		slot_id6 = InventorySlots.GetSlotIdFromString("Material_MetalSheets");
		ItemBase bbpnails = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		ItemBase bbplogs = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		ItemBase bbpplanks = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		ItemBase bbpbricks = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		ItemBase bbpmortar = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		ItemBase bbpsheet = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		
		if ( bbpnails )
		{
			return true;
		}
		else if ( bbplogs )
		{
			return true;
		}
		else if ( bbpplanks )
		{
			return true;
		}
		else if ( bbpbricks )
		{
			return true;
		}
		else if ( bbpmortar )
		{
			return true;
		}
		else if ( bbpsheet )
		{
			return true;
		}
		
		return false;
    }
	
	//--- ACTION CONDITIONS
	override bool IsPlayerInside( PlayerBase player, string selection )
	{
		if(BBPGetTier() == 0 || BBPGetTier() == 69)
		{
			return true;
		}
		
		if(BBP_HasMats())
		{
			return true;
		}
		
		if(isflat()) //floor/roof
		{
			if ( HasProperDistanceFlatBBP( "inside", player ) )
			{
				return true;
			}
			return false;
		}
		
		if (!isflat() && isSmall()) //small walls
		{
			if ( HasProperDistanceBBP( "inside", player ) )
			{
				return true;
			}
			return false;
		}
		
		if (!isflat() && !isSmall()) //large walls
		{
			if ( HasProperDistanceBBP( "inside", player ) )
			{
				return true;
			}
			return false;
		}
		
		return true;
	}
	
	override bool NameOverride(out string output)
	{
		//if ( m_GateState != GATE_STATE_NONE )
		//{
			//output = "#str_cfgvehicles_construction_part_gate";  //changes object displayed name if in 'gate' state
			//output.ToUpper();
			//return true;
		//}
		return false;
	}
	
	override void OnWorkStart()
	{
		SetPilotLight(true);
		m_BBP_IsSwichedOn = true;
	}
	
	override void OnWorkStop()
	{
		SetPilotLight(false);
		m_BBP_IsSwichedOn = false;
	}
	
	//! Energy manager: Checks if the device can be switched ON
	bool CanSwitchOn()
	{
		if ( !IsSwitchedOn() )
		{
			return true;
		}
		
		return false;
	}
	
	//! Energy manager: Checks if the device can be switched OFF
	bool CanSwitchOff()
	{
		if ( IsPassive() )
		{
			return false;
		}
		
		return IsSwitchedOn();
	}
	
	//! Energy manager: Returns state of the switch. Whenever the device is working or not does not matter. Use IsWorking() to account for that as well.
	bool IsSwitchedOn()
	{
		return m_BBP_IsSwichedOn;
	}
	
	//! Energy manager: Returns true if this device is set to be passive. False if otherwise.
	bool IsPassive()
	{
		if ( !m_BBP_IsSwichedOn )
		{
			return true;
		}

		return false;
	}
	
	bool IsFlashlightAttached()
	{
		int slot_id;
		slot_id = InventorySlots.GetSlotIdFromString("Wall_Flashlight");
		ItemBase wallflashlight = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		if ( wallflashlight )
		{
			return true;
		}
		return false;
	}
	
	//--- ATTACHMENT & CONDITIONS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		//Remove super
		//if ( !super.CanReceiveAttachment(attachment, slotId) )
		//	return false;
		
		//manage action initiator (AT_ATTACH_TO_CONSTRUCTION)
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if ( player )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				
				//reset action initiator
				construction_action_data.SetActionInitiator( NULL );				
			}
		}
		
		//Remove conditions
		//conditions
		//if ( attachment.Type() != ATTACHMENT_WOODEN_LOG )
		//{
		//	if ( !HasBase() )
		//	{
		//		return false;
		//	}
		//}
		
		if ( attachment.IsInherited( ATTACHMENT_COMBINATION_LOCK ) || attachment.IsInherited( ATTACHMENT_CODE_LOCK ) )
		{
			return HasFullyConstructedGate() && !BBP_HasLock() && !IsOpened();
		}
#ifdef EXPANSIONMODBASEBUILDING
		if ( attachment.IsInherited( ExpansionCodeLock ) )
		{
			return HasFullyConstructedGate() && !BBP_HasLock() && !IsOpened();
		}
#endif
		
		if ( attachment.Type() == ATTACHMENT_FLASHLIGHT ) 
		{
			if ( !attachment.GetCompEM().CanWork() )
			{
				return false;
			}
		}
		
		//Remove GateAttachmentConditions check
		//if ( !GateAttachmentConditions(slotId) )
		//	return false;
		
		return true;
	}
	
	//refresh visual/physics state
	void Refresh()
	{
		UpdateVisuals();
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdatePhysics, 200, false );
		RefreshAttachements();
	}
	
	void RefreshAttachements()
	{

	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		//super.EEItemAttached(item, slot_name);
		
		/* if ( !IsFlashlightAttached() || !IsSwitchedOn() )
		{
			SetPilotLight(false);
		}
		
		if ( item.IsKindOf ( "Flashlight" ) ) 
		{
			if ( item.GetCompEM().IsSwitchedOn() ) 
			{
				item.GetCompEM().SwitchOff();
			}
		}
		
		if ( item.IsKindOf ( "XmasLights" ) ) 
		{
			SetAnimationPhase( "Xlights", 0 );
			SetAnimationPhase( "Xlights_glass_r", 0 );
			SetAnimationPhase( "Xlights_glass_g", 0 );
			SetAnimationPhase( "Xlights_glass_b", 0 );
			SetAnimationPhase( "Xlights_glass_y", 0 );
			
			XmasLights xlights = XmasLights.Cast( item );
			xlights.AttachToObject( this );
			
			if ( !IsFlashlightAttached() || !IsSwitchedOn() )
			{
				SetPilotLight(false);
			}
		} */
		
		CheckForHybridAttachments( item, slot_name );
#ifdef EXPANSIONMODBASEBUILDING
		if (item && item.IsInherited(ExpansionCodeLock))
		{
			Expansion_RegisterLockRPCs();
		}
#endif
		UpdateVisuals();
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		UpdateVisuals();
	}
	
	override protected void OnSetSlotLock( int slotId, bool locked, bool was_locked )
	{
		string slot_name = InventorySlots.GetSlotName( slotId );
		bsbDebugPrint( "inv: OnSetSlotLock " + GetDebugName( this ) + " slot=" + slot_name + " locked=" + locked + " was_locked=" + was_locked );

		UpdateAttachmentVisuals( slot_name, locked );
		//UpdateAttachmentPhysics( slot_name, locked );
	}

	override void OnPartBuiltServer( notnull Man player, string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//check base state
		if ( constrution_part.IsBase() )
		{
			SetBaseState( true );
			
			//hide hologram
			SetAnimationPhase( "Hologram", 		1 );
			
			//spawn toolkit
			//CreateConstructionKit();
		}
		
		/* //check gate state
		if ( constrution_part.IsGate() )
		{
			SetGateState( true );
		}
		
		//register constructed parts for synchronization
		RegisterPartForSync( constrution_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( constrution_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();
		
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			SetPartFromSyncData(constrution_part); // server part of sync, client will be synced from SetPartsFromSyncData
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//set gate state
		if( IsBBPGate() )
		{
			SetGateState( CheckGateState() );
		}
		
		//drop attachments without carrier part
		//if (constrution_part.IsGate())
			//GateAttachmentsSanityCheck();
		
		//update visuals (server)
		UpdateVisuals(); */

		super.OnPartBuiltServer( player, part_name, action_id );
	}
	
	override void OnPartDismantledServer( notnull Man player, string part_name, int action_id )
	{
		//super.OnPartDismantledServer( player, part_name, action_id );

		bsbDebugPrint("[bsb] " + GetDebugName(this) + " OnPartDismantledServer " + part_name);
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//register constructed parts for synchronization
		UnregisterPartForSync( constrution_part.GetId() );
		
		//register action that was performed on part
		RegisterActionForSync( constrution_part.GetId(), action_id );
		
		//synchronize
		SynchronizeBaseState();

		// server part of sync, client will be synced from SetPartsFromSyncData
		SetPartFromSyncData( constrution_part );
		
		//reset action sync data
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
		
		//check base state
		if ( constrution_part.IsBase() )
		{
			//Destroy construction
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( DestroyConstruction, 200, false, this );
			
			//spawn toolkit
			//CreateConstructionKit();
		}
		
		//set gate state
		if( IsBBPGate() )
		{
			#ifdef EXPANSIONMODBASEBUILDING
			ExpansionCodeLock codelock_exp = ExpansionGetCodeLock();
			if ( codelock_exp )
			{
				codelock_exp.UnlockServer( player, this );
			}
			#endif
			
			CombinationLock combination_lock = CombinationLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
			if(combination_lock)
			{
				combination_lock.UnlockOnServer( player , this );
			}
			
			DigitalCodeLock obfv_codeLock = GetCodeLock();
			if (obfv_codeLock) obfv_codeLock.UnlockOnServer(this);
			SetGateState( CheckGateState() );
		}

		//update visuals (server)
		UpdateVisuals();
	}

	override void OnPartDestroyedServer( Man player, string part_name, int action_id, bool destroyed_by_connected_part = false )
	{
		super.OnPartDestroyedServer( player, part_name, action_id, destroyed_by_connected_part );

		if( IsBBPGate() )
		{
			#ifdef EXPANSIONMODBASEBUILDING
			ExpansionCodeLock codelock_exp = ExpansionGetCodeLock();
			if ( codelock_exp )
			{
				codelock_exp.UnlockServer( player, this );
			}
			#endif
			
			CombinationLock combination_lock = CombinationLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
			if(combination_lock)
			{
				combination_lock.UnlockOnServer( player , this );
			}
			
			DigitalCodeLock obfv_codeLock = GetCodeLock();
			if (obfv_codeLock) obfv_codeLock.UnlockOnServer(this);
			SetGateState( CheckGateState() );
		}
	}
	
	override void AfterStoreLoad()
	{
		// BBP floor/wall parts lack the vanilla Fence gate part.
		// Do not invoke Fence.AfterStoreLoad() without a gate-specific migration.
		bbp_config = GetDayZGame().getBBPGlobals();
		if (bbp_config && bbp_config.BBP_SetInfiniteLifetime)
		{
			this.SetLifetime(3888000);
		}

		//check base state
		if ( !HasBase() )
		{
			//show hologram
			SetAnimationPhase( "Hologram", 0 );
		}
		
		//update server data
		SetPartsFromSyncData();
		
		//set base state
		ConstructionPart construction_part = GetConstruction().GetBaseConstructionPart();
		if (construction_part) SetBaseState( construction_part.IsBuilt() );
		
		//set gate state
		if(IsBBPGate())
		{
			//ConstructionPart gate_part = GetConstruction().GetGateConstructionPart();
			//SetGateState( gate_part.IsBuilt() );
			//SetGateState( false );
			//set gate state
			ConstructionPart gate_part = GetConstruction().GetGateConstructionPart();
			SetGateState( CheckGateState() );
		}
		
		//update gate state visual
		if ( IsOpened() )
		{
			OpenFence();
		}
		
		UpdateVisuals();
		
		bsbDebugPrint("[bsb] AfterStoreLoad - build=" + "false" + " opened=" + IsOpened());
		
		if ( !m_ClutterCutter && HasClutterCutter() )
		{		
			CreateClutterCutter();
		}

		//synchronize after load
		SynchronizeBaseState();
	}

	/*override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		//write
		ctx.Write( m_HasGate );
		ctx.Write( m_IsOpened );
		ctx.Write( m_DismantleDisabled );
		bsbDebugPrint("[bsb] OnStoreSave - build=" + m_HasGate + " opened=" + m_IsOpened);
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		//--- Fence data ---
		//has gate
		if ( !ctx.Read( m_HasGate ) )
		{
			m_HasGate = false;
			return false;
		}
		
		//is opened
		if ( !ctx.Read( m_IsOpened ) )
		{
			m_IsOpened = false;
			return false;
		}

		if ( !ctx.Read( m_DismantleDisabled ) )
		{
			m_DismantleDisabled = false;
			return false;
		}
		
		bsbDebugPrint("[bsb] OnStoreLoad - build=" + m_HasGate + " opened=" + m_IsOpened);
		//---
		
		return true;
	}*/
	
	// Use Fence's server-side rotation, opened-state and network synchronization.
	// Only the server-validated trusted-door action may call these helpers.
	void BBPTrustedOpenDoor()
	{
		if (!GetGame().IsServer() || !IsBBPGate() || IsOpened()) return;
		OpenFence();
	}

	void BBPTrustedCloseDoor()
	{
		if (!GetGame().IsServer() || !IsBBPGate() || !IsOpened()) return;
		CloseFence();
	}

	// Keep Expansion gates secured even when vanilla Fence.IsLocked() sees no vanilla lock.
	override bool CanOpenFence()
	{
		if (!super.CanOpenFence()) return false;
		return !obfm_BBPIsSecured();
	}

	override void OpenFence()
	{	
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateOpenStart();
		}
		
		//light off
		if ( !IsFlashlightAttached() || !IsSwitchedOn() )
		{
			SetPilotLight(false);
		}
	}

	override void CloseFence()
	{
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateCloseStart();
			
			//add check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceClosed, 0, true );
		}
		
		//light off
		if ( !IsFlashlightAttached() || !IsSwitchedOn() )
		{
			SetPilotLight(false);
		}
	}

	override void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Wall_Interact_Rotate" ) == 0 )			//animation closed
		{
			//play sound
			if ( this ) SoundGateCloseEnd();
			
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}

	override void CreateAreaDamage( string slot_name, float rotation_angle = 0 )
    {
        if ( IsOpened() )
        {
            rotation_angle = 0;
        }
        
        super.CreateAreaDamage( slot_name, rotation_angle );
    }
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFoldBaseBuildingObject);
		AddAction(obfc_ActionBBPDigitalCodeLock);
		AddAction(ActionBBPTrustedOpen);
		///////////////////////////////////////
		RemoveAction(ActionDialCombinationLockOnTarget);
		RemoveAction(ActionNextCombinationLockDialOnTarget);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
		//RemoveAction(ActionDestroyPart);
		//RemoveAction(ActionDismantlePart);
	}
};

class BBP_BASE_LIGHT extends BBP_BASE {};
