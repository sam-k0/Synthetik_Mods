// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "TKEventManager.h"

TKEventManager* PluginEventManager = nullptr;

YYTKStatus Unload()
{
	// Cleanup
}

YYTKStatus InvokePEM(YYTKCodeEvent* codeEvent, void* v)
{
	PluginEventManager->Callback(codeEvent, v);
}

DllExport YYTKStatus PluginEntry(YYTKPlugin* PluginObject)
{
	PluginEventManager = new TKEventManager("Amogus", PluginObject, Unload);

	PluginAttributes_t* pluginAttributes = nullptr;
	if (PmGetPluginAttributes(PluginEventManager->mThisPlugin, pluginAttributes) == YYTK_OK)
	{
		PmCreateCallback(pluginAttributes,
			PluginEventManager->mCallbackAttributes,
			reinterpret_cast<FNEventHandler>(InvokePEM),
			EVT_CODE_EXECUTE, 
			nullptr);
	}

	return YYTKStatus::YYTK_OK;
}