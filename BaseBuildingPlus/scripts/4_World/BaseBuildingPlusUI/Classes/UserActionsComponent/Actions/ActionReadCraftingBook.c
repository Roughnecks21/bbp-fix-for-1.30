class ActionReadCraftingBook extends ActionSingleUseBase
{
	void ActionReadCraftingBook()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		//m_Animation = "break";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		BBP_CRAFTINGBOOK_BASE book;
		BBP_Workbench bench;
		return (Class.CastTo(book, item) || ((Class.CastTo(bench, target.GetObject()) || Class.CastTo(bench, target.GetParent())) && Class.CastTo(book, bench.GetCraftingBook())));
	}
	
	override string GetText()
	{
		return "#read";
	}

	override void OnExecuteClient( ActionData action_data )
	{
		CraftingBookUI craftingbookui = CraftingBookUI.Cast( GetGame().GetUIManager().EnterScriptedMenu(MENU_CRAFTINGBOOKUI, NULL) );
		BBP_CRAFTINGBOOK_BASE book;
		BBP_Workbench bench;
		if (Class.CastTo(book, action_data.m_MainItem) || (Class.CastTo(bench, action_data.m_Target.GetObject()) && Class.CastTo(book, bench.GetCraftingBook())))
			craftingbookui.SetEntity( book );
	}
	
};
class ActionReadCraftingBookOnWB: ActionInteractBase
{
	
	void ActionReadCraftingBookOnWB()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		BBP_CRAFTINGBOOK_BASE book;
		BBP_Workbench bench;
		return (Class.CastTo(book, item) || ((Class.CastTo(bench, target.GetObject()) || Class.CastTo(bench, target.GetParent())) && Class.CastTo(book, bench.GetCraftingBook())));
	}
	
	override string GetText()
	{
		return "#read";
	}

	override void OnExecuteClient( ActionData action_data )
	{
		CraftingBookUI craftingbookui = CraftingBookUI.Cast( GetGame().GetUIManager().EnterScriptedMenu(MENU_CRAFTINGBOOKUI, NULL) );
		BBP_CRAFTINGBOOK_BASE book;
		BBP_Workbench bench;
		if (Class.CastTo(book, action_data.m_MainItem) || (Class.CastTo(bench, action_data.m_Target.GetObject()) && Class.CastTo(book, bench.GetCraftingBook())))
			craftingbookui.SetEntity( book );
	}
	
}