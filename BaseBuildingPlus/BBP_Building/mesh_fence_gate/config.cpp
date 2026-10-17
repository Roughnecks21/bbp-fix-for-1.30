class CfgPatches
{
	class BaseBuildingPlus_meshFenceGate
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
	class BBP_Mesh_Gate_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(T2) Chain Link Gate Kit";
		descriptionShort="A GATE AND IT OPENS! WOW!";
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
	class BBP_Mesh_Gate_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Large Wall Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\mesh_fence_gate\proxies\barb_hologram_placing.p3d";
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
	class BBP_Mesh_Gate: BBP_GATE_BASE
	{
		scope=2;
		displayName="Chain Link Gate";
		descriptionShort="Door";
		model="\BaseBuildingPlus\BBP_Building\mesh_fence_gate\BBP_Mesh_Gate.p3d";
		attachments[]=
		{
			"Material_BBP_BarbedWire",
			"Att_CombinationLock",
			"Att_CodeLock",
			"Att_ExpansionCodeLock",
			"Material_Nails",
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
					"Material_Nails",
					"Material_MetalSheets",
					"Material_BBP_BarbedWire"
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
			class T2_Metal: AnimSourceHidden
			{
			};
			class T2_Metal_2: AnimSourceHidden
			{
			};
			class T2_Door: AnimSourceHidden
			{
			};
			class Wall_Interact_Rotate: AnimRotate
			{
			};
			class T2_Door_Rotate: AnimRotate
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
							type="MetalPlate";
							slot_name="Material_MetalSheets";
							quantity=2;
						};
					};
				};
				class t2_metal
				{
					name="(T2) Left Door";
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
							quantity=1;
						};
						class Material2
						{
							type="Nail";
							slot_name="Material_Nails";
							quantity=10;
						};
					};
				};
				class t2_door
				{
					name="(T1) Right Door";
					id=3;
					required_parts[]=
					{
						"t2_metal"
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
							quantity=1;
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
					name="(T2) Barbwire";
					id=4;
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
							type="BarbedWire";
							slot_name="Material_BBP_BarbedWire";
						};
					};
				};
			};
		};
	};
};
