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
    Daytime currentDayTime =  Daytime::Morning;
    Graphics graphics = LoadGraphics();
    State currentState = State::Startscreen;

    Audio audio = LoadAudio();

    while (!WindowShouldClose())    {  
        int currentHour = GetCurrentHour();
        int currentMinute = GetCurrentMinute();
        currentDayTime = CheckDayTime(currentHour); 
        //currentDayTime = Daytime::Morning; //for testings
        //currentState = State::ThemeBeach; // for testings
        BeginDrawing();

        ClearBackground(GREEN);
        PlayAudio(audio,currentDayTime);
        DrawGraphics(graphics, currentDayTime,currentState);
        DrawClock(currentHour, currentMinute);

        EndDrawing();
        
    }
    UnloadImage(icon);
    UnlaodAudio(audio);
    UnloadGraphics(graphics);

    CloseAudioDevice();
    CloseWindow();  
          

    return 0;
}