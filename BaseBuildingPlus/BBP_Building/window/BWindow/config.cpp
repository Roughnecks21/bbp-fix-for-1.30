class CfgPatches
{
	class BaseBuildingPlus_bWindow
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"BaseBuildingPlus"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BBP_KIT_BASE;
	class BBP_DOOR_BASE;
	class BBP_Window_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(Large/Small) Window Kit";
		descriptionShort="Press the left arrow key to cycle between sizes.";
		model="\BaseBuildingPlus\models\construction_kit\BBP_T1_ConstructionKit.p3d";
		rotationFlags=0;
		isMeleeWeapon=0;
		weight=300;
		absorbency=0;
		itemSize[]={4,2};
		lootCategory="Materials";
		reversed=0;
		itemBehaviour=2;
	};
	class BBP_BWindow_Hologram: Inventory_Base
	{
		scope=2;
		displayName="T1 Door Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\window\BWindow\Proxies\proxy_window_frame_hologram_placing.p3d";
		overrideDrawArea="3.0";
		itemBehaviour=2;
		attachments[]={};
		carveNavmesh=1;
		lootCategory="Tents";
		placement="ForceSlopeOnTerrain";
		physLayer="item_large";
		rotationFlags=2;
		class GUIInventoryAttachmentsProps
		{
		};
	};
	class BBP_BWindow: BBP_DOOR_BASE
	{
		scope=2;
		displayName="Large Window";
		descriptionShort="Window";
		model="\BaseBuildingPlus\BBP_Building\window\BWindow\BBP_BWindow.p3d";
		attachments[]=
		{
			"BBP_Wallpaper",
			"Wall_BarbedWire_1",
			"Wall_BarbedWire_2",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Lights",
			"Wall_Camonet",
			"Wall_Flashlight",
			"Att_CombinationLock",
			"Att_CodeLock",
			"Att_ExpansionCodeLock",
			"Material_Nails",
			"Material_FPole_WoodenLog2",
			"Material_WoodenPlanks",
			"Material_MetalSheets",
			"Material_Wallpaper_01",
			"Material_Wallpaper_02",
			"Material_Wallpaper_03",
			"Material_Wallpaper_04",
			"Material_Wallpaper_05",
			"Material_Wallpaper_06",
			"Material_Wallpaper_07",
			"Material_Wallpaper_08"
		};
		hybridAttachments[]=
		{
			"Wall_BarbedWire_1",
			"Wall_BarbedWire_2"
		};
		mountables[]=
		{
			"Wall_BarbedWire_1",
			"Wall_BarbedWire_2"
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name="Attachments";
				description="";
				attachmentSlots[]=
				{
					"Wall_BarbedWire_1",
					"Wall_BarbedWire_2",
					"Wall_Camonet",
					"Att_CombinationLock",
			"Att_CodeLock",
			"Att_ExpansionCodeLock"
				};
				icon="cat_bb_attachments";
				selection="wall_build";
			};
			class Materials
			{
				name="Materials";
				description="";
				attachmentSlots[]=
				{
					"Material_BBP_Concrete_Brick_Pile",
					"Material_Mortar",
					"Material_Nails",
					"Material_FPole_WoodenLog2",
					"Material_WoodenPlanks",
					"Material_MetalSheets"
				};
				icon="cat_bb_material";
				selection="wall_build";
			};
			class WallPaper
			{
				name="Wallpaper";
				description="";
				attachmentSlots[]=
				{
					"BBP_Wallpaper"
				};
				selection="wall_build";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class AnimSourceHidden
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class AnimRotate
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Lights: AnimSourceHidden
			{
			};
			class Xlights: AnimSourceHidden
			{
			};
			class Xlights_glass_r: AnimSourceHidden
			{
			};
			class Xlights_glass_g: AnimSourceHidden
			{
			};
			class Xlights_glass_b: AnimSourceHidden
			{
			};
			class Xlights_glass_y: AnimSourceHidden
			{
			};
			class Material_Nails: AnimSourceHidden
			{
			};
			class Material_FPole_WoodenLog2: AnimSourceHidden
			{
			};
			class Material_WoodenPlanks: AnimSourceHidden
			{
			};
			class Material_MetalSheets: AnimSourceHidden
			{
			};
			class Material_Wallpaper_01: AnimSourceHidden
			{
			};
			class Material_Wallpaper_02: AnimSourceHidden
			{
			};
			class Material_Wallpaper_03: AnimSourceHidden
			{
			};
			class Material_Wallpaper_04: AnimSourceHidden
			{
			};
			class Material_Wallpaper_05: AnimSourceHidden
			{
			};
			class Material_Wallpaper_06: AnimSourceHidden
			{
			};
			class Material_Wallpaper_07: AnimSourceHidden
			{
			};
			class Material_Wallpaper_08: AnimSourceHidden
			{
			};
			class Wall_Camonet: AnimSourceHidden
			{
			};
			class Wall_BarbedWire_1: AnimSourceHidden
			{
			};
			class Wall_BarbedWire_1_Mounted: AnimSourceHidden
			{
			};
			class Wall_BarbedWire_2: AnimSourceHidden
			{
			};
			class Wall_BarbedWire_2_Mounted: AnimSourceHidden
			{
			};
			class Wall_Awning: AnimSourceHidden
			{
			};
			class Wall_Flashlight: AnimSourceHidden
			{
			};
			class Deployed: AnimSourceHidden
			{
			};
			class Hologram: AnimSourceHidden
			{
			};
			class Frame: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class T1_Wall_Planks: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks_2: AnimSourceHidden
			{
			};
			class Window_Bars: AnimSourceHidden
			{
			};
			class T2_Metal: AnimSourceHidden
			{
			};
			class T2_Metal_2: AnimSourceHidden
			{
			};
			class T1_door: AnimSourceHidden
			{
			};
			class T2_Door: AnimSourceHidden
			{
			};
			class T1_door_Rotate: AnimRotate
			{
			};
			class T2_Door_Rotate: AnimRotate
			{
			};
			class T3_door: AnimSourceHidden
			{
			};
			class T3_door_Rotate: AnimRotate
			{
			};
			class Wall_Interact_Rotate: AnimRotate
			{
			};
		};
		class Construction
		{
			class wall_build
			{
				class frame
				{
					name="Window Frame";
					is_base=1;
					is_gate=1;
					id=1;
					required_parts[]={};
					conflicted_parts[]={};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=5;
						};
					};
				};
				class t1_wall_logs_horizontal
				{
					name="(T1) Log Wall";
					id=2;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_wall_concrete_bricks",
						"t3_wall_concrete_bricks_2",
						"t1_wall_planks",
						"t3_door"
					};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
						class Material2
						{
							type="WoodenLog";
							slot_name="Material_FPole_WoodenLog2";
							quantity=2;
						};
					};
				};
				class t1_door
				{
					name="(T1) Wooden Hatch";
					id=3;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_door"
					};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=5;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=2;
						};
					};
				};
				class t2_door
				{
					name="(T2) Metal Hatch";
					id=11;
					required_parts[]=
					{
						"t1_door"
					};
					conflicted_parts[]=
					{
						"t3_door"
					};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=5;
						};
						class Material2
						{
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=2;
						};
					};
				};
				class t3_door
				{
					name="(T3) Reinforced Hatch";
					id=4;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t1_door",
						"t1_wall_logs_horizontal",
						"t1_wall_planks"
					};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
						class Material2
						{
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=3;
						};
						class Material3
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=5;
						};
					};
				};
				class t3_wall_concrete_bricks
				{
					name="(T3) Concrete Wall";
					id=5;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t1_wall_logs_horizontal",
						"t3_wall_concrete_bricks_2",
						"t1_wall_planks"
					};
					collision_data[]={};
					build_action_type=4;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="BBP_Mortar_Mix";
							slot_name="Material_Mortar";
							quantity=1;
						};
						class Material2
						{
							type="BBP_Concrete_Brick_Pile";
							slot_name="Material_BBP_Concrete_Brick_Pile";
							quantity=3;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Sheet Metal";
					id=6;
					required_parts[]=
					{
						"t1_wall_logs_horizontal"
					};
					conflicted_parts[]={};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
						class Material2
						{
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=4;
						};
					};
				};
				class window_bars
				{
					name="Window Bars";
					id=7;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]={};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=1;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=1;
						};
					};
				};
				class t3_wall_concrete_bricks_2
				{
					name="(T3) Concrete Brick Wall";
					id=8;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t1_wall_logs_horizontal",
						"t3_wall_concrete_bricks",
						"t1_wall_planks"
					};
					collision_data[]={};
					build_action_type=4;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="BBP_Mortar_Mix";
							slot_name="Material_Mortar";
							quantity=1;
						};
						class Material2
						{
							type="BBP_Concrete_Brick_Pile";
							slot_name="Material_BBP_Concrete_Brick_Pile";
							quantity=3;
						};
					};
				};
				class t1_wall_planks
				{
					name="(T1) Plank Wall";
					id=9;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_wall_concrete_bricks",
						"t3_wall_concrete_bricks_2",
						"t1_wall_logs_horizontal",
						"t3_door"
					};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=5;
						};
					};
				};
				class t2_metal_2
				{
					name="(T2) Sheet Metal";
					id=10;
					required_parts[]=
					{
						"t1_wall_planks"
					};
					conflicted_parts[]={};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=4;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
			};
		};
	};
};
