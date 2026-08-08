#include "raylib.h"
#include "graphics.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "NoD");

    SetTargetFPS(60);      
    
    //Texture2D texture = LoadGraphics();

    while (!WindowShouldClose())    
    {

        BeginDrawing();

            ClearBackground(GREEN);

            DrawText("Test", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        
    }

    CloseWindow();        

    return 0;
}