modded class ActionUnmountBarbedWire
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();

		if (targetObject && targetObject.IsInherited(BBP_BASE))
		{
			BBP_BASE bbpbase = BBP_BASE.Cast(targetObject);

			BarbedWire barbed_wire = BarbedWire.Cast(bbpbase.FindAttachmentBySlotName("Wall_BarbedWire_1"));
			BarbedWire barbed_wire2 = BarbedWire.Cast(bbpbase.FindAttachmentBySlotName("Wall_BarbedWire_2"));

			if (bbpbase && bbpbase.isflat())
			{
				if (bbpbase && bbpbase.HasProperDistanceFlatBBP("inside", player))
				{
					if (barbed_wire && barbed_wire.IsMounted() && !barbed_wire.IsRuined())
					{
						m_SlotNameValue = "Wall_BarbedWire_1";
						return true;
					}
					if (barbed_wire2 && barbed_wire2.IsMounted() && !barbed_wire2.IsRuined())
					{
						m_SlotNameValue = "Wall_BarbedWire_2";
						return true;
					}
				}
			}

			if (bbpbase && !bbpbase.isflat())
			{
				if (bbpbase && bbpbase.HasProperDistanceBBP("inside", player))
				{
					if (barbed_wire && barbed_wire.IsMounted() && !barbed_wire.IsRuined())
					{
						m_SlotNameValue = "Wall_BarbedWire_1";
						return true;
					}
					if (barbed_wire2 && barbed_wire2.IsMounted() && !barbed_wire2.IsRuined())
					{
						m_SlotNameValue = "Wall_BarbedWire_2";
						return true;
					}
				}
			}
		}

		return super.ActionCondition(player, target, item);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_Target.GetObject().IsInherited(BBP_BASE))
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast(action_data.m_Target.GetObject());
			// unmount and refresh parent
			BarbedWire wire = BarbedWire.Cast(base_building.FindAttachmentBySlotName(m_SlotNameValue));
			wire.SetMountedState(false);
		}
		else
			super.OnFinishProgressServer(action_data);
	}
}