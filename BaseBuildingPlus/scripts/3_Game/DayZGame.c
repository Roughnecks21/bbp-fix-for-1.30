modded class DayZGame
{
    protected ref BBPConfig m_CheckBBPConfig;

    void setBBPGlobals(BBPConfig config)
    {
        m_CheckBBPConfig = config;
    }

    BBPConfig getBBPGlobals()
    {
        return m_CheckBBPConfig;
    }

	int getBBPBuildTime()
	{
		BBPConfig config = getBBPGlobals();
		int buildTime = 5;
		buildTime = config.BBP_BuildTime;
		return buildTime;
	}

    int GetBBPRaidTime(string item)
	{
		BBPConfig config = getBBPGlobals();
		int destroyTime = -1;
		switch( item )
		{
			case "Tier1":
				destroyTime = config.BBP_Tier1RaidTime;
				break;
			case "Tier2":
				destroyTime = config.BBP_Tier2RaidTime;
				break;
			case "Tier3":
				destroyTime = config.BBP_Tier3RaidTime;
				break;
			default:
				destroyTime = config.BBP_Tier1RaidTime;
				break;
		}
		return destroyTime;
	}

	ref array<string> GetBBPBuildTools()
	{
		BBPConfig config = getBBPGlobals();
		array<string> BBP_DesiredBuildTools = {};
		BBP_DesiredBuildTools = config.BBP_BuildTools;
		return BBP_DesiredBuildTools;
	}
	
	ref array<string> GetBBPDismantleTools()
	{
		BBPConfig config = getBBPGlobals();
		array<string> BBP_DesiredDismantleTools = {};
		BBP_DesiredDismantleTools = config.BBP_DismantleTools;
		return BBP_DesiredDismantleTools;
	}

	ref array<string> GetBBPRaidToolsT1()
	{
		BBPConfig config = getBBPGlobals();
		array<string> BBP_DesiredRaidToolsT1 = {};
		BBP_DesiredRaidToolsT1 = config.BBP_Tier1RaidTools;
		return BBP_DesiredRaidToolsT1;
	}

	ref array<string> GetBBPRaidToolsT2()
	{
		BBPConfig config = getBBPGlobals();
		array<string> BBP_DesiredRaidToolsT2 = {};
		BBP_DesiredRaidToolsT2 = config.BBP_Tier2RaidTools;
		return BBP_DesiredRaidToolsT2;
	}

	ref array<string> GetBBPRaidToolsT3()
	{
		BBPConfig config = getBBPGlobals();
		array<string> BBP_DesiredRaidToolsT3 = {};
		BBP_DesiredRaidToolsT3 = config.BBP_Tier3RaidTools;
		return BBP_DesiredRaidToolsT3;
	}
	
	/*ref array<string> GetBBPRaidTools(string item)
	{
		BBPConfig config = getBBPGlobals();
		array<string> BBP_DesiredRaidTools = {};
		switch( item )
		{
			case "Tier1":
				BBP_DesiredRaidTools = config.BBP_Tier1RaidTools;
				break;
			case "Tier2":
				BBP_DesiredRaidTools = config.BBP_Tier2RaidTools;
				break;
			case "Tier3":
				BBP_DesiredRaidTools = config.BBP_Tier3RaidTools;
				break;
			default:
				BBP_DesiredRaidTools = config.BBP_Tier1RaidTools;
				break;
		}
		return BBP_DesiredRaidTools;
	}*/

	int GetBBPRaidToolDamage(string item)
	{
		BBPConfig config = getBBPGlobals();
		int destroyTime = -1;
		switch( item )
		{
			case "Tier1":
				destroyTime = config.BBP_Tier1RaidToolDamage;
				break;
			case "Tier2":
				destroyTime = config.BBP_Tier2RaidToolDamage;
				break;
			case "Tier3":
				destroyTime = config.BBP_Tier3RaidToolDamage;
				break;
			default:
				destroyTime = config.BBP_Tier1RaidToolDamage;
				break;
		}
		return destroyTime;
	}

};