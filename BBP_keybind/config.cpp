class CfgPatches
{
	class BBP_keybind
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
	class BBP_keybind
	{
		type="mod";
		author="DA CREW";
		name="BBP_keybind";
		dir="BBP_keybind";
		inputs="BBP_keybind/data/modded_Inputs.xml";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
	};
};
