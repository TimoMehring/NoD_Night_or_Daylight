#pragma once
#include "raylib.h"
#include "ctime"

enum class Daytime {
    Morning,
    Daylight,
    Night
};

Daytime CheckDayTime(int currentHour);
int GetCurrentHour();