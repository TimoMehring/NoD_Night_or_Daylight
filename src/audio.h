#pragma once
#include "raylib.h"
#include "daytime.h"

struct Audio{
    Music birds;
};

Audio LoadAudio();
void PlayAudio(Audio& audio, Daytime currentDayTime);