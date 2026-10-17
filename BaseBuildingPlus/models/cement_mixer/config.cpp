class CfgPatches
{
	class BaseBuildingPlus_Concrete
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
	class Spotlight;
	class Inventory_Base;
	class BBP_KIT_BASE;
	class BBP_Cement_Mixer_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="Cement Mixer Kit";
		descriptionShort="Cement Mixer kit.";
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
	class BBP_Cement_Mixer_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\models\cement_mixer\BBP_Cement_Mixer_Hologram.p3d";
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
	class BBP_Cement_Mixer: Spotlight
	{
		scope=2;
		displayName="Cement Mixer";
		descriptionShort="A cement mixer. Connect a power source and add 2 bags of concrete mix to craft concrete brick piles.";
		model="\BaseBuildingPlus\models\cement_mixer\moveable\BBP_Cement_Mixer.p3d";
		overrideDrawArea="8.0";
		forceFarBubble="true";
		destroyOnEmpty=0;
		quantityBar=0;
		varQuantityMax=0;
		carveNavmesh=1;
		canBeDigged=0;
		heavyItem=1;
		weight=10000;
		itemSize[]={15,15};
		itemBehaviour=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		attachments[]=
		{
			"Material_Cement"
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.0099999998;
			cordTextureFile="DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength=5;
			plugType=2;
			updateInterval=5;
		};
		class AnimationSources
		{
			class Spin
			{
				source="user";
				initPhase=0;
				animPeriod=7200;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\camping\data\spotlight.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\camping\data\spotlight.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\camping\data\spotlight_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\camping\data\spotlight_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\camping\data\spotlight_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BBP_Cement_Mixer_Static: Spotlight
	{
		scope=2;
		displayName="CEMENT MIXER";
		descriptionShort="A cement mixer. Connect a power source and add 2 bags of concrete mix to craft concrete brick piles.";
		model="\BaseBuildingPlus\models\cement_mixer\BBP_Cement_Mixer_Static.p3d";
		overrideDrawArea="8.0";
		forceFarBubble="true";
		destroyOnEmpty=0;
		quantityBar=0;
		varQuantityMax=0;
		carveNavmesh=1;
		canBeDigged=0;
		heavyItem=1;
		weight=10000;
		itemSize[]={15,15};
		itemBehaviour=0;
		physLayer="item_large";
		allowOwnedCargoManipulation=1;
		attachments[]=
		{
			"Material_Cement"
		};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.0099999998;
			cordTextureFile="DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength=5;
			plugType=2;
			updateInterval=5;
		};
		class AnimationSources
		{
			class Spin
			{
				source="user";
				initPhase=0;
				animPeriod=7200;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\camping\data\spotlight.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\camping\data\spotlight.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\camping\data\spotlight_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\camping\data\spotlight_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\camping\data\spotlight_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class WoodenCrate;
	class BBP_Concrete_Brick_Pile: WoodenCrate
	{
		scope=2;
		displayName="Concrete Bricks";
		descriptionShort="A pile of concrete bricks.";
		model="\BaseBuildingPlus\models\concrete\Material_BBP_Concrete_Brick_Pile.p3d";
		bounding="BSphere";
		overrideDrawArea="3.0";
		handheld="true";
		carveNavmesh=1;
		physLayer="item_large";
		rotationFlags=2;
		weight=18000;
		itemSize[]={5,4};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=5;
		varQuantityDestroyOnMin=1;
		varStackMax=5;
		lootCategory="Tools";
		inventorySlot[]=
		{
			"Material_BBP_Concrete_Brick_Pile"
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItemLight
				{
					soundSet="pickUpGardenLimeLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpGardenLime_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="gardenlime_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class BBP_Cement: WoodenCrate
	{
		scope=2;
		displayName="Concrete Mix";
		descriptionShort="A bag of concrete mix. Use with a cement mixer to create concrete bricks. Connect a power source to a cement mixer and add 2 bags of this to craft concrete bricks.";
		model="\BaseBuildingPlus\models\concrete\BBP_Cement_Bag.p3d";
		bounding="BSphere";
		overrideDrawArea="3.0";
		handheld="true";
		carveNavmesh=1;
		physLayer="item_large";
		animClass="NoFireClass";
		weight=15000;
		itemSize[]={4,5};
		heavyItem=1;
		itemBehaviour=2;
		reversed=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=2;
		varQuantityDestroyOnMin=1;
		varStackMax=2;
		lootCategory="Materials";
		inventorySlot="Material_Cement";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItemLight
				{
					soundSet="pickUpGardenLimeLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpGardenLime_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="gardenlime_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class BBP_Mortar_Mix: Inventory_Base
	{
		scope=2;
		displayName="Mortar Mix";
		descriptionShort="A bag of mortar mix. Used to secure concrete bricks together.";
		model="\BaseBuildingPlus\models\concrete\BBP_mortar_bag.p3d";
		bounding="BSphere";
		overrideDrawArea="3.0";
		handheld="true";
		carveNavmesh=1;
		physLayer="item_large";
		animClass="NoFireClass";
		weight=1000;
		itemSize[]={3,3};
		rotationFlags=2;
		reversed=0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=4;
		varQuantityDestroyOnMin=1;
		varStackMax=4;
		inventorySlot="Material_Mortar";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItemLight
				{
					soundSet="pickUpGardenLimeLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpGardenLime_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="gardenlime_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};
