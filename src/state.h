#pragma once
#include "raylib.h"

enum class State{
    Startscreen,
    ThemeChoice,
    ThemeBeach,
    ThemeForrest,
    ThemeVulcan
};

void UpdateScreen(State& currentState);
/* void UpdateHomeButton(Graphics graphics,State& currentState); */