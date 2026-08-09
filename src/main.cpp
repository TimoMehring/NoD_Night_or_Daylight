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

    SetTargetFPS(60);      
    Daytime currentDayTime =  Daytime::Morning;
    Graphics graphics = LoadGraphics();

    Audio audio = LoadAudio();
    //PlayMusicStream(audio.birds); //Simple Audio Test

    while (!WindowShouldClose())    {  
        //UpdateMusicStream(audio.birds); // Implemented in PlayAudio()
        int currentHour = GetCurrentHour();
        int currentMinute = GetCurrentMinute();
        currentDayTime = CheckDayTime(currentHour); 
        //currentDayTime = Daytime::Night; //for testings

        BeginDrawing();

        ClearBackground(GREEN);
        PlayAudio(audio,currentDayTime);
        DrawGraphics(graphics, currentDayTime);
        DrawClock(currentHour, currentMinute);

        EndDrawing();
        
    }
    UnloadGraphics(graphics);
    CloseWindow();  
          

    return 0;
}