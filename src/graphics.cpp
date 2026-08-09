#include "graphics.h"
#include "raylib.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.morning = LoadTexture("assets/morning.png");
    graphics.daylight = LoadTexture("assets/daylight.png");
    graphics.night = LoadTexture("assets/night.png");
    return graphics; 
}

void DrawGraphics(Graphics graphics, Daytime currentDayTime, int currentHour, int currentMinute)
{
    ClearBackground(GRAY);

    if (currentDayTime == Daytime::Morning)
    {
        DrawTexture(graphics.morning, 0, 0, WHITE);
        //DrawTextureEx(graphics.morning,{0.0f, 0.0f},0.0f,8.0f,WHITE); // Later for all 3 (Morning,Daylight,Night) 
        DrawText(TextFormat("%02d:%02d", currentHour, currentMinute), 300, 100, 30, WHITE);
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