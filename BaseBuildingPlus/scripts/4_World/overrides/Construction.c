modded class Construction
{	
	override bool CanBuildPart( string part_name, ItemBase tool, bool use_tool )
	{
		if ( tool && tool.isBBPAdminTool() && !IsPartConstructed( part_name ) && HasRequiredPart( part_name ) && !HasConflictPart( part_name ) )
		{
			return true;
		}
		
		return super.CanBuildPart(part_name,tool,use_tool);
	}
	
	void BBP_AdminHatchetLockLockableSlots(string part_name, bool repairing = false)
	{
		string main_part_name = GetConstructionPart(part_name).GetMainPartName();
		string cfg_path = "cfgVehicles" + " " + GetParent().GetType() + " "+ "Construction" + " " + main_part_name + " " + part_name + " " + "Materials";
		
		if(GetGame().ConfigIsExisting(cfg_path))
		{
			int	child_count = GetGame().ConfigGetChildrenCount(cfg_path);
			
			for(int i = 0; i < child_count; i++)
			{
				string child_name;
				GetGame().ConfigGetChildName(cfg_path, i, child_name);
				
				string config_path;
				string slot_name;
				config_path = cfg_path + " " + child_name + " " + "slot_name";
				GetGame().ConfigGetText(config_path, slot_name);
				config_path = cfg_path + " " + child_name + " " + "lockable";
				bool lockable = GetGame().ConfigGetInt(config_path);
				
				ItemBase attachment = ItemBase.Cast(GetParent().FindAttachmentBySlotName(slot_name));
				if(attachment && lockable)
				{
					InventoryLocation inventory_location = new InventoryLocation;
					attachment.GetInventory().GetCurrentInventoryLocation(inventory_location);
			
					GetParent().GetInventory().SetSlotLock(inventory_location.GetSlot(), true);
				}
			}
		}
	};

	void AdminBuildPartServer( notnull Man player, string part_name, int action_id )
	{
		string damage_zone;
		if(DamageSystem.GetDamageZoneFromComponentName(GetParent(),part_name,damage_zone))
		{		
			GetParent().SetHealthMax(damage_zone);
		}
		BBP_AdminHatchetLockLockableSlots(part_name);
		GetParent().OnPartBuiltServer(player, part_name, action_id);
	}

	//============================================
	// Collision check
	//============================================
	override bool IsCollidingEx( CollisionCheckData check_data )
    {
        if (GetParent() && GetParent().IsInherited(BBP_BASE)) return false;
        return super.IsCollidingEx(check_data);
    }
	
	override void DropNonUsableMaterialsServer( Man player, string part_name )
	{
		ConstructionPart construction_part = GetConstructionPart( part_name );
		
		string cfg_path = "cfgVehicles" + " " + GetParent().GetType() + " " + "Construction" + " " + construction_part.GetMainPartName() + " " + construction_part.GetPartName() + " " + "platform_support";
		string platform_support;
		
		if ( GetGame().ConfigIsExisting( cfg_path ) )
		{		
			GetGame().ConfigGetText( cfg_path, platform_support );
		}
		
		if ( platform_support.Length() > 0 || construction_part.IsBase() )
		{
			string at_cfg_path = "cfgVehicles" + " " + GetParent().GetType() + " "+ "GUIInventoryAttachmentsProps";
			
			if ( GetGame().ConfigIsExisting( at_cfg_path ) )
			{
				int	child_count = GetGame().ConfigGetChildrenCount( at_cfg_path );
				
				for ( int i = 0; i < child_count; i++ )
				{
					string child_name;
					GetGame().ConfigGetChildName( at_cfg_path, i, child_name );
					child_name.ToLower();
					
					if ( child_name.Contains( platform_support ) )
					{
						array<string> attachment_slots = new array<string>;
						GetGame().ConfigGetTextArray( at_cfg_path + " " + child_name + " " + "attachmentSlots", attachment_slots );
						
						for ( int j = 0; j < attachment_slots.Count(); ++j )
						{
							//get material
							ItemBase attachment = ItemBase.Cast( GetParent().FindAttachmentBySlotName( attachment_slots.Get( j ) ) );
							
							//material still attached
							if ( attachment )
							{
								InventoryLocation inventory_location = new InventoryLocation;
								attachment.GetInventory().GetCurrentInventoryLocation( inventory_location );
								bsbDebugPrint("[bsb] " + Object.GetDebugName(GetParent()) + " DropNonUsableMaterials UNlocking slot=" + inventory_location.GetSlot());
								
								//unlock slot
								GetParent().GetInventory().SetSlotLock( inventory_location.GetSlot() , false );
								
								EntityAI parent = GetParent();
								if (!parent)
									parent = player;
								
								int quantity_max = attachment.GetTargetQuantityMax(-1);
								InventoryLocation dst = new InventoryLocation;
								vector mat[4];
								attachment.GetTransform(mat);
								
								if ( parent.MemoryPointExists("" + part_name + "_materials") )
								{
									vector destination = player.GetPosition();
									//destination = GetGame().ObjectModelToWorld(parent,destination);
									float health = attachment.GetHealth("","Health");
									float quantity = attachment.GetQuantity() - 1;
									if (quantity < 1.0)
										quantity = 1.0;
									float dir[4];
									inventory_location.GetDir(dir);
									dst.SetGroundEx(attachment,destination,dir);
									//Print(dst.DumpToString());
									MiscGameplayFunctions.CreateItemBasePiles(attachment.GetType(),destination,quantity,health,true);
									attachment.AddQuantity( -quantity );
								}
								else
								{
									dst.SetGround(attachment,mat);
									
									for ( int k = attachment.GetQuantity(); k > quantity_max;  )
									{
										Object o = parent.GetInventory().LocationCreateEntity( dst, attachment.GetType(), ECE_PLACE_ON_SURFACE, RF_DEFAULT );
										ItemBase new_item = ItemBase.Cast( o );
										
										if( new_item )
										{
											MiscGameplayFunctions.TransferItemProperties( attachment, new_item );
											attachment.AddQuantity( -quantity_max );
											new_item.SetQuantity( quantity_max );
										}
										k -= quantity_max;
									}
								}
								
								//drop
								if (attachment.GetQuantity() > 0)
								{
									if ( GetGame().IsMultiplayer() )
									{
										parent.ServerTakeToDst( inventory_location, dst );
									}
									else
									{
										parent.LocalTakeToDst( inventory_location, dst );
									}
								}
								else
								{
									attachment.Delete();
								}
							}
						}
					}
				}
			}
		}
	}
}

