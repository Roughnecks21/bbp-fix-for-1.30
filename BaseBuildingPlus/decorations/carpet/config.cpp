class CfgPatches
{
	class BaseBuildingPlus_Carpets
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
	class BBP_Carpet: Inventory_Base
	{
		scope=0;
		displayName="Carpet";
		descriptionShort="Good morning and excuse my bad English, is it planned to bring the wallpapers back into the game?";
		model="\BaseBuildingPlus\decorations\carpet\BBP_Carpet.p3d";
		itemSize[]={4,2};
		absorbency=0.89999998;
		ragQuantity=6;
		inventorySlot[]=
		{
			"BBP_Carpet"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\carpet\Carpet_Example.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0,
							
							{
								""
							}
						}
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
		class AnimationSources
		{
			class folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class unfolded_1
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class unfolded_2
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class unfolded_3
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};
	class BBP_Carpet_1: BBP_Carpet
	{
		scope=2;
		displayName="Blue Carpet";
		descriptionShort="Blue Carpet";
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\carpet\Carpet_Example.paa"
		};
	};
	class BBP_Carpet_2: BBP_Carpet
	{
		scope=2;
		displayName="Green Carpet";
		descriptionShort="Green Carpet";
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\carpet\Carpet_Example_2.paa"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBBP_Carpet: ProxyAttachment
	{
		model="\BaseBuildingPlus\decorations\carpet\BBP_Carpet.p3d";
		inventorySlot[]=
		{
			"BBP_Carpet"
		};
	};
};
