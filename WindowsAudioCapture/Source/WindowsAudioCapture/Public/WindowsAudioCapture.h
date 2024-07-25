//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FWindowsAudioCaptureModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};