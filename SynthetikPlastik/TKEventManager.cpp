#include "TKEventManager.h"

bool TKEventManager::EventCallbackVecGetFunc(TKEventCallback TKECB, std::vector<TKEventCallback>::iterator& OutIterator, std::vector<TKEventCallback> &EventCallbacks)
{
	OutIterator = std::find(EventCallbacks.begin(), EventCallbacks.end(), TKECB);// Try to find the iterator
	if (OutIterator == EventCallbacks.end())
	{
		return false;
	}
	return true;
}

bool TKEventManager::RegisterEventCallback(std::string EventTypeStr, TKEventCallback FunctionCB)
{
	// Set new callback function pointer
	auto it = mEventCallbackFunctions.find(EventTypeStr);

	if (it == mEventCallbackFunctions.end()) // Doesn't contain vector for callback
	{
		std::vector<TKEventCallback> ptrVec = std::vector<TKEventCallback>();
		ptrVec.push_back(FunctionCB);
		mEventCallbackFunctions.insert(std::make_pair(EventTypeStr,ptrVec));

	}
	else // Contains a vector
	{
		it->second.push_back(FunctionCB);
	}

	return true;
}

YYTKStatus TKEventManager::Callback(YYTKCodeEvent* CodeEvent, void*)
{
	// Loop through vectors and see if registered
}
