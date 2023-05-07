// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "TKEventManager.h"

YYTKStatus PluginUnload()
{
	// Cleanup
}

DllExport YYTKStatus PluginEntry(YYTKPlugin* PluginObject)
{
	return YYTKStatus::YYTK_OK;
}