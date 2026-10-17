class CfgPatches
{
	class BaseBuildingPlus
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"RPC_Scripts",
			"DZ_Gear_Tools",
			"DZ_Gear_Camping"
		};
	};
};
class CfgMods
{
	class BaseBuildingPlus
	{
		type="mod";
		author="DA CREW";
		name="BaseBuildingPlus";
		dir="BaseBuildingPlus";
		defines[]=
		{
			"BBP"
		};
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"BaseBuildingPlus/GUI/imagesets/BBP_BuildMenu.imageset",
					"BaseBuildingPlus/GUI/imagesets/BBP_BuildMenu2.imageset",
					"BaseBuildingPlus/GUI/imagesets/bbp_icons.imageset",
					"BaseBuildingPlus/GUI/imagesets/Laptop/AppIcons.imageset",
					"BaseBuildingPlus/GUI/imagesets/workbench_UI.imageset",
					"BaseBuildingPlus/GUI/imagesets/workbench_UI2.imageset",
					"BaseBuildingPlus/GUI/imagesets/workbench_UI3.imageset"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BaseBuildingPlus/scripts/Common",
					"BaseBuildingPlus/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BaseBuildingPlus/scripts/Common",
					"BaseBuildingPlus/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"BaseBuildingPlus/scripts/Common",
					"BaseBuildingPlus/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSlots
{
	class Slot_Blueprint
	{
		name="Blueprint";
		displayName="Blueprint";
		ghostIcon="set:bbp_icons image:bbp_blueprint";
	};
	class Slot_HandSaw
	{
		name="HandSaw";
		displayName="HandSaw";
		ghostIcon="set:bbp_icons image:bbp_handsaw";
	};
	class Slot_BBP_TapeMeasure
	{
		name="BBP_TapeMeasure";
		displayName="BBP_TapeMeasure";
		ghostIcon="set:bbp_icons image:bbp_tm";
	};
	class Slot_Material_BBP_Concrete_Brick_Pile
	{
		name="Material_BBP_Concrete_Brick_Pile";
		displayName="Concrete bricks";
		selection="material_bbp_concrete_brick_pile";
		ghostIcon="set:bbp_icons image:bbp_cementbricks";
		stackMax=5;
	};
	class Slot_Material_BBP_BarbedWire
	{
		name="Material_BBP_BarbedWire";
		displayName="#STR_CfgBarbedWire0";
		ghostIcon="set:dayz_inventory image:barbedwiredown";
	};
	class Slot_Material_Cement
	{
		name="Material_Cement";
		displayName="Cement";
		ghostIcon="set:bbp_icons image:bbp_cement";
		stackMax=2;
	};
	class Slot_Material_Mortar
	{
		name="Material_Mortar";
		displayName="Mortar";
		selection="Material_Mortar";
		ghostIcon="set:bbp_icons image:bbp_mortar";
		stackMax=4;
	};
	class Slot_BBP_Wallpaper
	{
		name="BBP_Wallpaper";
		displayName="Wallpaper";
		ghostIcon="set:bbp_icons image:bbp_wallpaper";
	};
	class Slot_BBP_WallPaper_Mural
	{
		name="BBP_WallPaper_Mural";
		displayName="Mural Wallpaper";
		ghostIcon="set:bbp_icons image:bbp_wallpaper";
	};
	class Slot_BBP_Carpet
	{
		name="BBP_Carpet";
		displayName="Carpet";
		ghostIcon="set:bbp_icons image:bbp_carpet";
	};
	class Slot_BBP_Plaster
	{
		name="BBP_Plaster";
		displayName="Plaster";
		ghostIcon="set:bbp_icons image:bbp_plaster";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Hammer;
	class BBP_Admin_Hammer: Hammer
	{
		displayName="ADMIN HAMMER";
		descriptionShort="No materials required for building, only dirty cheaters use this item.";
		model="\BaseBuildingPlus\BBP_Building\admin_hammer\Admin_Hammer.p3d";
		itemSize[]={2,2};
	};
	class BarbedWire: Inventory_Base
	{
		inventorySlot[]+=
		{
			"Material_BBP_BarbedWire"
		};
	};
	class BBP_KIT_BASE: Inventory_Base
	{
		scope=0;
		isMeleeWeapon=0;
		weight=300;
		absorbency=0;
		rotationFlags=90;
		itemSize[]={4,2};
		lootCategory="Materials";
		reversed=0;
		itemBehaviour=2;
	};
	class BBP_WALL_BASE: Inventory_Base
	{
		scope=0;
		hiddenSelections[]=
		{
			"xlights_glass_r",
			"xlights_glass_g",
			"xlights_glass_b",
			"xlights_glass_y"
		};
		overrideDrawArea="3.0";
		forceFarBubble="true";
		lootCategory="Crafted";
		carveNavmesh=1;
		weight=60000;
		itemSize[]={6,6};
		physLayer="item_large";
		createProxyPhysicsOnInit="false";
		createdProxiesOnInit[]=
		{
			"Deployed",
			"Hologram"
		};
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0;
			plugType=1;
			attachmentAction=1;
			updateInterval=5;
		};
		class PointLights
		{
			class PointLight
			{
				color[]={1,1,1,0.050000001};
				ambient[]={0.0099999998,0.0099999998,0.0099999998,0.0099999998};
				position="light";
				hitpoint="bulb";
				selection="bulb";
				size=0;
				radius=10;
				brightness=5;
				dayLight=1;
				heatHazeRadius=0;
				heatHazePower=0;
				fireEffect=0;
				fireEffectOctaves=0;
				fireEffectPersistence=0;
				fireEffectFract=0;
			};
		};
	};
	class BBP_GATE_BASE: BBP_WALL_BASE
	{
	};
	class BBP_DOOR_BASE: BBP_WALL_BASE
	{
	};
	class BBP_BuildPermit: Inventory_Base
	{
		scope=2;
		displayName="Construction Permit";
		descriptionShort="Official BBP Building Permit. Combine with 6 planks to craft a construction workbench.";
		model="\BaseBuildingPlus\models\build_permit\BBP_BuildPermit.p3d";
		physLayer="item_small";
		weight=1;
		itemSize[]={1,1};
		rotationFlags=1;
	};
};
class CfgNonAIVehicles
{
	class ProxyBaseBuilding;
	class ProxyBlueprint: ProxyBaseBuilding
	{
		model="\BaseBuildingPlus\models\workbench\blueprint.p3d";
		inventorySlot[]=
		{
			"Blueprint"
		};
	};
	class ProxyMaterial_BBP_Concrete_Brick_Pile: ProxyBaseBuilding
	{
		model="\BaseBuildingPlus\models\concrete\Material_BBP_Concrete_Brick_Pile.p3d";
		inventorySlot[]=
		{
			"Material_BBP_Concrete_Brick_Pile"
		};
	};
};
