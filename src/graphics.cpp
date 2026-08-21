#include "graphics.h"
#include "raylib.h"

Graphics LoadGraphics(){
    Graphics graphics;
    graphics.startscreen = LoadTexture("assets/startscreen.png");
    graphics.startscreen_spritesheet = LoadTexture("assets/startscreen_spritesheet.png");
    graphics.startscreen_objects_spritesheet = LoadTexture("assets/startscreen_objects_spritesheet.png");
    graphics.themechoice = LoadTexture("assets/themechoice.png");
    graphics.themechoice_spritesheet = LoadTexture("assets/themechoice_spritesheet.png");
    graphics.morning = LoadTexture("assets/morning.png");
    graphics.daylight = LoadTexture("assets/daylight.png");
    graphics.night = LoadTexture("assets/night.png");
    graphics.forrest_morning = LoadTexture("assets/forrest_morning.png");
    graphics.forrest_daylight = LoadTexture("assets/forrest_daylight.png");
    graphics.forrest_night = LoadTexture("assets/forrest_night.png");
    graphics.vulcan_morning = LoadTexture("assets/vulcan_morning.png");
    graphics.vulcan_daylight = LoadTexture("assets/vulcan_daylight.png");
    graphics.vulcan_night = LoadTexture("assets/vulcan_night.png");
    graphics.icon_vulcan = LoadTexture("assets/icon_vulcan.png");

    graphics.vulcan_morning_object_spritesheet = LoadTexture("assets/vulcan_morning_object_spritesheet.png");
    graphics.vulcan_daylight__object_spritesheet = LoadTexture("assets/vulcan_daylight_object_spritesheet.png");
    graphics.vulcan_night_spritesheet = LoadTexture("assets/vulcan_night_spritesheet.png");
    graphics.vulcan_night_object_spritesheet = LoadTexture("assets/vulcan_night_object_spritesheet.png");


    graphics.homeButton = LoadTexture("assets/homebutton.png");
    
    graphics.icon_beach = LoadTexture("assets/icon_beach.png");
    graphics.icon_forrest = LoadTexture("assets/icon_forrest.png");
    return graphics; 
}

void DrawGraphics(Graphics graphics, Daytime currentDayTime,State& currentState,int currentFrameStartscreen, int currentFrameObjects, int currentThemeFrame, int currentObjektFrame)
{
    //ClearBackground(GRAY);

    if(currentState == State::Startscreen){

        Rectangle source{currentFrameStartscreen * 100.0f ,0.0f, 100.0f, 50.0f};
        Rectangle dest{0.0f,0.0f, 800.0f, 400.0f};
        DrawTexturePro(graphics.startscreen_spritesheet, source, dest,{0.0f, 0.0f}, 0.0f, WHITE);

        Rectangle sourceObjects{currentFrameObjects*100.0f, 0.0f, 100.0f, 50.0f};
        DrawTexturePro(graphics.startscreen_objects_spritesheet, sourceObjects, dest, {0.0f, 0.0f}, 0.0f, WHITE);
        DrawText("NoD",345, 25, 60, BLACK);
        DrawText("Night or Daylight",150, 90, 60, BLACK);
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
            Rectangle source{currentObjektFrame * 100.0f ,0.0f, 100.0f, 50.0f};
            Rectangle dest{0.0f,0.0f, 800.0f, 400.0f};
            DrawTexturePro(graphics.vulcan_night_spritesheet, source, dest,{0.0f, 0.0f}, 0.0f, WHITE);
            Rectangle sourceObjects{currentObjektFrame*100.0f, 0.0f, 100.0f, 50.0f};
            DrawTexturePro(graphics.vulcan_morning_object_spritesheet, sourceObjects, dest,{0.0f, 0.0f}, 0.0f, WHITE);
            //DrawTextureEx(graphics.vulcan_morning,{0.0f, 0.0f},0.0f,8.0f,WHITE);
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
            Rectangle source{currentThemeFrame * 100.0f ,0.0f, 100.0f, 50.0f};
            Rectangle dest{0.0f,0.0f, 800.0f, 400.0f};
            DrawTexturePro(graphics.vulcan_night_spritesheet, source, dest,{0.0f, 0.0f}, 0.0f, WHITE);
            Rectangle sourceObjects{currentObjektFrame*100.0f, 0.0f, 100.0f, 50.0f};
            DrawTexturePro(graphics.vulcan_daylight__object_spritesheet, sourceObjects, dest,{0.0f, 0.0f}, 0.0f, WHITE);
            //DrawTextureEx(graphics.vulcan_daylight,{0.0f, 0.0f},0.0f,8.0f,WHITE);
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
            Rectangle source{currentThemeFrame * 100.0f ,0.0f, 100.0f, 50.0f};
            Rectangle dest{0.0f,0.0f, 800.0f, 400.0f};
            DrawTexturePro(graphics.vulcan_night_spritesheet, source, dest,{0.0f, 0.0f}, 0.0f, WHITE);
            Rectangle sourceObjects{currentObjektFrame*100.0f, 0.0f, 100.0f, 50.0f};
            DrawTexturePro(graphics.vulcan_night_object_spritesheet, sourceObjects, dest,{0.0f, 0.0f}, 0.0f, WHITE);
            //DrawTextureEx(graphics.vulcan_night,{0.0f, 0.0f},0.0f,8.0f,WHITE);
        }
        
    }
}

