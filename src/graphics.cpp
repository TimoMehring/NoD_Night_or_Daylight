#include "graphics.h"
#include "raylib.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.morning = LoadTexture("assets/morning.png");
    graphics.daylight = LoadTexture("assets/daylight.png");
    graphics.night = LoadTexture("assets/night.png");
    return graphics; 
}

void DrawGraphics(Graphics graphics, Daytime currentDayTime)
{
    ClearBackground(GRAY);

    if (currentDayTime == Daytime::Morning)
    {
        DrawTexture(graphics.morning, 0, 0, WHITE);
    }
    else if (currentDayTime == Daytime::Daylight)
    {
        DrawTexture(graphics.daylight, 0, 0, WHITE);
    }
    else if (currentDayTime == Daytime::Night)
    {
        DrawTexture(graphics.night, 0, 0, WHITE);
    }
}

void UnloadGraphics(Graphics graphics)
{
    UnloadTexture(graphics.morning);
    UnloadTexture(graphics.daylight);
    UnloadTexture(graphics.night);
}