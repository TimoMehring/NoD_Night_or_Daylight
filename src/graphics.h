#pragma once
#include "raylib.h"
#include "daytime.h"
#include <cstdio>
#include "state.h"

struct Graphics
{
    Texture2D startscreen;
    Texture2D morning;
    Texture2D daylight;
    Texture2D night;

    Texture2D forrest_morning;
    Texture2D forrest_daylight;
    Texture2D forrest_night;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics graphics, Daytime currentDayTime, State& currentState);
void UnloadGraphics(Graphics graphics);
void DrawClock(int currentHour, int currentMinute);