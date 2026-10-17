class CfgPatches
{
	class BaseBuildingPlus_halfWall
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
	class BBP_WALL_BASE;
	class BBP_Half_Wall_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(Large/Small) Half Wall Kit";
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
	class BBP_Half_Bwall_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Large Half Wall Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\models\t1_wall_half\Hologram\T1_Wall_Half_Hologram.p3d";
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
	class BBP_Half_Swall_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Small Half Wall Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\Frames\Proxy_Half_Swall_Hologram_placing.p3d";
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
	class BBP_Half_Bwall: BBP_WALL_BASE
	{
		scope=2;
		displayName="Large Half Wall";
		descriptionShort="A sturdy wooden wall.";
		model="\BaseBuildingPlus\BBP_Building\half_wall\Half_Bwall\BBP_Half_Bwall.p3d";
		attachments[]=
		{
			"BBP_Wallpaper",
			"Material_MetalSheets",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Lights",
			"Wall_Camonet",
			"Wall_BarbedWire_1",
			"Wall_Flashlight",
			"Material_Nails",
			"Material_FPole_WoodenLog2",
			"Material_WoodenPlanks",
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
			"Wall_BarbedWire_1"
		};
		mountables[]=
		{
			"Wall_BarbedWire_1"
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name="Attachments";
				description="";
				attachmentSlots[]=
				{
					"Wall_Camonet",
					"Wall_BarbedWire_1",
					"Wall_Flashlight"
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
					"Material_MetalSheets",
					"Material_BBP_Concrete_Brick_Pile",
					"Material_Mortar",
					"Material_Nails",
					"Material_FPole_WoodenLog2",
					"Material_WoodenPlanks"
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
			class T2_Metal: AnimSourceHidden
			{
			};
			class T2_Metal_2: AnimSourceHidden
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
			class Wall_Flashlight: AnimSourceHidden
			{
			};
			class Deployed: AnimSourceHidden
			{
			};
			class Hologram: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class T1_Wall_Planks: AnimSourceHidden
			{
			};
			class Frame: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks_2: AnimSourceHidden
			{
			};
			class Dummy_Gate: AnimSourceHidden
			{
			};
			class Dummy_Rotate: AnimRotate
			{
			};
		};
		class Construction
		{
			class wall_build
			{
				class frame
				{
					name="Frame";
					is_base=1;
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
							quantity=3;
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
							type="WoodenLog";
							slot_name="Material_FPole_WoodenLog2";
							quantity=1;
						};
					};
				};
				class t3_wall_concrete_bricks
				{
					name="(T3) Concrete Wall";
					id=3;
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
							quantity=2;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Sheet Metal";
					id=4;
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
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=2;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
				class t3_wall_concrete_bricks_2
				{
					name="(T3) Concrete Brick Wall";
					id=5;
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
							quantity=2;
						};
					};
				};
				class t1_wall_planks
				{
					name="(T1) Plank Wall";
					id=6;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_wall_concrete_bricks",
						"t3_wall_concrete_bricks_2",
						"t1_wall_logs_horizontal"
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
							quantity=3;
						};
					};
				};
				class t2_metal_2
				{
					name="(T2) Sheet Metal";
					id=7;
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
							quantity=2;
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
	class BBP_Half_Swall: BBP_WALL_BASE
	{
		scope=2;
		displayName="Small Half Wall";
		descriptionShort="A sturdy wooden wall.";
		model="\BaseBuildingPlus\BBP_Building\half_wall\Half_Swall\BBP_Half_Swall.p3d";
		attachments[]=
		{
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Lights",
			"Wall_Camonet",
			"Wall_BarbedWire_1",
			"Wall_BarbedWire_2",
			"Wall_Flashlight",
			"Material_Nails",
			"Material_FPole_WoodenLog2",
			"Material_WoodenPlanks",
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
			""
		};
		mountables[]=
		{
			""
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name="Attachments";
				description="";
				attachmentSlots[]=
				{
					""
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
					"Material_WoodenPlanks"
				};
				icon="cat_bb_material";
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
			class Deployed: AnimSourceHidden
			{
			};
			class Hologram: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class Frame: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
			{
			};
			class T1_Wall_Planks: AnimSourceHidden
			{
			};
			class Dummy_Gate: AnimSourceHidden
			{
			};
			class T2_Metal: AnimSourceHidden
			{
			};
			class T2_Metal_2: AnimSourceHidden
			{
			};
			class Dummy_Rotate: AnimRotate
			{
			};
		};
		class Construction
		{
			class wall_build
			{
				class frame
				{
					name="Frame";
					is_base=1;
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
							quantity=5;
						};
						class Material2
						{
							type="WoodenLog";
							slot_name="Material_FPole_WoodenLog2";
							quantity=1;
						};
					};
				};
				class t3_wall_concrete_bricks
				{
					name="(T3) Concrete Wall";
					id=3;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t1_wall_logs_horizontal",
						"t1_wall_planks"
					};
					collision_data[]={};
					build_action_type=4;
					dismantle_action_type=2;
					material_type=1;
					class Materials
					{
						class Material1
						{
							type="BBP_Concrete_Brick_Pile";
							slot_name="Material_BBP_Concrete_Brick_Pile";
							quantity=1;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Sheet Metal";
					id=4;
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
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=1;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=5;
						};
					};
				};
				class t1_wall_planks
				{
					name="(T1) Plank Wall";
					id=5;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_wall_concrete_bricks",
						"t3_wall_concrete_bricks_2",
						"t1_wall_logs_horizontal"
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
				class t2_metal_2
				{
					name="(T2) Sheet Metal";
					id=6;
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
							quantity=1;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=5;
						};
					};
				};
			};
		};
	};
};
