#pragma once
#include "raylib.h"
#include "daytime.h"

struct Graphics
{
    Texture2D morning;
    Texture2D daylight;
    Texture2D night;
};

Graphics LoadGraphics();
void DrawGraphics(Graphics graphics, Daytime currentDayTime, int currentHour, int currentMinute);
void UnloadGraphics(Graphics graphics);