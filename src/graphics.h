#pragma once
#include "raylib.h"
#include "daytime.h"
#include <cstdio>
#include "state.h"
#include "audio.h"

struct Graphics
{
    Texture2D startscreen;
    Texture2D startscreen_spritesheet;
    Texture2D startscreen_objects_spritesheet;
    Texture2D themechoice;
    Texture2D themechoice_spritesheet;

    Texture2D morning;
    Texture2D daylight;
    Texture2D night;

    Texture2D forrest_morning;
    Texture2D forrest_daylight;
    Texture2D forrest_night;

    Texture2D vulcan_morning;
    Texture2D vulcan_daylight;
    Texture2D vulcan_night;

    Texture2D homeButton;

    Texture2D icon_beach;
    Texture2D icon_forrest;
    Texture2D icon_vulcan;

    Texture2D vulcan_morning_object_spritesheet;
    Texture2D vulcan_daylight__object_spritesheet;
    Texture2D vulcan_night_spritesheet;
    Texture2D vulcan_night_object_spritesheet;

    Texture2D beach_morning_spritesheet;
    Texture2D beach_morning_object_spritesheet;
    Texture2D beach_daylight_spritesheet;
    Texture2D beach_daylight_object_spritesheet;
    Texture2D beach_night_spritesheet;
    Texture2D beach_night_object_spritesheet;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics graphics, Daytime currentDayTime, State& currentState, int currentFrameStartscreen,int currentFrameObjects,int currentThemeFrame,int currentObjektFrame);
void UnloadGraphics(Graphics& graphics);
void DrawClock(int currentHour, int currentMinute,State currentState);
void DrawHomeButton(Graphics graphics);
void UpdateHomeButton(Graphics graphics,State& currentState,Audio& audio);
void UpdateStartscreen(State& currentState,Audio& audio);
void UpdateThemeChoice(Graphics graphics, State& currentState,Audio& audio);
void DrawThemeChoiceExtras(Graphics graphics);
void DrawThemeChoiceAnimation(Graphics  graphics, int currentThemeChoiceFrame);
