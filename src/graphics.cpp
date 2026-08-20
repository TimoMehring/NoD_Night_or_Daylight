#include "graphics.h"
#include "raylib.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.startscreen = LoadTexture("assets/startscreen.png");
    graphics.themechoice = LoadTexture("assets/themechoice.png");
    graphics.themechoice_spritesheet = LoadTexture("assets/themechoice_spritesheet.png");
    graphics.morning = LoadTexture("assets/morning.png");
    graphics.daylight = LoadTexture("assets/daylight.png");
    graphics.night = LoadTexture("assets/night.png");
    graphics.forrest_morning = LoadTexture("assets/forrest_morning.png");
    graphics.forrest_daylight = LoadTexture("assets/forrest_daylight.png");
    graphics.forrest_night = LoadTexture("assets/forrest_night.png");
    graphics.vulcan_daylight = LoadTexture("assets/vulcan_daylight.png");
    graphics.icon_vulcan = LoadTexture("assets/icon_vulcan.png");


    graphics.homeButton = LoadTexture("assets/homebutton.png");
    
    graphics.icon_beach = LoadTexture("assets/icon_beach.png");
    graphics.icon_forrest = LoadTexture("assets/icon_forrest.png");
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
        else if(currentState == State::ThemeVulcan){
            // exchange daylight texture with morning texture later
            DrawTextureEx(graphics.vulcan_daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
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
        else if(currentState == State::ThemeVulcan){
            DrawTextureEx(graphics.vulcan_daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
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
        else if(currentState == State::ThemeVulcan){
            // exchange daylight texture with night texture
            DrawTextureEx(graphics.vulcan_daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
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
    DrawTextureEx(graphics.homeButton, {20.0f,10.0f},0.0f,5.0f,WHITE);
}

void UnloadGraphics(Graphics& graphics)
{
    UnloadTexture(graphics.startscreen);
    UnloadTexture(graphics.themechoice);
    UnloadTexture(graphics.themechoice_spritesheet);
    UnloadTexture(graphics.morning);
    UnloadTexture(graphics.daylight);
    UnloadTexture(graphics.night);
    UnloadTexture(graphics.forrest_morning);
    UnloadTexture(graphics.forrest_daylight);
    UnloadTexture(graphics.forrest_night);
    UnloadTexture(graphics.vulcan_daylight);
    UnloadTexture(graphics.homeButton);
    UnloadTexture(graphics.icon_beach);
    UnloadTexture(graphics.icon_forrest);
    UnloadTexture(graphics.icon_vulcan);
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
    Rectangle beachButton = {20.0, 100.0, static_cast<float>(graphics.icon_beach.width)*7,static_cast<float>(graphics.icon_beach.height)*7};
    Rectangle forrestButton = {281.0, 100.0, static_cast<float>(graphics.icon_forrest.width)*7,static_cast<float>(graphics.icon_forrest.height)*7};
    Rectangle vulcanButton = {542.0, 100.0, static_cast<float>(graphics.icon_vulcan.width)*7,static_cast<float>(graphics.icon_vulcan.height)*7};
    Vector2 mousePosition = GetMousePosition();

    if(CheckCollisionPointRec(mousePosition,beachButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        currentState = State::ThemeBeach;
    }
    else if(CheckCollisionPointRec(mousePosition,forrestButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        currentState = State::ThemeForrest;
    }
    else if(CheckCollisionPointRec(mousePosition,vulcanButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        currentState = State::ThemeVulcan;
    }


}

void DrawThemeChoiceExtras(Graphics graphics){
    DrawTextureEx(graphics.icon_beach,{20.0f,100.0f},0.0,7.0,WHITE);
    DrawTextureEx(graphics.icon_forrest,{281.0f,100.0f},0.0f,7.0,WHITE);
    DrawTextureEx(graphics.icon_vulcan,{542.0f,100.0f},0.0,7.0,WHITE);
}

void DrawThemeChoiceAnimation(Graphics  graphics, int currentThemeChoiceFrame){
    Rectangle source{currentThemeChoiceFrame * 100.0f ,0.0f, 100.0f, 50.0f};
    Rectangle dest{0.0f,0.0f, 800.0f, 400.0f};
    DrawTexturePro(graphics.themechoice_spritesheet, source, dest,{0.0f, 0.0f}, 0.0f, WHITE);
    
}