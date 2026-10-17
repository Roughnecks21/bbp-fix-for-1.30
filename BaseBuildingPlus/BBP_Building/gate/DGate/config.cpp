class CfgPatches
{
	class BaseBuildingPlus_dGate
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
	class BBP_GATE_BASE;
	class BBP_DGate_Hologram: Inventory_Base
	{
		scope=2;
		displayName="T1 Door Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\gate\DGate\proxies\hologram_placing.p3d";
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
	class BBP_DGate: BBP_GATE_BASE
	{
		scope=2;
		displayName="Double Garage Door";
		descriptionShort="Door";
		model="\BaseBuildingPlus\BBP_Building\gate\DGate\BBP_D_Gate.p3d";
		attachments[]=
		{
			"Wall_Camonet",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Att_CombinationLock",
			"Att_CodeLock",
			"Att_ExpansionCodeLock",
			"Material_Nails",
			"Material_FPole_WoodenLog2",
			"Material_WoodenPlanks",
			"Material_MetalSheets"
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
					"Wall_Camonet",
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
					"Material_FPole_WoodenLog2",
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
			class Frame: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal_2: AnimSourceHidden
			{
			};
			class T2_Metal: AnimSourceHidden
			{
			};
			class T2_Metal_2: AnimSourceHidden
			{
			};
			class Wall_Camonet: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks_2: AnimSourceHidden
			{
			};
			class T1_Frame_Rotate: AnimRotate
			{
			};
			class T1_Wall_Logs_Horizontal_Rotate: AnimRotate
			{
			};
			class T1_Wall_Logs_Horizontal_2_Rotate: AnimRotate
			{
			};
			class T3_Wall_Concrete_Bricks_Rotate: AnimRotate
			{
			};
			class T3_Wall_Concrete_Bricks_2_Rotate: AnimRotate
			{
			};
			class Wall_Interact_Rotate: AnimRotate
			{
			};
			class T2_Metal_Rotate: AnimRotate
			{
			};
			class T2_Metal_2_Rotate: AnimRotate
			{
			};
		};
		class Construction
		{
			class wall_build
			{
				class frame
				{
					name="Gate Frame";
					is_base=1;
					is_gate=1;
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
							quantity=4;
						};
					};
				};
				class t1_wall_logs_horizontal
				{
					name="(T1) Right Wood Door";
					id=2;
					required_parts[]=
					{
						"frame"
					};
					conflicted_parts[]=
					{
						"t3_wall_concrete_bricks"
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
							quantity=12;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=8;
						};
					};
				};
				class t1_wall_logs_horizontal_2
				{
					name="(T1) Left Wood Door";
					id=3;
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
							type="Nail";
							slot_name="Material_Nails";
							quantity=12;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=8;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Left Sheet Metal";
					id=4;
					required_parts[]=
					{
						"t1_wall_logs_horizontal_2"
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
				class t2_metal_2
				{
					name="(T2) Right Sheet Metal";
					id=5;
					required_parts[]=
					{
						"t1_wall_logs_horizontal_2"
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
				class t3_wall_concrete_bricks
				{
					name="(T3) Right Reinforced Door";
					id=6;
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
							quantity=1;
						};
					};
				};
				class t3_wall_concrete_bricks_2
				{
					name="(T3) Left Reinforced Door";
					id=7;
					required_parts[]=
					{
						"t3_wall_concrete_bricks"
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
							quantity=1;
						};
					};
				};
			};
		};
	};
};
