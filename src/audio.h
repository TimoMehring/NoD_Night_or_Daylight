#pragma once
#include "raylib.h"
#include "daytime.h"

struct Audio{
    Music birds;
    Music nightwater;
};

Audio LoadAudio();
void PlayAudio(Audio& audio, Daytime currentDayTime);