class CfgPatches
{
	class BaseBuildingPlus_Workbench
	{
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
	class Container_Base;
	class Book_Base;
	class BBP_Blueprint: Inventory_Base
	{
		scope=2;
		displayName="BBP Crafting Book";
		descriptionShort="Combine this book with 5 planks to craft a workbench, (you keep the book after the crafting is done.) Then attach the book to the workbench to start crafting kits.";
		model="BaseBuildingPlus\models\workbench\blueprint.p3d";
		inventorySlot="Blueprint";
		itemSize[]={2,2};
		rotationFlags=1;
		weight=1;
	};
	class BBP_TapeMeasure: Inventory_Base
	{
		scope=2;
		displayName="BBP Tape Measure";
		descriptionShort="Used for getting the current health of BBP Parts. Instructions: Hold tape measure in your hand, and look at the BBP object.";
		model="BaseBuildingPlus\models\workbench\tape_measure\BBP_Tape_Measure.p3d";
		inventorySlot="BBP_TapeMeasure";
		itemSize[]={1,1};
		weight=1;
	};
	class WoodenCrate;
	class BBP_KIT_BASE;
	class BBP_Workbench_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="BBP Workbench Kit";
		descriptionShort="BaseBuildingPlus workbench kit.";
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
	class BBP_Workbench_hologram: Inventory_Base
	{
		scope=2;
		displayName="Hologram";
		descriptionShort="xD";
		model="BaseBuildingPlus\models\workbench\proxies\workbench_hologram.p3d";
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
	class BBP_Workstation_Base: WoodenCrate
	{
		scope=0;
		displayName="WorkstationBase";
		descriptionShort="Attach a blueprint, tape measure and hand-saw start crafting.";
		model="BaseBuildingPlus\models\workbench\workbench.p3d";
		attachments[]=
		{
			"Blueprint",
			"Backpack_1",
			"Truck_01_WoodenLogs",
			"Material_WoodenPlanks",
			"Material_MetalSheets",
			"Material_Cement",
			"Material_Mortar",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Nails",
			"Melee",
			"BBP_TapeMeasure"
		};
		canBeDigged=0;
		heavyItem=1;
		weight=10000;
		physLayer="item_large";
		rotationFlags=0;
		itemSize[]={10,10};
		itemBehaviour=0;
		allowOwnedCargoManipulation=1;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
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
	};
	class BBP_Workbench: BBP_Workstation_Base
	{
		scope=2;
		displayName="BBP Workbench";
		model="BaseBuildingPlus\models\workbench\workbench.p3d";
		class AnimationSources
		{
			class Nails
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class Logs
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class Planks
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class Metal
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class Tape
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
			class HandSaw
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
		};
	};
};
