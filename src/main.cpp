#include "raylib.h"
#include "graphics.h"
#include "logic.h"

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

        BeginDrawing();

        ClearBackground(GREEN);
        DrawGraphics(dayTime);

        EndDrawing();
        
    }
    UnloadGraphics(dayTime);
    CloseWindow();  
          

    return 0;
}