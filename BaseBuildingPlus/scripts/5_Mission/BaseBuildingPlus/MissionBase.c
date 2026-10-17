modded class MissionBase {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu) {
            switch (id) {
           /* case MENU_WORKBENCHUI_MENU:
                menu = new WorkbenchUI;
                break;*/
            case MENU_CRAFTINGBOOKUI:
                menu = new CraftingBookUI;
                break;
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
}