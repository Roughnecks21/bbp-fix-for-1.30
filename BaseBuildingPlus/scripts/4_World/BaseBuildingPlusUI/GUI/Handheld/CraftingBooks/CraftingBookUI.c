class CraftingBookUI extends UIScriptedMenu
{
	protected TextWidget 								m_MainItemTitle;
	protected Widget 									m_UIItems;
	protected ButtonWidget 								m_CraftButton;
	protected ButtonWidget 								m_DiscordLinkButton;
	protected ButtonWidget 								m_BBPTitleButton;
	protected Widget 									m_RequiredItemsGrid;
	//protected Widget 									m_RequiredToolsGrid;
	protected ItemPreviewWidget 						m_MainItemPreveiw;
	
	protected BBPRecipeBase 					m_BBPRecipeBase;
	protected autoptr BBPRecipeItem						m_RecipeItem1;
	protected autoptr BBPRecipeItem						m_RecipeItem2;
	protected autoptr BBPRecipeItem						m_RecipeItem3;
	protected autoptr BBPRecipeItem						m_RecipeItem4;
	protected autoptr BBPRecipeItem						m_RecipeItem5;
	protected autoptr BBPRecipeItem						m_RecipeItem6;
	protected autoptr BBPRecipeItem						m_RecipeItem7;
	protected BBP_CRAFTINGBOOK_BASE 					m_Book;
	
	autoptr array<autoptr RequiredItemWidget> 			m_RequiredItemWidgets;
	autoptr array<autoptr RecipieButtonWidget> 			m_RecipieButtonWidgets;
	//autoptr array<autoptr RequiredToolsWidget> 		m_RequiredToolsWidgets;
	
	InventoryItem 										m_PreviewItem;
	
	bool tempisCrafting = false;// HENNY ADDED
	
	void ~CraftingBookUI(){
		if (m_RequiredItemWidgets){
			delete m_RequiredItemWidgets;
		}
		//if (m_RequiredToolsWidgets){
		//	delete m_RequiredToolsWidgets;
		//}
	}
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("BaseBuildingPlus/GUI/layouts/Handheld/Book.layout");
		
		m_MainItemTitle 		= TextWidget.Cast(layoutRoot.FindAnyWidget("MainItemTitle"));
		m_UIItems 				= Widget.Cast(layoutRoot.FindAnyWidget("UIItems"));
		m_RequiredItemsGrid 	= Widget.Cast(layoutRoot.FindAnyWidget("RequiredItemsGrid"));
		//m_RequiredToolsGrid 	= Widget.Cast(layoutRoot.FindAnyWidget("RequiredToolsGrid"));
		m_MainItemPreveiw 		= ItemPreviewWidget.Cast(layoutRoot.FindAnyWidget("MainItemPreveiw"));
		m_CraftButton 			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("CraftButton"));
		m_DiscordLinkButton		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("DiscordLink"));
		m_BBPTitleButton		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("BBPTitle"));
		return layoutRoot;
	}

    override void OnShow()
    {
        super.OnShow();
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        PPEffects.SetBlurMenu(0.3);
    }

    override void OnHide()
    {
        super.OnHide();
		GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().GetHud().Show(true);
        GetGame().GetUIManager().Back();
        PPEffects.SetBlurMenu(0);
    }

    override void Update( float timeslice )
	{
		super.Update( timeslice );
		
		if( GetGame() && GetGame().GetInput() && GetGame().GetInput().LocalPress("UAUIBack", false) )
		{
			OnHide();
		}
		
		// Compute affordability for all materials. The server repeats these checks.
		if (!m_CraftButton) return;
		BBP_Workbench obfv_bench;
		if (m_Book) obfv_bench = BBP_Workbench.Cast(m_Book.GetHierarchyParent());
		bool obfv_canCraft = obfv_bench && m_BBPRecipeBase && !tempisCrafting;
		if (obfv_canCraft)
		{
			obfv_canCraft = obfv_bench.Has_Tools();
			array<autoptr BBPRecipeItem> obfv_items = m_BBPRecipeBase.GetRequiredItems();
			if (!obfv_items) obfv_canCraft = false;
			if (obfv_items)
			{
				foreach (BBPRecipeItem obfv_item : obfv_items)
				{
					if (!obfv_item || !obfv_bench.DeductMats_check(obfv_item.ItemClassName, obfv_item.Quantity))
					{
						obfv_canCraft = false;
						break;
					}
				}
			}
		}
		m_CraftButton.Show(true);
		m_CraftButton.Enable(obfv_canCraft);
	}
	
	void SetEntity(EntityAI entity){
		m_Book = BBP_CRAFTINGBOOK_BASE.Cast(entity);
		if (m_Book){
			array<autoptr BBPRecipeBase> Recipies = m_Book.GetRecipes();
			if (!Recipies || Recipies.Count() < 1){return;}
			int i = 0;
			if (m_RecipieButtonWidgets){
				delete m_RecipieButtonWidgets;
			}
			m_RecipieButtonWidgets = new array<autoptr RecipieButtonWidget>;
			for (i = 0; i< Recipies.Count(); i++){
				m_RecipieButtonWidgets.Insert(new RecipieButtonWidget(m_UIItems, this,Recipies.Get(i)));
			}
			SetRecipe(Recipies.Get(0));
		}
	}
		
	//players can spam to get more kits without taking the materials JUST A QUICK HACK //HENNY ADDED
	override bool OnClick( Widget w, int x, int y, int button )
	{		
		if (w == m_CraftButton && m_Book && m_BBPRecipeBase) 
		{
			Print("[BBP-CRAFT-DIAG] CLIENT: Craft button clicked, sending request for " + m_BBPRecipeBase.GetResult());
			m_Book.Craft(m_BBPRecipeBase);
			tempisCrafting = true;// HENNY ADDED
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( time_buffer, 400, false); // HENNY ADDED
			
			return true;
		}
		
		if(w == m_DiscordLinkButton)
		{
			GetGame().OpenURL( "https://basebuildingplus.fandom.com/wiki/Building_Recipes" );
			return true;
		}
		if(w == m_BBPTitleButton)
		{
			//GetGame().OpenURL( "https://discord.gg/tVcCBqvZmF" );
			return true;
		}
		return super.OnClick(w, x, y, button);
	}
	
	void time_buffer()// HENNY ADDED
	{
		if(tempisCrafting)
		{
			tempisCrafting = false;
		}
	}
	
	void SetRecipe(BBPRecipeBase recipe) {
		int i = 0;
		m_BBPRecipeBase = BBPRecipeBase.Cast(recipe);
		//Set Up Required 
		m_MainItemTitle.SetText(m_BBPRecipeBase.GetTitle());
		array<autoptr BBPRecipeItem> requiredItems = recipe.GetRequiredItems();
		if (m_RequiredItemWidgets){
			delete m_RequiredItemWidgets;
		}
		m_RequiredItemWidgets = new array<autoptr RequiredItemWidget>;
		for (i = 0; i < requiredItems.Count(); i++){
			m_RequiredItemWidgets.Insert(new RequiredItemWidget(m_RequiredItemsGrid, this, requiredItems.Get(i)));
		}
			
			
		/* //Set Up Required Tools
		autoptr array<autoptr BBPRecipeTool> requiredTools = recipe.GetRequiredTools();
		if (m_RequiredToolsWidgets){
			delete m_RequiredToolsWidgets;
		}
		m_RequiredToolsWidgets = new array<autoptr RequiredToolsWidget>;
		for (i = 0; i < requiredTools.Count(); i++){
			m_RequiredToolsWidgets.Insert(new RequiredToolsWidget(m_RequiredToolsGrid, this, requiredTools.Get(i)));
		} */
		
		if (m_PreviewItem)
		{
			GetGame().ObjectDelete(m_PreviewItem);
		}
		// Temporary diagnostic: report why the normal Craft button eligibility may fail.
		BBP_Workbench diagBench;
		if (m_Book) diagBench = BBP_Workbench.Cast(m_Book.GetHierarchyParent());
		if (!diagBench)
		{
			Print("[BBP-CRAFT-DIAG] CLIENT: crafting book has no BBP_Workbench parent");
		}
		else
		{
			if (diagBench.Has_Tools()) Print("[BBP-CRAFT-DIAG] CLIENT: tools OK");
			else Print("[BBP-CRAFT-DIAG] CLIENT: Has_Tools failed (tape measure or handsaw slot)");
			array<autoptr BBPRecipeItem> diagRequirements = recipe.GetRequiredItems();
			if (!diagRequirements)
			{
				Print("[BBP-CRAFT-DIAG] CLIENT: required-items array missing");
			}
			else
			{
				foreach (BBPRecipeItem diagItem : diagRequirements)
				{
					if (!diagItem) Print("[BBP-CRAFT-DIAG] CLIENT: null requirement");
					else if (!diagBench.DeductMats_check(diagItem.ItemClassName, diagItem.Quantity)) Print("[BBP-CRAFT-DIAG] CLIENT: insufficient attached " + diagItem.ItemClassName);
					else Print("[BBP-CRAFT-DIAG] CLIENT: material OK " + diagItem.ItemClassName);
				}
			}
		}
		BBPRecipePreviewItem previewItem = recipe.GetPreviewItem();
		m_PreviewItem = InventoryItem.Cast(GetGame().CreateObject(previewItem.ItemClassName,"0 0 0", true, false, true ));
		if (m_PreviewItem)
		{
			BaseBuildingBase basebuilding;
			if (Class.CastTo(basebuilding, m_PreviewItem))
			{
				Construction previewConstruction = basebuilding.GetConstruction();
				PlayerBase previewPlayer = PlayerBase.Cast(GetGame().GetPlayer());
				if (previewConstruction && previewPlayer && previewItem.Parts)
				{
					for (i = 0; i < previewItem.Parts.Count(); i++)
					{
						string previewPartName = previewItem.Parts.Get(i);
						if (previewConstruction.GetConstructionPart(previewPartName))
						{
							basebuilding.OnPartBuiltServer(previewPlayer, previewPartName, AT_BUILD_PART);
						}
					}
				}
			}
			m_MainItemPreveiw.SetItem( m_PreviewItem );
			
			m_MainItemPreveiw.SetModelPosition( Vector(0,0,0) );
			
			m_MainItemPreveiw.SetModelOrientation( previewItem.Orientation );
			
			m_MainItemPreveiw.SetPos( 0, 0);
			
			m_MainItemPreveiw.SetSize( 1, 1);
			
			m_MainItemPreveiw.SetView( 0 );
			
		}
	}
}


