class CfgPatches
{
	class BaseBuildingPlus_lGate
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
	class BBP_Gate_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(Right/Left) Gate Kit";
		descriptionShort="Press the left arrow key to cycle.";
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
	class BBP_LGate_Hologram: Inventory_Base
	{
		scope=2;
		displayName="T1 Door Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\gate\LGate\proxies\proxy_frame_hologram_placing.p3d";
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
	class BBP_LGate: BBP_GATE_BASE
	{
		scope=2;
		displayName="Left Gate";
		descriptionShort="Door";
		model="\BaseBuildingPlus\BBP_Building\gate\LGate\BBP_L_Gate.p3d";
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
				animPeriod=0.02;
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
			class T2_Metal: AnimSourceHidden
			{
			};
			class Wall_Camonet: AnimSourceHidden
			{
			};
			class T1_Wall_Logs_Horizontal: AnimSourceHidden
			{
			};
			class T3_Wall_Concrete_Bricks: AnimSourceHidden
			{
			};
			class T1_Frame_Rotate: AnimRotate
			{
			};
			class T1_Wall_Logs_Horizontal_Rotate: AnimRotate
			{
			};
			class T3_Wall_Concrete_Bricks_Rotate: AnimRotate
			{
			};
			class Wall_Interact_Rotate: AnimRotate
			{
			};
			class T2_Metal_Rotate: AnimRotate
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
					name="(T1) Wooden Gate";
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
							quantity=24;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=16;
						};
					};
				};
				class t3_wall_concrete_bricks
				{
					name="(T3) Reinforced Gate";
					id=3;
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
							quantity=3;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Sheet Metal";
					id=4;
					required_parts[]=
					{
						"t1_wall_logs_horizontal"
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
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=4;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=20;
						};
					};
				};
			};
		};
	};
};
