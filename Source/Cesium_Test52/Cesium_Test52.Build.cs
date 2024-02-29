// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cesium_Test52 : ModuleRules
{
	public Cesium_Test52(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "ImageWrapper"});
        PrivateDependencyModuleNames.AddRange(new string[] { "CesiumRuntime" });

        CppStandard = CppStandardVersion.Cpp17;
    }
}