class RecipieButtonWidget extends ScriptedWidgetEventHandler {
	
	static string 				m_LayoutPath = "BaseBuildingPlus/GUI/layouts/Handheld/RecipieItem.layout";
	
	CraftingBookUI 				m_Parent;
	BBPRecipeBase				m_Recipe;
	
	Widget						m_Root;
	Widget 						m_ParentWidget;
	
	ButtonWidget				m_Button;
	
	void RecipieButtonWidget(Widget parent, CraftingBookUI bookMenu, BBPRecipeBase recipeBase){
		if (!recipeBase || !bookMenu || !parent){return;}
		
		m_ParentWidget 		= Widget.Cast(parent);
		m_Root				= GetGame().GetWorkspace().CreateWidgets(m_LayoutPath, m_ParentWidget, true);
		
		m_Parent	 		= CraftingBookUI.Cast(bookMenu);
		
		m_Button			= ButtonWidget.Cast(m_Root.FindAnyWidget("Button"));
		m_Recipe			= BBPRecipeBase.Cast(recipeBase);
		
		
		m_Button.SetText(m_Recipe.Title);
		
		m_Root.SetHandler(this);
		m_Root.Show(true);
	}
		
	void ~RecipieButtonWidget(){
		
		Print("RecipieButtonWidget ItemDeleted");
		m_ParentWidget.RemoveChild(m_Root);
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{		
		if (w == m_Button) 
		{
			if(m_Recipe)
			{
				m_Parent.SetRecipe(m_Recipe);
				return true;
			}
		}
		return super.OnClick(w, x, y, button);
	}
	
	
}

class RequiredItemWidget extends ScriptedWidgetEventHandler {
	
