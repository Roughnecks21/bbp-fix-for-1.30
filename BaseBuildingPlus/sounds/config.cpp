class CfgPatches
{
	class BaseBuildingPlus_Sounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Sounds_Effects"
		};
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class BBP_METAL_Open_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_METAL_Open_Soundshader"
		};
	};
	class BBP_METAL_Close_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_METAL_Close_Soundshader"
		};
	};
	class BBP_METAL_Door_Open_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_METAL_Door_Open_Soundshader"
		};
	};
	class BBP_METAL_Door_Close_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_METAL_Door_Close_Soundshader"
		};
	};
	class BBP_WOOD_Door_Open_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_WOOD_Door_Open_Soundshader"
		};
	};
	class BBP_WOOD_Door_Close_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_WOOD_Door_Close_Soundshader"
		};
	};
	class BBP_METAL_GATE_Open_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_METAL_GATE_Open_Soundshader"
		};
	};
	class BBP_METAL_GATE_Close_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_METAL_GATE_Close_Soundshader"
		};
	};
	class BBP_WOOD_HATCH_Open_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_WOOD_HATCH_Open_Soundshader"
		};
	};
	class BBP_WOOD_HATCH_Close_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"BBP_WOOD_HATCH_Close_Soundshader"
		};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class BBP_METAL_Open_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\MetalGateMesh\doorMetalGateMeshOpen_1",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_METAL_Close_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\MetalGateMesh\doormetalgatemeshclose_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\MetalGateMesh\doormetalgatemeshclose_2",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\MetalGateMesh\doormetalgatemeshclose_3",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_METAL_Door_Open_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalsmallopenabit_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalsmallopenabit_2",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalsmallopenabit_3",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_METAL_Door_Close_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalclose_3",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalclose_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalclose_2",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\metal\doormetalclose_4",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_WOOD_Door_Open_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\woodsmall\doorwoodsmallopen_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodsmall\doorwoodsmallopen_2",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodsmall\doorwoodsmallopen_3",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodsmall\doorwoodsmallopen_4",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedopen_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedopen_3",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_WOOD_Door_Close_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\woodnolatch\doorwoodnolatchclose_3",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodnolatch\doorwoodnolatchclose_4",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedclose_4",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedclose_3",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_METAL_GATE_Open_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\metalcontainer\doormetalcontaineropen_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\metalcontainer\doormetalcontaineropen_2",
				1
			}
		};
		volume=0.90794575;
	};
	class BBP_METAL_GATE_Close_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\metalcontainer\doormetalcontainerclose_1",
				1
			}
		};
		volume=0.90794575;
	};
	class BBP_WOOD_HATCH_Close_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedclose_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedclose_2",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedclose_3",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedclose_4",
				1
			}
		};
		volume=0.70794576;
	};
	class BBP_WOOD_HATCH_Open_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedopen_1",
				1
			},
			
			{
				"\DZ\sounds\environment\buildings\doors\woodshed\doorwoodshedopen_3",
				1
			}
		};
		volume=0.70794576;
	};
};
