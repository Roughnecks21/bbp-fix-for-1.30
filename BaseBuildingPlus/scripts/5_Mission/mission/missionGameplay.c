modded class MissionGameplay
{
	// UIs
	//ref WB_Spawn_Item m_WB_Spawn_Item;
	protected Widget m_BBP_Snap_On;
	protected Widget m_BBP_Snap_Off;
	ref RotationMenu m_RotationMenu;
	
	void ~MissionGameplay()
    {
        delete m_BBP_Snap_On;
		delete m_BBP_Snap_Off;
    }

	void MissionGameplay()
    {
		//m_WB_Spawn_Item = new WB_Spawn_Item();
		m_RotationMenu = NULL;
	}
	
	override void OnMissionStart()
    {
        super.OnMissionStart();
        m_BBP_Snap_On = GetGame().GetWorkspace().CreateWidgets("BaseBuildingPlus/GUI/layouts/snap_enabled.layout");
		m_BBP_Snap_Off = GetGame().GetWorkspace().CreateWidgets("BaseBuildingPlus/GUI/layouts/snap_disabled.layout");
    }

	void BBPsetSize(PlayerBase playerPB, int a)
	{
		GetRPCManager().SendRPC( "BaseBuildingPlus", "BBP_SYNC_SIZES", new Param2< PlayerBase, int > ( playerPB, a ) ); 
		playerPB.BBPsetSize(a); 
	}

	override void OnUpdate(float timeslice)
    {
        if (!m_BBP_Snap_On || !m_BBP_Snap_Off)
        {
            super.OnUpdate(timeslice);
            return;
        }
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;

		if (player)
		{
			if (player.GetHumanInventory())
			{
				if (player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}
		
		//bro wtf is this ):
		if (iteminhands)
		{
			if (iteminhands && iteminhands.isBBP_Object())
			{			
				if (snappingEnabled)
				{
					m_BBP_Snap_On.Show(true);
					m_BBP_Snap_Off.Show(false);
				}
				if (!snappingEnabled)
				{
					m_BBP_Snap_On.Show(false);
					m_BBP_Snap_Off.Show(true);
				}
			}
		}
		
		if (!iteminhands || iteminhands && !iteminhands.isBBP_Object())
		{
			BBP_Rotate = false;
			BBP_Freeze = false;
			//snappingEnabled = false;
			//snappingEnabled_By_Looking = false;
			AUTO_BBP_SNAPPING_OBJECT = NULL;
			m_BBP_Snap_On.Show(false);
			m_BBP_Snap_Off.Show(false);
			holoOffset = 0;
			holoOffset_1 = 0;
			holoOffset_2 = 0;
			if (m_RotationMenu)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_RotationMenu);
				delete m_RotationMenu;
			}
		}

        // Input Declarations
        UAInput EscapeKeyInput = GetUApi().GetInputByName("UAUIBack");

		//TODO CLEAN UP MESS =D
		if (GetGame().GetInput().LocalPress("UACycleSize", true))
		{
			if (player.GetHologramLocal())
			{
				//bwall
				if (BBP_CYCLE_SIZE == 1)
				{
					BBP_CYCLE_SIZE = 2;
					//GetRPCManager().SendRPC("BaseBuildingPlus", "BBP_SYNC_SIZES", new Param1< int >( BBP_CYCLE_SIZE ));
					BBPsetSize(player,BBP_CYCLE_SIZE);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
				
				//swall
				else if (BBP_CYCLE_SIZE == 2)
				{
					BBP_CYCLE_SIZE = 1;
					//GetRPCManager().SendRPC("BaseBuildingPlus", "BBP_SYNC_SIZES", new Param1< int >( BBP_CYCLE_SIZE ));
					BBPsetSize(player,BBP_CYCLE_SIZE);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
				}
			}
		}

		if (GetGame().GetInput().LocalPress("UABBPRotate", true)) //snap by looking
		{		
			if (iteminhands && iteminhands.isBBP_Object())
			{
				if (!m_RotationMenu )
				{
					m_RotationMenu = new RotationMenu;
					GetGame().GetUIManager().ShowScriptedMenu( m_RotationMenu, NULL );
					//snappingEnabled_By_Looking = false;
				}
			}
		}
				
		if (GetGame().GetInput().LocalPress("UASnapLook", true)) //snap by looking
		{
			if (iteminhands)
			{
				if (iteminhands && iteminhands.canSnapBBP() || iteminhands.canSnapFloorBBP() || iteminhands.canSnapPillarBBP())
				{
					//ENABLE WITH AUTO ROTATION
					if (!snappingEnabled_By_Looking && !snappingEnabled)
					{
						snappingEnabled_By_Looking = true;
						snappingEnabled = true;
						//HERE UI DISPLAY ROTATION DISABLED
					}

					//DISABLE
					else
					{
						snappingEnabled_By_Looking = false;
						BBP_Rotate = false;
						snappingEnabled = false;
						AUTO_BBP_SNAPPING_OBJECT = NULL;
					}
				}
			}
        }

		if(snappingEnabled_By_Looking && !BBP_Freeze)
		{
			if (iteminhands)
			{
				if (iteminhands && iteminhands.canSnapBBP() || iteminhands.canSnapFloorBBP() || iteminhands.canSnapPillarBBP())
				{
					if (BBP_getObjectAtCrosshair())
					{
						if (BBP_getObjectAtCrosshair().IsInherited(BBP_BASE))
						{
							BBP_SelectObject();
						}
					}
				}
			}
		}

		if (snappingEnabled_By_Looking && !BBP_Rotate)
		{
			if (GetGame().GetInput().LocalPress("UAPrevSnap", true)) //prev snap point
			{
				if (iteminhands)
				{
					if (iteminhands && iteminhands.canSnap150())
					{
						if (iteminhands && iteminhands.canSnapBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevWall_150();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlat_150();
							}
						}
						if (iteminhands && iteminhands.canSnapFloorBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlatWall_150();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlatFloor_150();
							}
						}
					}
					if (iteminhands && iteminhands.canSnap600())
					{
						if (iteminhands && iteminhands.canSnapBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevWall_600();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlat_600();
							}
						}
						if (iteminhands && iteminhands.canSnapFloorBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingPrevFlatWall_600();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingPrevFlatFloor_600();
							}
						}
						if (iteminhands && iteminhands.canSnapPillarBBP())
						{
							cycleSnappingPrevPillar();
						}
					}
				}
			}

			if (GetGame().GetInput().LocalPress("UANextSnap", true)) //next snap point		
			{
				if (iteminhands)
				{
					if (iteminhands && iteminhands.canSnap150())
					{
						if (iteminhands && iteminhands.canSnapBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextWall_150();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlat_150();
							}
						}
						if (iteminhands && iteminhands.canSnapFloorBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlatWall_150();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlatFloor_150();
							}
						}
					}
					if (iteminhands && iteminhands.canSnap600())
					{
						if (iteminhands && iteminhands.canSnapBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextWall_600();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlat_600();
							}
						}
						if (iteminhands && iteminhands.canSnapFloorBBP())
						{
							if (BBP_SNAPPING_OBJECT && !BBP_SNAPPING_OBJECT.isflat())
							{
								cycleSnappingNextFlatWall_600();
							}
							if (BBP_SNAPPING_OBJECT && BBP_SNAPPING_OBJECT.isflat()) 
							{
								cycleSnappingNextFlatFloor_600();
							}
						}
						if (iteminhands && iteminhands.canSnapPillarBBP())
						{
							cycleSnappingNextPillar();
						}
					}
				}
			}
		}
		
		//toggle Display of BBP Inventory
		if (GetGame().GetInput().LocalPress("UABBPTogInv", true))
		{
			if (BBP_Hide)
			{
				BBP_Hide = false;
			}
			else if (!BBP_Hide)
			{
				BBP_Hide = true;
			}
		/* BBPConfig bbp_config = GetDayZGame().getBBPGlobals();
			if (bbp_config)
			{
				bool BBPInventoryToggle = bbp_config.BBP_InventoryToggle; //player now has to keybind it, so going to disable this atm
			}
			if ( BBPInventoryToggle )
			{
				if (BBP_Hide)
				{
					BBP_Hide = false;
				}
				else if (!BBP_Hide)
				{
					BBP_Hide = true;
				}
			}
		} */
		}	
		super.OnUpdate(timeslice);
	}
	
	override void OnKeyPress(int key)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        ItemBase item_in_hands;
        if (player && player.GetHumanInventory()) item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
		
		super.OnKeyPress(key);

		if (key == KeyCode.KC_ESCAPE)
		{
			if (m_RotationMenu)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_RotationMenu);
				delete m_RotationMenu;
			}
		}
		
		//move hologram  up and down
		if (key == KeyCode.KC_PRIOR) //PageUp
		{
			BBPConfig bbp_config2 = GetDayZGame().getBBPGlobals();
			if (bbp_config2)
			{
				bool CanRaiseAndLowerHologram = bbp_config2.BBP_CanRaiseAndLowerHologram;
			}
			if ( CanRaiseAndLowerHologram )
			{
				if(BBP_For_Back_)
				{
					if (item_in_hands && item_in_hands.isBBP_Object())
					{
						holoOffset = holoOffset + holoMove;
					}
				}
				if(BBP_Up_Down_)
				{
					if (item_in_hands && item_in_hands.isBBP_Object())
					{
						holoOffset_1 = holoOffset_1 + holoMove;
					}
				}
				if(BBP_Left_Right_)
				{
					if (item_in_hands && item_in_hands.isBBP_Object())
					{
						holoOffset_2 = holoOffset_2 + holoMove;
					}
				}
			}
				
        }
		
		if (key == KeyCode.KC_NEXT) //PageDown
		{
			BBPConfig bbp_config3 = GetDayZGame().getBBPGlobals();
			if (bbp_config3)
			{
				bool CanRaiseAndLowerHologram2 = bbp_config3.BBP_CanRaiseAndLowerHologram;
			}
			if ( CanRaiseAndLowerHologram2 )
			{
				if(BBP_For_Back_)
				{
					if (item_in_hands && item_in_hands.isBBP_Object())
					{
						holoOffset = holoOffset - holoMove;
					}
				}
				if(BBP_Up_Down_)
				{
					if (item_in_hands && item_in_hands.isBBP_Object())
					{
						holoOffset_1 = holoOffset_1 - holoMove;
					}
				}
				if(BBP_Left_Right_)
				{
					if (item_in_hands && item_in_hands.isBBP_Object())
					{
						holoOffset_2 = holoOffset_2 - holoMove;
					}
				}
			}
        }
	}

	// HUD Control
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    void ShowHUD(bool state)
    {
        GetHud().Show(state);
    }
}