	static string 				m_LayoutPath = "BaseBuildingPlus/GUI/layouts/Handheld/RequiredItems.layout";
	
	CraftingBookUI 				m_Parent;
	BBPRecipeItem				m_RecipeItem;
	
	Widget						m_Root;
	Widget 						m_ParentWidget;
	
	TextWidget				m_RequiredItemName;
	TextWidget				m_RequireItemCount;
	ItemPreviewWidget		m_MainItemPreveiw;
	
	InventoryItem 			m_PreviewItem;
	
	void RequiredItemWidget(Widget parent, CraftingBookUI bookMenu, BBPRecipeItem recipeItem){
		if (!recipeItem || !bookMenu || !parent){return;}
		
		m_ParentWidget 				= Widget.Cast(parent);
		m_Root						= GetGame().GetWorkspace().CreateWidgets(m_LayoutPath, m_ParentWidget, true);
		
		m_Parent	 				= CraftingBookUI.Cast(bookMenu);
		
		m_RequiredItemName			= TextWidget.Cast(m_Root.FindAnyWidget("RequiredItemName"));
		m_RequireItemCount			= TextWidget.Cast(m_Root.FindAnyWidget("RequireItemCount"));
		m_MainItemPreveiw			= ItemPreviewWidget.Cast(m_Root.FindAnyWidget("MainItemPreveiw"));
		m_RecipeItem				= BBPRecipeItem.Cast(recipeItem);
		
		
		
		m_PreviewItem = InventoryItem.Cast(GetGame().CreateObject(m_RecipeItem.ItemClassName,"0 0 0", true, false, true ));
		
		if (!m_PreviewItem){
			Error2("BBP", "Failed to create preview item " + m_RecipeItem.ItemClassName);
			return;
		}
		
		Print(m_PreviewItem);
		
		m_MainItemPreveiw.SetItem( m_PreviewItem );
				
		m_MainItemPreveiw.SetModelPosition( Vector(0,0,0) );
		
		//m_MainItemPreveiw.SetModelOrientation( Vector(0,0,0) );
		
		m_MainItemPreveiw.SetPos( 0, 0);
		
		m_MainItemPreveiw.SetSize( 1, 1);
		
		m_MainItemPreveiw.SetView( 0 );
				
		
		string quantity = "X " + m_RecipeItem.Quantity;
		
		m_RequireItemCount.SetText( quantity );
		
		m_RequiredItemName.SetText( m_PreviewItem.GetDisplayName() );
		
		m_Root.SetHandler(this);
		m_Root.Show(true);
	}
		
