class CfgPatches
{
	class BaseBuildingPlus_bFloormesh
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
	class BBP_Floor_Mesh_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(T2) Metal Floor Mesh Kit";
		descriptionShort="Place on the ground to begin construction.";
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
	class BBP_Floor_Mesh_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Large Floor Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\hologram\bfloor\placing_hologram_bfloor.p3d";
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
	class BBP_Floor_Mesh: BBP_WALL_BASE
	{
		scope=2;
		displayName="Metal Floor Mesh";
		descriptionShort="A sturdy wooden wall.";
		model="\BaseBuildingPlus\BBP_Building\floor\BFloorMesh\BBP_Sfloor.p3d";
		attachments[]=
		{
			"Material_Nails",
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
			class Material_Carpet_01: AnimSourceHidden
			{
			};
			class Material_Carpet_02: AnimSourceHidden
			{
			};
			class Material_Carpet_03: AnimSourceHidden
			{
			};
			class Material_Carpet_04: AnimSourceHidden
			{
			};
			class Material_Carpet_05: AnimSourceHidden
			{
			};
			class Material_Carpet_06: AnimSourceHidden
			{
			};
			class Material_Carpet_07: AnimSourceHidden
			{
			};
			class Material_Carpet_08: AnimSourceHidden
			{
			};
			class Material_Plaster_01: AnimSourceHidden
			{
			};
			class Material_Plaster_02: AnimSourceHidden
			{
			};
			class Material_Plaster_03: AnimSourceHidden
			{
			};
			class Material_Plaster_04: AnimSourceHidden
			{
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
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class Frame: AnimSourceHidden
			{
			};
			class T2_Metal: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
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
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=1;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Metal Mesh";
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
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=2;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
				class hologram_collision
				{
					name="Hologram Collision";
					id=3;
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
