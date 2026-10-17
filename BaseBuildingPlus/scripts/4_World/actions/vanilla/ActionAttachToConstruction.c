modded class ActionAttachToConstruction
{
    // Keep DayZ's own action setup and inventory transfer; only choose the BBP slot.
    override protected int FindAndTranslateAttachmentSlot(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!player || !target || !item) return InventorySlots.INVALID;

        BBP_BASE bbp = BBP_BASE.Cast(target.GetObject());
        if (!bbp) return super.FindAndTranslateAttachmentSlot(player, target, item);

        if (item.IsKindOf("DigitalCodeLock"))
        {
            if (!bbp.IsBBPGate() || !bbp.HasFullyConstructedGate() || bbp.IsOpened() || bbp.BBP_HasLock()) return InventorySlots.INVALID;

            int slotId = InventorySlots.GetSlotIdFromString("Att_CodeLock");
            if (slotId != InventorySlots.INVALID && bbp.GetInventory().CanAddAttachmentEx(item, slotId))
                return slotId;

            return InventorySlots.INVALID;
        }

        // Preserve the old BBP combination-lock fallback.
        if (item.IsKindOf("CombinationLock"))
        {
            int originalSlot = super.FindAndTranslateAttachmentSlot(player, target, item);
            if (originalSlot != InventorySlots.INVALID) return originalSlot;

            InventoryLocation location = new InventoryLocation;
            if (bbp.GetInventory().FindFreeLocationFor(item, FindInventoryLocationType.ATTACHMENT, location))
                return location.GetSlot();

            return InventorySlots.INVALID;
        }

        return super.FindAndTranslateAttachmentSlot(player, target, item);
    }
}
