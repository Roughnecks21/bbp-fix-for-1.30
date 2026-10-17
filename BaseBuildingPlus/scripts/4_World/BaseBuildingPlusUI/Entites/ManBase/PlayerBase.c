/*
# PlayerBase.c
#
# © 2021 BaseBuildingPlus Development Team
# BaseBuildingPlus Mod
# www.basebuildingplus.com
#
# All Rights Reserved.See License File For Further Information
#
*/

modded class PlayerBase
{
  protected bool m_BookMenuToggle;

  void ToggleBookReading()
	{
		m_BookMenuToggle = !m_BookMenuToggle;
	}
	bool IsReadingBook()
	{
		return m_BookMenuToggle;
	}
}