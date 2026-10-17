modded class TruckBattery
{
    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        EntityAI parent = GetHierarchyParent();
        if (parent && parent.GetCompEM())
            parent.GetCompEM().SwitchOff();
    }
}
