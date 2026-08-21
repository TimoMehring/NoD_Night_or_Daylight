#pragma once
#include "raylib.h"
#include "daytime.h"
#include "state.h"

struct Audio{
    Music birds;
    Music nightwater;
    Music vulcan;
    Music startscreen;
    Sound button;
};

Audio LoadAudio();
void PlayAudio(Audio& audio, Daytime currentDayTime,State currentState);
void UnlaodAudio(Audio& audio);