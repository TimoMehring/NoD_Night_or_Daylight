#include "graphics.h"
#include "raylib.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.morning = LoadTexture("assets/morning.png");
    graphics.daylight = LoadTexture("assets/daylight.png");
    graphics.night = LoadTexture("assets/night.png");
    graphics.forrest_morning = LoadTexture("assets/forrest_morning.png");
    graphics.forrest_daylight = LoadTexture("assets/forrest_daylight.png");
    graphics.forrest_night = LoadTexture("assets/forrest_night.png");
    return graphics; 
}

void DrawGraphics(Graphics graphics, Daytime currentDayTime,Theme& currentTheme)
{
    ClearBackground(GRAY);

    if (currentDayTime == Daytime::Morning)
    {
        if(currentTheme == Theme::Beach){
            DrawTextureEx(graphics.morning,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        else if(currentTheme == Theme::Forrest){
            DrawTextureEx(graphics.forrest_morning,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
    }
    else if (currentDayTime == Daytime::Daylight)
    {
        if(currentTheme == Theme::Beach){
            DrawTextureEx(graphics.daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        else if(currentTheme == Theme::Forrest){
            DrawTextureEx(graphics.forrest_daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
    }
    else if (currentDayTime == Daytime::Night)
    {   
        DrawTextureEx(graphics.night,{0.0f, 0.0f},0.0f,8.0f,WHITE);
    }
}

void DrawClock(int currentHour, int currentMinute)
{
    const int fontSize = 60;

    char hourText[3];
    char minuteText[3];

    snprintf(hourText, sizeof(hourText), "%02d", currentHour);
    snprintf(minuteText, sizeof(minuteText), "%02d", currentMinute);

    int hourWidth = MeasureText(hourText, fontSize);
    int colonWidth = MeasureText(":", fontSize);
    int minuteWidth = MeasureText(minuteText, fontSize);

    int totalWidth = hourWidth + colonWidth + minuteWidth;

    int startX = (800 - totalWidth) / 2;
    int startY = 80;

    // Stunde
    DrawText(hourText, startX -10, startY, fontSize, WHITE);

    // Doppelpunkt
    bool showColon = ((int)GetTime() % 2 == 0);

    if (showColon)
    {
        DrawText(":", startX + hourWidth, startY, fontSize, WHITE);
    }

    // Minuten
    DrawText(minuteText, startX + 10 + hourWidth + colonWidth, startY, fontSize, WHITE);
}

void UnloadGraphics(Graphics graphics)
{
    UnloadTexture(graphics.morning);
    UnloadTexture(graphics.daylight);
    UnloadTexture(graphics.night);
    UnloadTexture(graphics.forrest_morning);
    UnloadTexture(graphics.forrest_daylight);
    UnloadTexture(graphics.forrest_night);
}