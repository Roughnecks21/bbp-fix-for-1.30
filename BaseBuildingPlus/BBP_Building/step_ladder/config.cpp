class CfgPatches
{
	class BaseBuildingPlus_StepLadder
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
	class BBP_Step_Ladder_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="Folded Step Ladder";
		descriptionShort="Designed to help building when its above you.";
		model="\BaseBuildingPlus\BBP_Building\step_ladder\proxies\BBP_Stepladder_Folded.p3d";
		rotationFlags=0;
		isMeleeWeapon=0;
		weight=300;
		absorbency=0;
		itemSize[]={10,10};
		lootCategory="Materials";
		reversed=0;
		itemBehaviour=2;
	};
	class BBP_Step_Ladder_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Step ladder";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\step_ladder\proxies\BBP_Stepladder.p3d";
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
	class BBP_Step_Ladder: BBP_WALL_BASE
	{
		scope=2;
		displayName="Step Ladder";
		descriptionShort="Stair.";
		model="\BaseBuildingPlus\BBP_Building\step_ladder\BBP_Step_Ladder.p3d";
		attachments[]={};
		hybridAttachments[]={};
		mountables[]={};
		class GUIInventoryAttachmentsProps
		{
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
					name="Stair";
					id=1;
					is_base=1;
					required_parts[]=
					{
						"hologram"
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
							quantity=100;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=100;
						};
					};
				};
			};
		};
	};
};
