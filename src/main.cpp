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
    int currentFrameStartscreen = 0;
    int currentFrameObjects = 0;
    int currentThemeFrame = 0;
    int currentObjektFrame = 0;
    float themeChoiceTimer = 0.0f;
    float objectsTimer = 0.0f;
    float allThemesTimer = 0.0f;
    Daytime currentDayTime =  Daytime::Night;
    Graphics graphics = LoadGraphics();
    State currentState = State::Startscreen;

    Audio audio = LoadAudio();

    while (!WindowShouldClose()){  
        int currentHour = GetCurrentHour();
        int currentMinute = GetCurrentMinute();
        currentDayTime = CheckDayTime(currentHour); 
        

        if(currentState == State::Startscreen){
            themeChoiceTimer += GetFrameTime();
            if(themeChoiceTimer >= 0.6){
                currentFrameStartscreen++;  
                if(currentFrameStartscreen >= 4){
                    currentFrameStartscreen = 0;
                }
                themeChoiceTimer = 0.0f;
            }

            objectsTimer += GetFrameTime();
            if(objectsTimer >= 0.7){
                currentFrameObjects++;
                if(currentFrameObjects >= 4){
                    currentFrameObjects = 0;
                }
                objectsTimer = 0.0f;
            }
            UpdateStartscreen(currentState,audio);
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
            UpdateThemeChoice(graphics, currentState,audio);
        }
        else if(currentState == State::ThemeVulcan){
            allThemesTimer += GetFrameTime();
            if(allThemesTimer >= 0.6){
                currentThemeFrame++;
                if(currentThemeFrame >= 4){
                    currentThemeFrame = 0;
                }
                allThemesTimer = 0.0f;
            }
            objectsTimer += GetFrameTime();
            if(objectsTimer >= 0.9){
                currentObjektFrame++;
                if(currentObjektFrame >= 4){
                    currentObjektFrame = 0;
                }
                objectsTimer = 0.0f;
            }
            UpdateHomeButton(graphics,currentState,audio);
        }
        else if(currentState == State::ThemeBeach || currentState == State::ThemeForrest || currentState == State::ThemeVulcan){
            UpdateHomeButton(graphics,currentState,audio);
        }
        //currentDayTime = Daytime::Daylight; //for testings
        //currentState = State::ThemeChoice; // for testings
        BeginDrawing();

        ClearBackground(GREEN);
        PlayAudio(audio,currentDayTime,currentState);
        DrawGraphics(graphics, currentDayTime,currentState,currentFrameStartscreen,currentFrameObjects, currentThemeFrame,currentObjektFrame);
        if(currentState == State::ThemeBeach || currentState == State::ThemeForrest || currentState == State::ThemeVulcan){
            DrawClock(currentHour, currentMinute, currentState);
        };

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