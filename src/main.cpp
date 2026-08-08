#include "raylib.h"
#include "graphics.h"
#include "logic.h"
#include "daytime.h"
#include "ctime"

int main(void)
{   
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "NoD");

    SetTargetFPS(60);      
    Daytime currentDayTime =  Daytime::Morning;
    Texture2D dayTime = LoadGraphics(currentDayTime);

    while (!WindowShouldClose())    
    {
        int currentHour = GetCurrentHour();

        BeginDrawing();

        ClearBackground(GREEN);
        DrawGraphics(dayTime);

        DrawText(TextFormat("Hour: %d", currentHour),100,100,30,WHITE);

        EndDrawing();
        
    }
    UnloadGraphics(dayTime);
    CloseWindow();  
          

    return 0;
}