// dllmain.cpp : Defines the entry point for the DLL application.
#include "TKEventManager.h"
TKEventManager* PluginEventManager = nullptr;

YYTKStatus Unload()
{
	// Cleanup
	return YYTKStatus::YYTK_OK;
}

DllExport YYTKStatus PluginEntry(YYTKPlugin* PluginObject)
{
	PluginEventManager = new TKEventManager("Plastik", PluginObject, Unload);

	if (PmGetPluginAttributes(PluginEventManager->mThisPlugin, PluginEventManager->mPluginAttributes) == YYTK_OK)
	{
		PmCreateCallback(
			PluginEventManager->mPluginAttributes,
			PluginEventManager->mCallbackAttributes,
			reinterpret_cast<FNEventHandler>(PluginEventManager->Callback),
			EVT_CODE_EXECUTE,
			PluginEventManager); // Pass self to function to access vars in static member fnc
	}

	return YYTKStatus::YYTK_OK;
}


