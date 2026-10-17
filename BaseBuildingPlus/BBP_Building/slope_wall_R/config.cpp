class CfgPatches
{
	class BaseBuildingPlus_slopeWallR
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
	class BBP_Slope_Wall_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(Right/Left) Slope Wall Kit";
		descriptionShort="Press the left arrow key to cycle.";
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
	class BBP_Right_Slope_Wall_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Large Wall Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\slope_wall_R\Proxies\slope_r_frame_hologram_placing.p3d";
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
	class BBP_Right_Slope_Wall: BBP_WALL_BASE
	{
		scope=2;
		displayName="Right Slope Wall";
		descriptionShort="A sturdy wooden wall.";
		model="\BaseBuildingPlus\BBP_Building\slope_wall_R\slope_r.p3d";
		attachments[]={
			"BBP_Wallpaper",
			"Wall_Camonet",
			"Material_MetalSheets",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Lights",
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
					"Wall_Camonet"
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
			class T2_Metal: AnimSourceHidden
			{
			};
			class T2_Metal_2: AnimSourceHidden
			{
			};
			class Wall_Camonet: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
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
							quantity=2;
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
							quantity=3;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
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
							quantity=3;
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
