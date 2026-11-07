#ifdef EXPANSIONMODBASEBUILDING
modded class ExpansionActionAttachCodeLock
{
    // BBP uses ActionAttachToConstruction and Att_CombinationLock instead.
    override int GetCodeLockSlotId(ActionTarget target, out ItemBase targetItem)
    {
        if (target && (BBP_BASE.Cast(target.GetObject()) || BBP_BASE.Cast(target.GetParent())))
        {
            targetItem = null;
            return InventorySlots.INVALID;
        }

        return super.GetCodeLockSlotId(target, targetItem);
    }
}
#endif
