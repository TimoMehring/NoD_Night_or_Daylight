#pragma once
#include "raylib.h"
#include "daytime.h"
#include <cstdio>

struct Graphics
{
    Texture2D morning;
    Texture2D daylight;
    Texture2D night;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics graphics, Daytime currentDayTime);
void UnloadGraphics(Graphics graphics);
void DrawClock(int currentHour, int currentMinute);