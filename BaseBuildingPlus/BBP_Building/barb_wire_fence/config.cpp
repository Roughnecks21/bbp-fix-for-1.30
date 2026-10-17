class CfgPatches
{
	class BaseBuildingPlus_barbWireFence
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
	class BBP_Barbwire_Fence_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="Barbwire Barrier Kit";
		descriptionShort="Barbwire Barrier Kit";
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
	class BBP_Barbwire_Fence_Hologram: Inventory_Base
	{
		scope=2;
		displayName="bARB";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\barb_wire_fence\proxies\barb_hologram_placing.p3d";
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
	class BBP_Barbwire_Fence: BBP_WALL_BASE
	{
		scope=2;
		displayName="Barbwire Barrier";
		descriptionShort="A sturdy wooden wall.";
		model="\BaseBuildingPlus\BBP_Building\barb_wire_fence\BBP_Barb_Fence.p3d";
		attachments[]=
		{
			"Material_BBP_BarbedWire",
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
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name="Materials";
				description="";
				attachmentSlots[]=
				{
					"Material_BBP_BarbedWire",
					"Material_Nails",
					"Material_FPole_WoodenLog2"
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
			class Frame: AnimSourceHidden
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
							type="WoodenLog";
							slot_name="Material_FPole_WoodenLog2";
							quantity=2;
						};
					};
				};
				class t1_wall_logs_horizontal
				{
					name="Barbwire";
					id=2;
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
							quantity=10;
						};
						class Material2
						{
							type="BarbedWire";
							slot_name="Material_BBP_BarbedWire";
						};
					};
				};
			};
		};
	};
};
