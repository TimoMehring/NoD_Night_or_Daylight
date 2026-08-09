#include "raylib.h"
#include "graphics.h"
#include "daytime.h"
#include "ctime"

int main(void)
{   
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "NoD");

    SetTargetFPS(60);      
    Daytime currentDayTime =  Daytime::Morning;
    Graphics graphics = LoadGraphics();

    while (!WindowShouldClose())    {  
        int currentHour = GetCurrentHour();
        int currentMinute = GetCurrentMinute();
        currentDayTime = CheckDayTime(currentHour); 

        BeginDrawing();

        ClearBackground(GREEN);
        DrawGraphics(graphics, currentDayTime, currentHour, currentMinute);

        //DrawText(TextFormat("Hour: %d", currentHour),100,100,30,WHITE);

        EndDrawing();
        
    }
    UnloadGraphics(graphics);
    CloseWindow();  
          

    return 0;
}