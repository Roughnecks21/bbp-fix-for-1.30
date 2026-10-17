/* modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
        UIScriptedMenu menu = NULL;
        switch (id)
        {
            case MENU_CBUI_MENU:
                menu = new ConstructionBenchUI;
                if (menu) menu.SetID(id);
                break;
            default:
                menu = super.CreateScriptedMenu(id);
                break;
        }

        return menu;
    }
} */