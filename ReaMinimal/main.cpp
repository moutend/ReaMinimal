#include "stdafx.h"
#include <windows.h>

#define REAPERAPI_IMPLEMENT

#include "ReaMinimal.h"

using namespace std;

class ReaTest : IReaperControlSurface {
	public:
	ReaTest() {
		// do nothing
	}

	virtual ~ReaTest() {
		// do nothing
	}

	virtual const char* GetTypeString() override {
		return "ReaTest";
	}

	virtual const char* GetDescString() override {
		return "Plugin for testing";
	}

	virtual const char* GetConfigString() override {
		return "";
	}

	virtual void SetSurfaceSelected(MediaTrack* track, bool selected) override {
		ShowConsoleMsg("SetSurfaceSelected");
	}

	virtual void SetPlayState(bool play, bool pause, bool rec) override {
		ShowConsoleMsg("SetPlayState");
	}
};

ReaTest* rt = nullptr;

extern "C" REAPER_PLUGIN_DLL_EXPORT int REAPER_PLUGIN_ENTRYPOINT(REAPER_PLUGIN_HINSTANCE hInstance, reaper_plugin_info_t* rec) {
	if (rec) {
		if (rec->caller_version != REAPER_PLUGIN_VERSION || !rec->GetFunc || REAPERAPI_LoadAPI(rec->GetFunc) != 0) {
			// Incompatible
			return 0;
		}
		// Load
		rt = new ReaTest();
		rec->Register("csurf_inst", (void*)rt);
		return 1;
	} else {
		// Unload
		delete rt;
		return 0;
	}
}
