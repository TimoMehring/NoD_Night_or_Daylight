#include "graphics.h"
#include "raylib.h"

Texture2D LoadGraphics(Daytime currentDayTime){
    Texture2D daytime;
    if(currentDayTime == Daytime::Morning){
        daytime = LoadTexture("assets/morning.png");
    }else if(currentDayTime == Daytime::Daylight){
        daytime = LoadTexture("assets/daylight.png");
    }else if(currentDayTime == Daytime::Night){
        daytime = LoadTexture("assets/night.png");
    }
    
    return daytime;
}

void DrawGraphics(Texture2D dayTime){
    ClearBackground(GRAY);
    DrawTexture(dayTime, 0, 0, WHITE);
}

void UnloadGraphics(Texture2D dayTime){
    UnloadTexture(dayTime);
}
