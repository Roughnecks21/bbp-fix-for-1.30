class CfgPatches
{
	class BaseBuildingPlus_bFloor
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
	class BBP_Floor_Kit: BBP_KIT_BASE
	{
		scope=2;
		displayName="(Large/Small) Floor Kit";
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
	class BBP_Bfloor_Hologram: Inventory_Base
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
	class BBP_Bfloor: BBP_WALL_BASE
	{
		scope=2;
		displayName="Large Floor";
		descriptionShort="A sturdy wooden wall.";
		model="\BaseBuildingPlus\BBP_Building\floor\BFloor\BBP_Sfloor.p3d";
		attachments[]={
			"BBP_Plaster",
			"BBP_Carpet",
			"Wall_Camonet",
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Material_Nails",
			"Material_FPole_WoodenLog2",
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
					"Wall_Camonet"
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
			class Carpet
			{
				name="Carpet";
				description="";
				attachmentSlots[]=
				{
					"BBP_Carpet"
				};
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
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=5;
						};
					};
				};
				class t1_wall_logs_horizontal
				{
					name="(T1) Wooden Floor";
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
							quantity=10;
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
					name="(T2) Sheet Metal";
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
				class t3_wall_concrete_bricks
				{
					name="(T3) Concrete Floor";
					id=4;
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
				class hologram_collision
				{
					name="Hologram Collision";
					id=5;
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
	class BBP_Sfloor_Hologram: Inventory_Base
	{
		scope=2;
		displayName="Large Floor Hologram";
		descriptionShort="xD";
		model="\BaseBuildingPlus\BBP_Building\hologram\sfloor\placing_hologram_sfloor.p3d";
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
	class BBP_Sfloor: BBP_WALL_BASE
	{
		scope=2;
		displayName="Small Floor";
		descriptionShort="A sturdy floor.";
		model="\BaseBuildingPlus\BBP_Building\floor\SFloor\BBP_Sfloor.p3d";
		attachments[]={
			"Material_BBP_Concrete_Brick_Pile",
			"Material_Mortar",
			"Material_Nails",
			"Material_WoodenPlanks",
			"Material_MetalSheets"
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
					"Material_BBP_Concrete_Brick_Pile",
					"Material_Mortar",
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
							quantity=5;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=3;
						};
					};
				};
				class t1_wall_logs_horizontal
				{
					name="(T1) Wooden Floor";
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
							quantity=5;
						};
						class Material2
						{
							type="WoodenPlank";
							slot_name="Material_WoodenPlanks";
							quantity=3;
						};
					};
				};
				class t3_wall_concrete_bricks
				{
					name="(T3) Concrete Floor";
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
					material_type=1;
					class Materials
					{
						class Material1
						{
							type="BBP_Concrete_Brick_Pile";
							slot_name="Material_BBP_Concrete_Brick_Pile";
							quantity=1;
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
							quantity=5;
						};
					};
				};
				class hologram_collision
				{
					name="Hologram Collision";
					id=5;
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
