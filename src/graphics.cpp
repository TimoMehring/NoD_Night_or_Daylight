#include "graphics.h"
#include "raylib.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.startscreen = LoadTexture("assets/startscreen.png");
    graphics.themechoice = LoadTexture("assets/themechoice.png");
    graphics.morning = LoadTexture("assets/morning.png");
    graphics.daylight = LoadTexture("assets/daylight.png");
    graphics.night = LoadTexture("assets/night.png");
    graphics.forrest_morning = LoadTexture("assets/forrest_morning.png");
    graphics.forrest_daylight = LoadTexture("assets/forrest_daylight.png");
    graphics.forrest_night = LoadTexture("assets/forrest_night.png");
    graphics.homeButton = LoadTexture("assets/homebutton.png");
    return graphics; 
}

void DrawGraphics(Graphics graphics, Daytime currentDayTime,State& currentState)
{
    //ClearBackground(GRAY);

    if(currentState == State::Startscreen){
        DrawTextureEx(graphics.startscreen,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        return;
    }

    if(currentState == State::ThemeChoice){
        DrawTextureEx(graphics.themechoice,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        return;
    }

    if (currentDayTime == Daytime::Morning)
    {
        if(currentState == State::ThemeBeach){
            DrawTextureEx(graphics.morning,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        else if(currentState == State::ThemeForrest){
            DrawTextureEx(graphics.forrest_morning,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
    }
    else if (currentDayTime == Daytime::Daylight)
    {
        if(currentState == State::ThemeBeach){
            DrawTextureEx(graphics.daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        else if(currentState == State::ThemeForrest){
            DrawTextureEx(graphics.forrest_daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
    }
    else if (currentDayTime == Daytime::Night)
    {  
        if (currentState == State::ThemeBeach){
            DrawTextureEx(graphics.night,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        else if(currentState == State::ThemeForrest){
            DrawTextureEx(graphics.forrest_night,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        
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

void DrawHomeButton(Graphics graphics){
    //Rectangle HomeButton = {0.0, 0.0, graphics.homeButton.width, graphics.homeButton.height};
    DrawTextureEx(graphics.homeButton, {20.0f,10.0f},0.0f,5.0f,WHITE);
}

void UnloadGraphics(Graphics& graphics)
{
    UnloadTexture(graphics.startscreen);
    UnloadTexture(graphics.themechoice);
    UnloadTexture(graphics.morning);
    UnloadTexture(graphics.daylight);
    UnloadTexture(graphics.night);
    UnloadTexture(graphics.forrest_morning);
    UnloadTexture(graphics.forrest_daylight);
    UnloadTexture(graphics.forrest_night);
    UnloadTexture(graphics.homeButton);
}

void UpdateHomeButton(Graphics graphics,State& currentState){
    Rectangle homeButton = {20.0, 10.0, static_cast<float>(graphics.homeButton.width)*5,static_cast<float>(graphics.homeButton.height)*5};
    
    Vector2 mousePosition = GetMousePosition();
    
    if(CheckCollisionPointRec(mousePosition,homeButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        
        currentState = State::Startscreen;

        
    }
}

void UpdateStartscreen(State& currentState){
    if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        currentState = State::ThemeChoice;
    }
}

void UpdateThemeChoice(Graphics graphics, State& currentState){

}