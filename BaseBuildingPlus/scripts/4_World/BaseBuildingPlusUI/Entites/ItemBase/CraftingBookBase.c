/*
# CraftingBookBase.c
#
# © 2021 BaseBuildingPlus Development Team
# BaseBuildingPlus Mod
# www.basebuildingplus.com
#
# All Rights Reserved.See License File For Further Information
# 
*/

class BBP_CRAFTINGBOOK_BASE extends ItemBase
{
	void BBP_CRAFTINGBOOK_BASE(){
		RegisterRecipies();
	}
	
	static int CRAFTRPC = 810780378;
	
	autoptr array<autoptr BBPRecipeBase> Recipies;
	
	protected void AddNewRecipe(BBPRecipeBase recipe){
		if (!recipe) {return;}
		if (!Recipies){
			Recipies = new array<autoptr BBPRecipeBase>;
		}
		Recipies.Insert(recipe);
	}
	
	void RegisterRecipies(){
		
	}
	
	void Craft(BBPRecipeBase recipe, PlayerBase player = NULL)
	{
		if (!recipe || !Recipies) return;
		int obfv_recipeIndex = Recipies.Find(recipe);
		if (obfv_recipeIndex < 0) return;
		if (GetGame().IsServer())
		{
			obfm_CraftServer(obfv_recipeIndex, player);
		}
		else if (GetGame().IsClient())
		{
			RPCSingleParam(CRAFTRPC, new Param1<int>(obfv_recipeIndex), true);
		}
	}

	void obfm_CraftServer(int obfv_recipeIndex, PlayerBase player)
	{
		// Temporary crafting diagnostics; security checks and crafting costs unchanged.
		if (!GetGame().IsServer()) return;
		if (!player) { Print("[BBP-CRAFT-DIAG] SERVER: player lookup failed"); return; }
		if (!Recipies || obfv_recipeIndex < 0 || obfv_recipeIndex >= Recipies.Count()) { Print("[BBP-CRAFT-DIAG] SERVER: invalid recipe index"); return; }
		if (vector.Distance(player.GetPosition(), GetPosition()) > 10) { Print("[BBP-CRAFT-DIAG] SERVER: player is too far from book"); return; }

		BBP_Workbench obfv_bench = BBP_Workbench.Cast(GetHierarchyParent());
		if (!obfv_bench) { Print("[BBP-CRAFT-DIAG] SERVER: book not attached to BBP workbench"); return; }
		if (obfv_bench.GetCraftingBook() != this) { Print("[BBP-CRAFT-DIAG] SERVER: workbench book mismatch"); return; }
		if (!obfv_bench.Has_Tools()) { Print("[BBP-CRAFT-DIAG] SERVER: required tools missing"); return; }

		BBPRecipeBase obfv_recipe = Recipies.Get(obfv_recipeIndex);
		if (!obfv_recipe) { Print("[BBP-CRAFT-DIAG] SERVER: recipe missing"); return; }
		if (!GetGame().ConfigIsExisting("CfgVehicles " + obfv_recipe.GetResult())) { Print("[BBP-CRAFT-DIAG] SERVER: result classname not defined " + obfv_recipe.GetResult()); return; }
		array<autoptr BBPRecipeItem> obfv_items = obfv_recipe.GetRequiredItems();
		if (!obfv_items) { Print("[BBP-CRAFT-DIAG] SERVER: requirements missing"); return; }

		// Check every requirement before taking a single item.
		foreach (BBPRecipeItem obfv_item : obfv_items)
		{
			if (!obfv_item || obfv_item.Quantity <= 0) { Print("[BBP-CRAFT-DIAG] SERVER: invalid recipe cost"); return; }
			if (!obfv_bench.DeductMats_check(obfv_item.ItemClassName, obfv_item.Quantity)) { Print("[BBP-CRAFT-DIAG] SERVER: insufficient attached " + obfv_item.ItemClassName); return; }
		}
		foreach (BBPRecipeItem obfv_cost : obfv_items)
		{
			obfv_bench.DeductMats(obfv_cost.ItemClassName, obfv_cost.Quantity);
		}
		Print("[BBP-CRAFT-DIAG] SERVER: spawning kit " + obfv_recipe.GetResult());
		GetGame().CreateObject(obfv_recipe.GetResult(), obfv_bench.GetPosition() + "0 0.9 0");
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (!GetGame().IsServer() || rpc_type != CRAFTRPC) return;
		if (!sender) { Print("[BBP-CRAFT-DIAG] SERVER: crafting RPC has no sender"); return; }
		Param1<int> obfv_data;
		if (!ctx.Read(obfv_data)) { Print("[BBP-CRAFT-DIAG] SERVER: crafting RPC data unreadable"); return; }
		Print("[BBP-CRAFT-DIAG] SERVER: crafting RPC received");
		obfm_CraftServer(obfv_data.param1, FindPlayerByIdentity(sender));
	}

