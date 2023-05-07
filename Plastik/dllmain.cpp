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
	PluginEventManager = new TKEventManager("Amogus", PluginObject, Unload);

	PluginAttributes_t* pluginAttributes = nullptr;
	if (PmGetPluginAttributes(PluginEventManager->mThisPlugin, pluginAttributes) == YYTK_OK)
	{
		PmCreateCallback(pluginAttributes,
			PluginEventManager->mCallbackAttributes,
			reinterpret_cast<FNEventHandler>(PluginEventManager->Callback),
			EVT_CODE_EXECUTE,
			PluginEventManager); // Pass self to function to access vars in static member fnc
	}

	return YYTKStatus::YYTK_OK;
}