	void ~RequiredItemWidget(){
		Print("RequiredItemWidget ItemDeleted");
		m_ParentWidget.RemoveChild(m_Root);
		GetGame().ObjectDelete(m_PreviewItem);
	}
		
	
}

/*class RequiredToolsWidget extends ScriptedWidgetEventHandler {
	
	static string 				m_LayoutPath = "BaseBuildingPlus/GUI/layouts/Handheld/RequiredTools.layout";
	
	CraftingBookUI 				m_Parent;
	BBPRecipeTool				m_RecipeTool;
	
	Widget						m_Root;
	Widget 						m_ParentWidget;
	
	TextWidget				m_RequiredToolName;
	TextWidget				m_RequireItemCount;
	ItemPreviewWidget		m_MainItemPreveiw;
	
	InventoryItem 			m_PreviewItem;
	
	void RequiredToolsWidget(Widget parent, CraftingBookUI bookMenu, BBPRecipeTool recipeTool){
		if (!recipeTool || !bookMenu || !parent){return;}
		
		m_ParentWidget 				= Widget.Cast(parent);
		m_Root						= GetGame().GetWorkspace().CreateWidgets(m_LayoutPath, m_ParentWidget, true);
		
		m_Parent	 				= CraftingBookUI.Cast(bookMenu);
		
		m_RequiredToolName			= TextWidget.Cast(m_Root.FindAnyWidget("RequiredToolName"));
		m_MainItemPreveiw			= ItemPreviewWidget.Cast(m_Root.FindAnyWidget("MainItemPreveiw"));
		m_RecipeTool				= BBPRecipeTool.Cast(recipeTool);
		
		
		
		m_PreviewItem = InventoryItem.Cast(GetGame().CreateObject(m_RecipeTool.ToolClassName,"0 0 0", true, false, true ));
		
		if (!m_PreviewItem){
			Error2("BBP", "Failed to create preview tool " + m_RecipeTool.ToolClassName);
			return;
		}
		
		Print(m_PreviewItem);
		
		m_MainItemPreveiw.SetItem( m_PreviewItem );
				
		m_MainItemPreveiw.SetModelPosition( Vector(0,0,0) );
		
		//m_MainItemPreveiw.SetModelOrientation( Vector(0,0,0) );
		
		m_MainItemPreveiw.SetPos( 0, 0);
		
		m_MainItemPreveiw.SetSize( 1, 1);
		
		m_MainItemPreveiw.SetView( 0 );
				
		
		m_RequiredToolName.SetText( m_PreviewItem.GetDisplayName() );
		
		m_Root.SetHandler(this);
		m_Root.Show(true);
	}
		
	void ~RequiredToolsWidget(){
		Print("RequiredToolsWidget ItemDeleted");
		m_ParentWidget.RemoveChild(m_Root);
		GetGame().ObjectDelete(m_PreviewItem);
	}
		
}*/