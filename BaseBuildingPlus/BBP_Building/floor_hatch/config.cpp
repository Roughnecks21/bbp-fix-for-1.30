class CfgPatches
{
	class BaseBuildingPlus_floorHatch
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
	class BBP_DOOR_BASE;
	class BBP_Roof_Hatch_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="Roof Hatch Kit";
		descriptionShort="Floor Hatch construction kit. Place on the ground to begin construction.";
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
	class BBP_Roof_Hatch_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Roof Hatch Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\floor_hatch\proxies\placing_hologram_bfloor.p3d";
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
	class BBP_Roof_Hatch: BBP_DOOR_BASE
	{
		scope=2;
		displayName="Roof Hatch";
		descriptionShort="Door";
		model="\BaseBuildingPlus\BBP_Building\floor_hatch\BBP_Floor_Hatch.p3d";
		attachments[]={
			"BBP_Plaster",
			"Att_CombinationLock",
			"Att_CodeLock",
			"Att_ExpansionCodeLock",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
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
			class Attachments
			{
				name="Attachments";
				description="";
				attachmentSlots[]=
				{
					"Att_CombinationLock",
			"Att_CodeLock",
			"Att_ExpansionCodeLock"
				};
				icon="cat_bb_attachments";
				selection="wall_build";
			};
			class Materials
			{
				name="Materials";
				description="";
				attachmentSlots[]=
				{
					"Material_BBP_Concrete_Brick_Pile",
					"Material_Mortar",
					"Material_Nails",
					"Material_WoodenPlanks",
					"Material_MetalSheets"
				};
				icon="cat_bb_material";
				selection="wall_build";
			};
			class Plaster
			{
				name="Plaster";
				description="";
				attachmentSlots[]=
				{
					"BBP_Plaster"
				};
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
			class Wall_Camonet: AnimSourceHidden
			{
			};
			class Lights: AnimSourceHidden
			{
			};
			class Xlights: AnimSourceHidden
			{
			};
			class Xlights_glass_r: AnimSourceHidden
			{
			};
			class Xlights_glass_g: AnimSourceHidden
			{
			};
			class Xlights_glass_b: AnimSourceHidden
			{
			};
			class Xlights_glass_y: AnimSourceHidden
			{
			};
			class Material_Nails: AnimSourceHidden
			{
			};
			class Material_FPole_WoodenLog2: AnimSourceHidden
			{
			};
			class Material_WoodenPlanks: AnimSourceHidden
			{
			};
			class Material_MetalSheets: AnimSourceHidden
			{
			};
			class Wall_Flashlight: AnimSourceHidden
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
			class Frame: AnimSourceHidden
			{
			};
			class Stair: AnimSourceHidden
			{
			};
			class T2_Metal: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
			{
			};
			class T1_Door: AnimSourceHidden
			{
			};
			class T2_Door: AnimSourceHidden
			{
			};
			class T3_Door: AnimSourceHidden
			{
			};
			class T1_Door_Rotate: AnimRotate
			{
			};
			class T2_Door_Rotate: AnimRotate
			{
			};
			class T3_Door_Rotate: AnimRotate
			{
			};
			class Wall_Interact_Rotate: AnimRotate
			{
			};
		};
		class Construction
		{
			class wall_build
			{
				class frame
				{
					name="Hatch Frame";
					is_base=1;
					id=1;
					is_gate=1;
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
				class t1_wall_logs_horizontal
				{
					name="(T1) Wooden Roof";
					id=2;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_wall_concrete_bricks",
						"t3_door"
					};
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
							quantity=6;
						};
					};
				};
				class t1_door
				{
					name="(T1) Wooden Hatch";
					id=3;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_door"
					};
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
				class t2_door
				{
					name="(T2) Metal Hatch";
					id=9;
					required_parts[]=
					{
						"t1_door"
					};
					conflicted_parts[]=
					{
						"t3_door"
					};
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
							quantity=4;
						};
					};
				};
				class t3_door
				{
					name="(T3) Reinforced Hatch";
					id=4;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t1_door",
						"t1_wall_logs_horizontal"
					};
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
							quantity=20;
						};
						class Material2
						{
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=4;
						};
						class Material3
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=5;
						};
					};
				};
				class t3_wall_concrete_bricks
				{
					name="(T3) Concrete Roof";
					id=5;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t1_wall_logs_horizontal"
					};
					collision_data[]={};
					build_action_type=4;
					dismantle_action_type=2;
					material_type=2;
					class Materials
					{
						class Material1
						{
							type="BBP_Mortar_Mix";
							slot_name="Material_Mortar";
							quantity=1;
						};
						class Material2
						{
							type="BBP_Concrete_Brick_Pile";
							slot_name="Material_BBP_Concrete_Brick_Pile";
							quantity=2;
						};
					};
				};
				class stair
				{
					name="Stairs";
					id=6;
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
				class t2_metal
				{
					name="(T2) Sheet Metal";
					id=7;
					required_parts[]=
					{
						"t1_wall_logs_horizontal"
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
							quantity=3;
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
					id=8;
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
