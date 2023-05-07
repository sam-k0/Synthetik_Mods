// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "TKEventManager.h"

TKEventManager* PluginEventManager = nullptr;

YYTKStatus PluginUnload()
{
	// Cleanup
}

DllExport YYTKStatus PluginEntry(YYTKPlugin* PluginObject)
{
	PluginEventManager = new TKEventManager("Amogus", PluginObject);
	return YYTKStatus::YYTK_OK;
}