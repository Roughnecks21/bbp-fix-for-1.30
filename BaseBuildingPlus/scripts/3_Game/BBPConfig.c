//thank you wardog, CheckIdentity, mod for the HOW TO on this 
//thank you Helkhiana as well, for teaching jest how do

class CementMixerLocations
{
    vector position;
    vector orientation;

	void SetCementMixerLocations(vector m_position, vector m_orientation)
	{
    	position = m_position;
    	orientation = m_orientation;
	}
}

class BBPConfig
{
	bool BBP_DisableCraftVanillaFence;
	bool BBP_DisableCraftVanillaWatchtower;
	int BBP_BaseBuildAnywhere;
	int BBP_FlagBuildAnywhere;
	int BBP_TentBuildAnywhere;
	int BBP_VanillaBuildAnywhere;
	bool BBP_CraftWorkbenchRequiresPermit;
	bool BBP_SetInfiniteLifetime;
	bool BBP_AdvancedRotation;
	bool BBP_FloatingPlacement;
	bool BBP_CanRaiseAndLowerHologram;
	bool BBP_HologramHasCollision;
	bool BBP_InventoryToggle;
	bool BBP_BarbedWireRemoveOutside;
	bool BBP_RequireVanillaCodeLockBattery = true;
	bool BBP_CanAttachFlashlights;
	bool BBP_CanAttachXmaslights;
	bool BBP_CanAttachCamonets;
	//bool BBP_CanAttachBarbedWire; 			//Not working
	bool BBP_CanAttachWallpaper;
	bool BBP_CanAttachCarpet;
	bool BBP_CanAttachPlaster;
	bool BBP_RaidOnlyDoors;
	bool BBP_DisableDestroy;
	bool BBP_DisableDismantle;
	int BBP_BuildTime;
	int BBP_DismantleTime;
	int BBP_Tier1RaidTime;
	int BBP_Tier2RaidTime;
	int BBP_Tier3RaidTime;
	int BBP_BaseBuildToolDamage;
	int BBP_BaseDismantleToolDamage;
	int BBP_Tier1RaidToolDamage;
	int BBP_Tier2RaidToolDamage;
	int BBP_Tier3RaidToolDamage;
	
	ref array<string> BBP_BuildTools;
	ref array<string> BBP_DismantleTools;
	ref array<string> BBP_Tier1RaidTools;
	ref array<string> BBP_Tier2RaidTools;
	ref array<string> BBP_Tier3RaidTools;
	
	int BBP_CementMixerTime;

	ref array<ref CementMixerLocations> BBP_CementMixerLocations;
}

class BBPGlobals
{
	private static ref BBPConfig m_BBPConfig = NULL;
	private static const int MAX_CONFIG_LINES = 500;
	private static const string configPath = "$profile:\\BaseBuildingPlus\\BBP_Settings.json";
	private static const string configRoot = "$profile:\\BaseBuildingPlus";
	
	static BBPConfig Get()
	{
		if (m_BBPConfig == NULL)
		{
			Set();
		}
		return m_BBPConfig;
	}

	static void Set()
	{
		m_BBPConfig = LoadConfig();
	}

	private static BBPConfig LoadConfig()
	{
		BBPConfig config = new BBPConfig;

		if (!FileExist(configPath))
        {
            Print("[BBP] 'BBP_Settings' does not exist, creating...");
            CreateDefaultConfig(config);
        }

		JsonFileLoader<BBPConfig>.JsonLoadFile(configPath, config);
		Print("[BBP] 'BBP_Settings' found, loading...");
		return config;
	}