	//Simple function for finding a player based on their identity
	static PlayerBase FindPlayerByIdentity(PlayerIdentity identity) {
		if (!identity)
			return NULL;

		int highBits;
		int lowBits;
		GetGame().GetPlayerNetworkIDByIdentityID(identity.GetPlayerId(), lowBits, highBits);
		return PlayerBase.Cast(GetGame().GetObjectByNetworkId(lowBits, highBits));
	}
	
	array<autoptr BBPRecipeBase> GetRecipes(){
		return Recipies;
	}
	
	string GetBookTitle(){
		return "NULL";
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionReadCraftingBook);
	}
}

class BBP_Blueprint extends BBP_CRAFTINGBOOK_BASE{

	override void RegisterRecipies(){
		super.RegisterRecipies();
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Wall Kit", "BBP_Wall_Kit", new BBPRecipePreviewItem("BBP_Bwall", {"frame","t1_door","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Door Kit", "BBP_Door_Kit", new BBPRecipePreviewItem("BBP_BDoor", {"frame","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3) }, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Floor Kit", "BBP_Floor_Kit", new BBPRecipePreviewItem("BBP_Bfloor", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Roof Kit", "BBP_Roof_Kit", new BBPRecipePreviewItem("BBP_Broof", {"frame","t1_door","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Gate Kit", "BBP_Gate_Kit", new BBPRecipePreviewItem("BBP_RGate", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Garage Door Kit", "BBP_SGate_Kit", new BBPRecipePreviewItem("BBP_SGate", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("Ramp Kit", "BBP_Ramp_Kit", new BBPRecipePreviewItem("BBP_Bramp", {"frame"}, "0 45 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("Stair Kit", "BBP_Stair_Kit", new BBPRecipePreviewItem("BBP_Bstair", {"frame"}, "0 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Window Kit", "BBP_Window_Kit", new BBPRecipePreviewItem("BBP_BWindow", {"frame","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Half Wall Kit", "BBP_Half_Wall_Kit", new BBPRecipePreviewItem("BBP_Half_Bwall", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("Pillar Kit", "BBP_Pillar_Kit", new BBPRecipePreviewItem("BBP_Bpillar", {"frame"}, "0 0 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Hanger Roof Kit", "BBP_Hanger_Roof_Kit", new BBPRecipePreviewItem("BBP_LHanger_Roof", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Triangle Foundation Kit", "BBP_Triangle_Foundation_Kit", new BBPRecipePreviewItem("BBP_Triangle_Foundation", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Foundation Kit", "BBP_Foundation_Kit", new BBPRecipePreviewItem("BBP_BFoundation", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Roof Hatch Kit", "BBP_Roof_Hatch_Kit", new BBPRecipePreviewItem("BBP_Roof_Hatch", {"frame","t1_wall_logs_horizontal", "stair"}, "25 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Floor Hatch Kit", "BBP_Floor_Hatch_Kit", new BBPRecipePreviewItem("BBP_Floor_Hatch", {"frame","t1_wall_logs_horizontal", "stair"}, "25 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));		
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Slope Roof Kit", "BBP_Slope_Roof_Kit", new BBPRecipePreviewItem("BBP_Slope_Roof", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Slope Wall Kit", "BBP_Slope_Wall_Kit", new BBPRecipePreviewItem("BBP_Left_Slope_Wall", {"frame","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Triangle Floor Kit", "BBP_Triangle_Floor_Kit", new BBPRecipePreviewItem("BBP_Triangle_Bfloor", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Triangle Roof Kit", "BBP_Triangle_Roof_Kit", new BBPRecipePreviewItem("BBP_Triangle_Broof", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T1) Barbwire Barrier Kit", "BBP_Barbwire_Fence_Kit", new BBPRecipePreviewItem("BBP_Barbwire_Fence", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T2) Chain Link Fence Kit", "BBP_Mesh_Fence_Kit", new BBPRecipePreviewItem("BBP_Mesh_Fence", {"frame","t2_metal","t2_metal_2"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T2) Chain Link Gate Kit", "BBP_Mesh_Gate_Kit", new BBPRecipePreviewItem("BBP_Mesh_Gate", {"frame","t2_metal","t2_door","t2_metal_2"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T2) Metal Floor Mesh Kit", "BBP_Floor_Mesh_Kit", new BBPRecipePreviewItem("BBP_Floor_Mesh", {"frame","t2_metal"}, "45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("(T2) Metal Stair Kit", "BBP_Metal_Stair_Kit", new BBPRecipePreviewItem("BBP_Metal_Stair", {"frame","railing_1","railing_2"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
		AddNewRecipe(new BBPRecipeBase("Step Ladder Kit", "BBP_Step_Ladder_Kit", new BBPRecipePreviewItem("BBP_Step_Ladder_Kit", {}, "-15 0 0"), { new BBPRecipeItem("Nail", 10), new BBPRecipeItem("WoodenPlank", 10)}, { new BBPRecipeTool("BBP_TapeMeasure")}));
	}
	
	override string GetBookTitle(){
		return "BBP Crafting";
	}
}
