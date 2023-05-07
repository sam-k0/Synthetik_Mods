#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define YYSDK_PLUGIN
#include "SDK/SDK.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef bool (*TKEventCallback)(CCode* CodeObj, CInstance* SelfInst, CInstance* OtherInst, void*);

class TKEventManager
{
private:
	std::map<std::string,std::vector<TKEventCallback>> mEventCallbackFunctions;
	std::string mPluginName;
	FNPluginUnload UnloadCallback;

	// Returns: Wether OutIterator is a valid iterator or .end()
	bool EventCallbackVecGetFunc(TKEventCallback TKECB, std::vector<TKEventCallback>::iterator& OutIterator, std::vector<TKEventCallback> &EventCallbacks);

public:
	YYTKPlugin* mThisPlugin;
	CallbackAttributes_t* mCallbackAttributes = nullptr;

	bool RegisterEventCallback(std::string EventTypeStr, TKEventCallback FunctionCB);

	// TODO: Rewrite this to static and pass void* arg self....
	YYTKStatus Callback(YYTKCodeEvent* CodeEvent, void*);
	 
	TKEventManager(std::string PluginName, YYTKPlugin* ThisPlugin, FNPluginUnload OnUnload);

	// Static members
	void Print(std::string Str, Color c = CLR_DEFAULT)
	{
		PrintMessage(c, (mPluginName + ":" + Str).c_str());
	}
};

