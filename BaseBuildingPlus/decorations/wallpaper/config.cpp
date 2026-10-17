class CfgPatches
{
	class BaseBuildingPlus_Wallpaper
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
	class BBP_WallPaper: Inventory_Base
	{
		scope=0;
		displayName="Wallpaper";
		descriptionShort="Good morning and excuse my bad English, is it planned to bring the wallpapers back into the game?";
		model="\BaseBuildingPlus\decorations\wallpaper\BBP_Wallpaper.p3d";
		itemSize[]={4,1};
		absorbency=0.89999998;
		ragQuantity=6;
		inventorySlot[]=
		{
			"BBP_Wallpaper"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\wallpaper\Wallpaper_Example.paa"
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
			class unfolded_4
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class unfolded_5
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class unfolded_6
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class unfolded_7
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
	};
	class BBP_WallPaper_1: BBP_WallPaper
	{
		scope=2;
		displayName="Nature's Herbs";
		descriptionShort="It's not weed officer";
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\wallpaper\Wallpaper_Example.paa"
		};
	};
	class BBP_WallPaper_2: BBP_WallPaper
	{
		scope=2;
		displayName="Land Of The Free";
		descriptionShort="AMERICA!";
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\wallpaper\Wallpaper_Example_2.paa"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBBP_Wallpaper: ProxyAttachment
	{
		model="\BaseBuildingPlus\decorations\wallpaper\BBP_Wallpaper.p3d";
		inventorySlot[]=
		{
			"BBP_Wallpaper"
		};
	};
};
