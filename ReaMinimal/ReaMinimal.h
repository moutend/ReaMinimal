#pragma once

#include <windows.h>

#define REAPERAPI_MINIMAL

#define REAPERAPI_WANT_MIDI_SetCC
#define REAPERAPI_WANT_CSurf_OnTrackSelection
#define REAPERAPI_WANT_CountTracks
#define REAPERAPI_WANT_CSurf_TrackToID
#define REAPERAPI_WANT_GetLastTouchedTrack
#define REAPERAPI_WANT_CSurf_OnPlay
#define REAPERAPI_WANT_ShowConsoleMsg
#define REAPERAPI_WANT_ClearConsole
#define REAPERAPI_WANT_TrackFX_GetParamName
#define REAPERAPI_WANT_CSurf_OnStop
#define REAPERAPI_WANT_CSurf_OnRecord

#include <reaper/reaper_plugin.h>
#include <reaper/reaper_plugin_functions.h>
