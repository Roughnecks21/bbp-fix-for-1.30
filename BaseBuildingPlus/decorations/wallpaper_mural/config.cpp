class CfgPatches
{
	class BaseBuildingPlus_Wallpaper_Mural
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
	class BBP_WallPaper_Mural: Inventory_Base
	{
		scope=0;
		displayName="Wallpaper Mural";
		descriptionShort="Good morning and excuse my bad English, is it planned to bring the wallpapers back into the game?";
		model="\BaseBuildingPlus\decorations\wallpaper_mural\BBP_WallPaper_Mural.p3d";
		itemSize[]={4,1};
		absorbency=0.89999998;
		ragQuantity=6;
		inventorySlot[]=
		{
			"BBP_WallPaper_Mural"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\wallpaper_mural\wallpaper_Example.paa"
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
		};
	};
	class BBP_WallPaper_Mural_1: BBP_WallPaper_Mural
	{
		scope=2;
		displayName="Mando";
		descriptionShort="Disney Please Don't Copyright Me!";
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\wallpaper_mural\wallpaper_mural_Example_1.paa"
		};
	};
	class BBP_WallPaper_Mural_2: BBP_WallPaper_Mural
	{
		scope=2;
		displayName="The Trilogy";
		descriptionShort="Disney Please Don't Copyright Me!";
		hiddenSelectionsTextures[]=
		{
			"BaseBuildingPlus\decorations\wallpaper_mural\wallpaper_mural_Example_2.paa"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBBP_WallPaper_Mural: ProxyAttachment
	{
		model="\BaseBuildingPlus\decorations\wallpaper_mural\BBP_WallPaper_Mural.p3d";
		inventorySlot[]=
		{
			"BBP_WallPaper_Mural"
		};
	};
};
