using UnrealBuildTool;

public class WindowsAudioCapture : ModuleRules
{
	public WindowsAudioCapture(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"WindowsAudioCapture/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"WindowsAudioCapture/Private",
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "RenderCore",
                "ShaderCore",
                "Kiss_FFT",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Win32)
        {
            if (WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2015)
            {
                PublicAdditionalLibraries.Add("legacy_stdio_definitions.lib");
            }
        }

        AddEngineThirdPartyPrivateStaticDependencies(Target, "Kiss_FFT");
    }
}
