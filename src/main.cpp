#include "raylib.h"
#include "graphics.h"
#include "daytime.h"
#include "audio.h"
#include "ctime"
#include "theme.h"

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
    Theme currentTheme = Theme::Forrest;

    Audio audio = LoadAudio();

    while (!WindowShouldClose())    {  
        int currentHour = GetCurrentHour();
        int currentMinute = GetCurrentMinute();
        currentDayTime = CheckDayTime(currentHour); 
        //currentDayTime = Daytime::Morning; //for testings

        BeginDrawing();

        ClearBackground(GREEN);
        PlayAudio(audio,currentDayTime);
        DrawGraphics(graphics, currentDayTime,currentTheme);
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