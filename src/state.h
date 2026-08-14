#pragma once
#include "raylib.h"

enum class State{
    Startscreen,
    ThemeChoice,
    ThemeBeach,
    ThemeForrest
};

void UpdateScreen(State& currentState);