modded class StaticConstructionMethods
{
	//! spawns material from any construction; 'player' parameter optional
	override static void SpawnConstructionMaterialPiles(notnull EntityAI entity, Man player, string cfg_path, string main_part_name, string damagezone_name = "", bool is_base = false )
	{
		int	child_count = GetGame().ConfigGetChildrenCount( cfg_path );
		
		for ( int i = 0; i < child_count; i++ )
		{
			string child_name;
			GetGame().ConfigGetChildName( cfg_path, i, child_name );
			
			//get type, quantity from material
			string config_path;
			string type;
			string slot_name;
			config_path = cfg_path + " " + child_name + " " + "type";
			GetGame().ConfigGetText( config_path, type );
			config_path = cfg_path + " " + child_name + " " + "slot_name";
			GetGame().ConfigGetText( config_path, slot_name );
			config_path = cfg_path + " " + child_name + " " + "quantity";
			float quantity = GetGame().ConfigGetFloat( config_path );
			config_path = cfg_path + " " + child_name + " " + "lockable";
			bool lockable = GetGame().ConfigGetInt( config_path );
			
			//receive material quantity
			ItemBase attachment = ItemBase.Cast( entity.FindAttachmentBySlotName( slot_name ) );
			int slot_id;
			
			//material still attached
			if ( lockable )			//if lockable 
			{
				if ( attachment )
				{
					InventoryLocation src = new InventoryLocation;
					attachment.GetInventory().GetCurrentInventoryLocation( src );
					bsbDebugPrint("[bsb] " + Object.GetDebugName( entity) + " DropNonUsableMaterials UNlocking slot=" + src.GetSlot() );
					entity.GetInventory().SetSlotLock( src.GetSlot() , false );
					
					//detach if base
					if ( is_base )
					{
						if ( GetGame().IsMultiplayer() && player )
						{
							InventoryLocation dst = new InventoryLocation;
							GameInventory.SetGroundPosByOwner( player, src.GetItem(), dst );
							player.ServerTakeToDst( src, dst );
						}
						else
						{
							entity.GetInventory().DropEntity( InventoryMode.PREDICTIVE, entity, attachment );
						}
					}
				}
			}
			else
			{
				float pile_health;
				float qty_coef;
				if ( player )
				{
					vector destination = player.GetPosition();

					//pile_health = GameConstants.DAMAGE_WORN_VALUE * MiscGameplayFunctions.GetTypeMaxGlobalHealth(type);
					pile_health = entity.GetHealth01(damagezone_name,"Health") * MiscGameplayFunctions.GetTypeMaxGlobalHealth(type);
					qty_coef =  1 - (entity.GetHealthLevel(damagezone_name) * Construction.DECONSTURCT_MATERIAL_LOSS) - Construction.DECONSTURCT_MATERIAL_LOSS;
					quantity *= qty_coef;
					quantity = Math.Max(Math.Floor(quantity),1);
					MiscGameplayFunctions.CreateItemBasePiles(type,destination,quantity,pile_health,true);
				}
			}
		}
	}
}
