#pragma once
#include "raylib.h"
#include "logic.h"

Texture2D LoadGraphics(Daytime currentDayTime);
void DrawGraphics(Texture2D dayTime);
void UnloadGraphics(Texture2D dayTime);