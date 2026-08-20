#include "raylib.h"
#include "graphics.h"
#include "daytime.h"
#include "audio.h"
#include "ctime"

int main(void)
{   
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "NoD");
    InitAudioDevice();

    Image icon = LoadImage("assets/nod_icon_exe.png");
    SetWindowIcon(icon);

    SetTargetFPS(60);  
    int currentThemeChoiceFrame = 0;  
    float themeChoiceTimer = 0.0f;
    Daytime currentDayTime =  Daytime::Night;
    Graphics graphics = LoadGraphics();
    State currentState = State::Startscreen;

    Audio audio = LoadAudio();

    while (!WindowShouldClose())    {  
/*         if((currentState == State::ThemeBeach) || (currentState == State::ThemeForrest)){
            
        } */
        int currentHour = GetCurrentHour();
        int currentMinute = GetCurrentMinute();
        currentDayTime = CheckDayTime(currentHour); 
        

        if(currentState == State::Startscreen){
            UpdateStartscreen(currentState);
        }
        else if(currentState == State::ThemeChoice){
            themeChoiceTimer += GetFrameTime();

            if(themeChoiceTimer >= 0.85){
                currentThemeChoiceFrame++;
                if(currentThemeChoiceFrame >= 8){
                    currentThemeChoiceFrame = 0;
                }
                themeChoiceTimer = 0.0f;
            }
            UpdateThemeChoice(graphics, currentState);
        }
        else if(currentState == State::ThemeBeach || currentState == State::ThemeForrest || currentState == State::ThemeVulcan){
            UpdateHomeButton(graphics,currentState);
        }
        //currentDayTime = Daytime::Morning; //for testings
        //currentState = State::ThemeChoice; // for testings
        BeginDrawing();

        ClearBackground(GREEN);
        PlayAudio(audio,currentDayTime);
        DrawGraphics(graphics, currentDayTime,currentState);
        if(currentState == State::ThemeBeach || currentState == State::ThemeForrest || currentState == State::ThemeVulcan){
            DrawClock(currentHour, currentMinute);
        }
        //DrawClock(currentHour, currentMinute);
        //DrawHomeButton(graphics);

        if(currentState == State::ThemeChoice){
            DrawThemeChoiceAnimation(graphics,currentThemeChoiceFrame);
            DrawThemeChoiceExtras(graphics);
        }
        if(currentState == State::ThemeBeach || currentState == State::ThemeForrest || currentState == State::ThemeVulcan){
            DrawHomeButton(graphics);
        }   

        EndDrawing();
        
    }
    UnloadImage(icon);
    UnlaodAudio(audio);
    UnloadGraphics(graphics);

    CloseAudioDevice();
    CloseWindow();  
          

    return 0;
}