void DrawClock(int currentHour, int currentMinute, State currentState)
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

    int startX = 640;
    int startY = 10;

    if(currentState == State::ThemeForrest || currentState == State::ThemeVulcan){
        DrawText(hourText, startX -10, startY, fontSize, BLACK);
        bool showColon = ((int)GetTime() % 2 == 0);
        if (showColon){
            DrawText(":", startX + hourWidth, startY, fontSize, BLACK);
        }
        DrawText(minuteText, startX + 10 + hourWidth + colonWidth, startY, fontSize, BLACK);
        DrawText(minuteText, startX + 10 + hourWidth + colonWidth, startY, fontSize, BLACK);
    }
    else if(currentState == State::ThemeBeach){
        DrawText(hourText, startX -10, startY, fontSize, WHITE);
        bool showColon = ((int)GetTime() % 2 == 0);
        if (showColon){
             DrawText(":", startX + hourWidth, startY, fontSize, WHITE);
        }
         DrawText(minuteText, startX + 10 + hourWidth + colonWidth, startY, fontSize, WHITE);
         DrawText(minuteText, startX + 10 + hourWidth + colonWidth, startY, fontSize, WHITE);
    }
    




}

void DrawHomeButton(Graphics graphics){
    DrawTextureEx(graphics.homeButton, {20.0f,10.0f},0.0f,5.0f,WHITE);
}

void UnloadGraphics(Graphics& graphics)
{
    UnloadTexture(graphics.startscreen);
    UnloadTexture(graphics.startscreen_spritesheet);
    UnloadTexture(graphics.startscreen_objects_spritesheet);
    UnloadTexture(graphics.themechoice);
    UnloadTexture(graphics.themechoice_spritesheet);
    UnloadTexture(graphics.morning);
    UnloadTexture(graphics.daylight);
    UnloadTexture(graphics.night);
    UnloadTexture(graphics.forrest_morning);
    UnloadTexture(graphics.forrest_daylight);
    UnloadTexture(graphics.forrest_night);
    UnloadTexture(graphics.vulcan_morning);
    UnloadTexture(graphics.vulcan_daylight);
    UnloadTexture(graphics.vulcan_night);
    UnloadTexture(graphics.homeButton);
    UnloadTexture(graphics.icon_beach);
    UnloadTexture(graphics.icon_forrest);
    UnloadTexture(graphics.icon_vulcan);

    UnloadTexture(graphics.vulcan_morning_object_spritesheet);
    UnloadTexture(graphics.vulcan_daylight__object_spritesheet);
    UnloadTexture(graphics.vulcan_night_spritesheet);
    UnloadTexture(graphics.vulcan_night_object_spritesheet);
}

void UpdateHomeButton(Graphics graphics,State& currentState,Audio& audio){
    Rectangle homeButton = {20.0, 10.0, static_cast<float>(graphics.homeButton.width)*5,static_cast<float>(graphics.homeButton.height)*5};
    
    Vector2 mousePosition = GetMousePosition();
    
    if(CheckCollisionPointRec(mousePosition,homeButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        PlaySound(audio.button);
        
        currentState = State::Startscreen;

        
    }
}

void UpdateStartscreen(State& currentState,Audio& audio){
    if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        PlaySound(audio.button);
        currentState = State::ThemeChoice;
    }
}

void UpdateThemeChoice(Graphics graphics, State& currentState,Audio& audio){
    Rectangle beachButton = {20.0, 100.0, static_cast<float>(graphics.icon_beach.width)*7,static_cast<float>(graphics.icon_beach.height)*7};
    Rectangle forrestButton = {281.0, 100.0, static_cast<float>(graphics.icon_forrest.width)*7,static_cast<float>(graphics.icon_forrest.height)*7};
    Rectangle vulcanButton = {542.0, 100.0, static_cast<float>(graphics.icon_vulcan.width)*7,static_cast<float>(graphics.icon_vulcan.height)*7};
    Vector2 mousePosition = GetMousePosition();

    if(CheckCollisionPointRec(mousePosition,beachButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        PlaySound(audio.button);
        currentState = State::ThemeBeach;
    }
    else if(CheckCollisionPointRec(mousePosition,forrestButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        PlaySound(audio.button);
        currentState = State::ThemeForrest;
    }
    else if(CheckCollisionPointRec(mousePosition,vulcanButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        PlaySound(audio.button);
        currentState = State::ThemeVulcan;
    }


}

void DrawThemeChoiceExtras(Graphics graphics){
    DrawTextureEx(graphics.icon_beach,{20.0f,100.0f},0.0,7.0,WHITE);
    DrawTextureEx(graphics.icon_forrest,{281.0f,100.0f},0.0f,7.0,WHITE);
    DrawTextureEx(graphics.icon_vulcan,{542.0f,100.0f},0.0,7.0,WHITE);
    DrawText("Choose your Theme",150, 25, 50, BLACK);
}

void DrawThemeChoiceAnimation(Graphics  graphics, int currentThemeChoiceFrame){
    Rectangle source{currentThemeChoiceFrame * 100.0f ,0.0f, 100.0f, 50.0f};
    Rectangle dest{0.0f,0.0f, 800.0f, 400.0f};
    DrawTexturePro(graphics.themechoice_spritesheet, source, dest,{0.0f, 0.0f}, 0.0f, WHITE);
    
}