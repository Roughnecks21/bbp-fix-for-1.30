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
		int recipeIndex = Recipies.Find(recipe);
		if (recipeIndex < 0) return;
		if (GetGame().IsServer())
		{
			CraftServer(recipeIndex, player);
		}
		else if (GetGame().IsClient())
		{
			RPCSingleParam(CRAFTRPC, new Param1<int>(recipeIndex), true);
		}
	}

	void CraftServer(int recipeIndex, PlayerBase player)
	{
		if (!GetGame().IsServer()) return;
		if (!player) return;
		if (!Recipies || recipeIndex < 0 || recipeIndex >= Recipies.Count()) return;
		if (vector.Distance(player.GetPosition(), GetPosition()) > 10) return;

		BBP_Workbench workbench = BBP_Workbench.Cast(GetHierarchyParent());
		if (!workbench) return;
		if (workbench.GetCraftingBook() != this) return;
		if (!workbench.Has_Tools()) return;

		BBPRecipeBase selectedRecipe = Recipies.Get(recipeIndex);
		if (!selectedRecipe) return;
		if (!GetGame().ConfigIsExisting("CfgVehicles " + selectedRecipe.GetResult())) return;
		array<autoptr BBPRecipeItem> requiredItems = selectedRecipe.GetRequiredItems();
		if (!requiredItems) return;

		// Check every requirement before taking a single item.
		foreach (BBPRecipeItem requiredItem : requiredItems)
		{
			if (!requiredItem || requiredItem.Quantity <= 0) return;
			if (!workbench.DeductMats_check(requiredItem.ItemClassName, requiredItem.Quantity)) return;
		}
		foreach (BBPRecipeItem requiredCost : requiredItems)
		{
			workbench.DeductMats(requiredCost.ItemClassName, requiredCost.Quantity);
		}
		GetGame().CreateObject(selectedRecipe.GetResult(), workbench.GetPosition() + "0 0.9 0");
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (!GetGame().IsServer() || rpc_type != CRAFTRPC) return;
		if (!sender) return;
		Param1<int> rpcData;
		if (!ctx.Read(rpcData)) return;
		CraftServer(rpcData.param1, FindPlayerByIdentity(sender));
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
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Wall Kit", "BBP_Wall_Kit", new BBPRecipePreviewItem("BBP_Bwall", {"frame","t1_door","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Door Kit", "BBP_Door_Kit", new BBPRecipePreviewItem("BBP_BDoor", {"frame","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3) }, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Floor Kit", "BBP_Floor_Kit", new BBPRecipePreviewItem("BBP_Bfloor", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Roof Kit", "BBP_Roof_Kit", new BBPRecipePreviewItem("BBP_Broof", {"frame","t1_door","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Gate Kit", "BBP_Gate_Kit", new BBPRecipePreviewItem("BBP_RGate", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Garage Door Kit", "BBP_SGate_Kit", new BBPRecipePreviewItem("BBP_SGate", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("Ramp Kit", "BBP_Ramp_Kit", new BBPRecipePreviewItem("BBP_Bramp", {"frame"}, "0 45 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("Stair Kit", "BBP_Stair_Kit", new BBPRecipePreviewItem("BBP_Bstair", {"frame"}, "0 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Window Kit", "BBP_Window_Kit", new BBPRecipePreviewItem("BBP_BWindow", {"frame","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Half Wall Kit", "BBP_Half_Wall_Kit", new BBPRecipePreviewItem("BBP_Half_Bwall", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("Pillar Kit", "BBP_Pillar_Kit", new BBPRecipePreviewItem("BBP_Bpillar", {"frame"}, "0 0 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Hanger Roof Kit", "BBP_Hanger_Roof_Kit", new BBPRecipePreviewItem("BBP_LHanger_Roof", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Triangle Foundation Kit", "BBP_Triangle_Foundation_Kit", new BBPRecipePreviewItem("BBP_Triangle_Foundation", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Foundation Kit", "BBP_Foundation_Kit", new BBPRecipePreviewItem("BBP_BFoundation", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Roof Hatch Kit", "BBP_Roof_Hatch_Kit", new BBPRecipePreviewItem("BBP_Roof_Hatch", {"frame","t1_wall_logs_horizontal", "stair"}, "25 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Floor Hatch Kit", "BBP_Floor_Hatch_Kit", new BBPRecipePreviewItem("BBP_Floor_Hatch", {"frame","t1_wall_logs_horizontal", "stair"}, "25 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));		
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Slope Roof Kit", "BBP_Slope_Roof_Kit", new BBPRecipePreviewItem("BBP_Slope_Roof", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Slope Wall Kit", "BBP_Slope_Wall_Kit", new BBPRecipePreviewItem("BBP_Left_Slope_Wall", {"frame","t1_wall_planks"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Triangle Floor Kit", "BBP_Triangle_Floor_Kit", new BBPRecipePreviewItem("BBP_Triangle_Bfloor", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1-2-3) Triangle Roof Kit", "BBP_Triangle_Roof_Kit", new BBPRecipePreviewItem("BBP_Triangle_Broof", {"frame","t1_wall_logs_horizontal"}, "-45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T1) Barbwire Barrier Kit", "BBP_Barbwire_Fence_Kit", new BBPRecipePreviewItem("BBP_Barbwire_Fence", {"frame","t1_wall_logs_horizontal"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T2) Chain Link Fence Kit", "BBP_Mesh_Fence_Kit", new BBPRecipePreviewItem("BBP_Mesh_Fence", {"frame","t2_metal","t2_metal_2"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T2) Chain Link Gate Kit", "BBP_Mesh_Gate_Kit", new BBPRecipePreviewItem("BBP_Mesh_Gate", {"frame","t2_metal","t2_door","t2_metal_2"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T2) Metal Floor Mesh Kit", "BBP_Floor_Mesh_Kit", new BBPRecipePreviewItem("BBP_Floor_Mesh", {"frame","t2_metal"}, "45 180 200"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("(T2) Metal Stair Kit", "BBP_Metal_Stair_Kit", new BBPRecipePreviewItem("BBP_Metal_Stair", {"frame","railing_1","railing_2"}, "0 180 180"), { new BBPRecipeItem("Nail", 3), new BBPRecipeItem("WoodenPlank", 3)}, {}));
		AddNewRecipe(new BBPRecipeBase("Step Ladder Kit", "BBP_Step_Ladder_Kit", new BBPRecipePreviewItem("BBP_Step_Ladder_Kit", {}, "-15 0 0"), { new BBPRecipeItem("Nail", 10), new BBPRecipeItem("WoodenPlank", 10)}, {}));
	}
	
	override string GetBookTitle(){
		return "BBP Crafting";
	}
}