	private static void CreateDefaultConfig(BBPConfig config)
	{
		config.BBP_DisableCraftVanillaFence = false;
		config.BBP_DisableCraftVanillaWatchtower = false;
		config.BBP_BaseBuildAnywhere = true;
		config.BBP_FlagBuildAnywhere = false;
		config.BBP_TentBuildAnywhere = false;
		config.BBP_VanillaBuildAnywhere = false;
		config.BBP_CraftWorkbenchRequiresPermit = false;
		config.BBP_SetInfiniteLifetime = true;
		config.BBP_AdvancedRotation = true;
		config.BBP_FloatingPlacement = true;
		config.BBP_CanRaiseAndLowerHologram = true;
		config.BBP_HologramHasCollision = false;
		config.BBP_InventoryToggle = true;
		config.BBP_BarbedWireRemoveOutside = true;
		config.BBP_RequireVanillaCodeLockBattery = true;
		config.BBP_CanAttachFlashlights = false;
		config.BBP_CanAttachXmaslights = false;
		config.BBP_CanAttachCamonets = true;
		//config.BBP_CanAttachBarbedWire = true; //Not working
		config.BBP_CanAttachWallpaper = true;
		config.BBP_CanAttachCarpet = true;
		config.BBP_CanAttachPlaster = true;
		config.BBP_RaidOnlyDoors = false;
		config.BBP_DisableDestroy = false;
		config.BBP_DisableDismantle = false;
		config.BBP_BuildTime = 1;
		config.BBP_DismantleTime = 2;
		config.BBP_Tier1RaidTime = 300;
		config.BBP_Tier2RaidTime = 600;
		config.BBP_Tier3RaidTime = 1200;
		config.BBP_BaseBuildToolDamage = 1;
		config.BBP_BaseDismantleToolDamage = 1;
		config.BBP_Tier1RaidToolDamage = 50;
		config.BBP_Tier2RaidToolDamage = 100;
		config.BBP_Tier3RaidToolDamage = 1000;
		config.BBP_BuildTools = { "Hammer", "Hatchet"};
		config.BBP_DismantleTools = { "Hatchet", "Crowbar"};
		config.BBP_Tier1RaidTools = { "SledgeHammer", "FirefighterAxe", "WoodAxe"};
		config.BBP_Tier2RaidTools = { "SledgeHammer", "FirefighterAxe"};
		config.BBP_Tier3RaidTools = { "SledgeHammer"};
		config.BBP_CementMixerTime = 252;
		
		ref array<ref CementMixerLocations> CMLocations = new ref array<ref CementMixerLocations>;

		CementMixerLocations loc = new CementMixerLocations;
		CementMixerLocations loc2 = new CementMixerLocations;
		CementMixerLocations loc3 = new CementMixerLocations;
		CementMixerLocations loc4 = new CementMixerLocations;
		CementMixerLocations loc5 = new CementMixerLocations;
		CementMixerLocations loc6 = new CementMixerLocations;
		CementMixerLocations loc7 = new CementMixerLocations;
		CementMixerLocations loc8 = new CementMixerLocations;

		loc.SetCementMixerLocations("10054.915039 5.998347 1824.814575", "140.320999 0 0");	//ELEKTRO
		loc2.SetCementMixerLocations("8025.974121 14.320039 3112.555664", "-134.317001 0.000000 -0.000001");//CHERNO
		loc3.SetCementMixerLocations("2259.967285 185.386688 5228.343262", "31.421862 0.000000 0.000000");//ZELNO
		loc4.SetCementMixerLocations("13320.810547 9.184664 6120.320313", "0.488000 0.002672 1.681928");//SOLNICHY
		loc5.SetCementMixerLocations("11916.333008 28.763134 14286.380859", "105.104500 0.000000 0.000000");//NOVO
		loc6.SetCementMixerLocations("8005.100098 129.204407 12594.500000", "-12.629600 -0.734632 0.240260");//UNKNOWN
		loc7.SetCementMixerLocations("5216.392578 340.970093 9886.897461", "-109.342987 -0.042234 0.007777");//NWAF1
		loc8.SetCementMixerLocations("2943.952881 220.784470 12637.526367", "-158.010208 0.018145 -0.044932");//UNKNOWN

		CMLocations.Insert(loc);
		CMLocations.Insert(loc2);
		CMLocations.Insert(loc3);
		CMLocations.Insert(loc4);
		CMLocations.Insert(loc5);
		CMLocations.Insert(loc6);
		CMLocations.Insert(loc7);
		CMLocations.Insert(loc8);

		config.BBP_CementMixerLocations = CMLocations;
		
        if (!FileExist(configRoot))
        {
            Print("[BBP] '" + configRoot + "' does not exist, creating...");
            MakeDirectory(configRoot);
        }
        JsonFileLoader<BBPConfig>.JsonSaveFile(configPath, config);
	}
};
