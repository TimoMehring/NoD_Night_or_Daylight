#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "NoD");

    SetTargetFPS(60);              

    while (!WindowShouldClose())    
    {

        BeginDrawing();

            ClearBackground(GREEN);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        
    }

    CloseWindow();        

    return 0;
}