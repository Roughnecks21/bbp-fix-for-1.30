class CfgPatches
{
	class BaseBuildingPlus_bStair
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
	class BBP_Stair_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(Large/Small) Stair Kit";
		descriptionShort="Press the left arrow key to cycle between sizes.";
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
	class BBP_Bstair_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Stair Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\stair\Bstair\proxies\proxy_placing.p3d";
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
	class BBP_Bstair: BBP_WALL_BASE
	{
		scope=2;
		displayName="Large Stair";
		descriptionShort="Stair.";
		model="\BaseBuildingPlus\BBP_Building\stair\Bstair\BBP_Bstair.p3d";
		attachments[]={
			"Material_Nails",
			"Material_WoodenPlanks",
			"Material_MetalSheets",
			"Material_Carpet_01",
			"Material_Carpet_02",
			"Material_Carpet_03",
			"Material_Carpet_04",
			"Material_Carpet_05",
			"Material_Carpet_06",
			"Material_Carpet_07",
			"Material_Carpet_08",
			"Material_Plaster_01",
			"Material_Plaster_02",
			"Material_Plaster_03",
			"Material_Plaster_04"
		};
		hybridAttachments[]={};
		mountables[]={};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name="Materials";
				description="";
				attachmentSlots[]=
				{
					"Material_Nails",
					"Material_WoodenPlanks",
					"Material_MetalSheets"
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
			class Deployed: AnimSourceHidden
			{
			};
			class Hologram: AnimSourceHidden
			{
			};
			class Hologram_Collision: AnimSourceHidden
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
					name="Large Stair";
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
				class hologram_collision
				{
					name="Hologram Collision";
					id=2;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"frame"
					};
					collision_data[]={};
					build_action_type=2;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="BBP_Mortar_Mix";
							slot_name="Material_Mortar";
							quantity=20;
						};
						class Material2
						{
							type="BBP_Concrete_Brick_Pile";
							slot_name="Material_BBP_Concrete_Brick_Pile";
							quantity=20;
						};
					};
				};
			};
		};
	};
};
