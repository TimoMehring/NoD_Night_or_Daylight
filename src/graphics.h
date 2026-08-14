#pragma once
#include "raylib.h"
#include "daytime.h"
#include <cstdio>
#include "theme.h"

struct Graphics
{
    Texture2D morning;
    Texture2D daylight;
    Texture2D night;

    Texture2D forrest_morning;
    Texture2D forrest_daylight;
    Texture2D forrest_night;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics graphics, Daytime currentDayTime, Theme& currentTheme);
void UnloadGraphics(Graphics graphics);
void DrawClock(int currentHour, int currentMinute);