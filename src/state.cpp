#include "state.h"
#include "raylib.h"

void UpdateScreen(State& currentState){

}

/* void UpdateHomeButton(Graphics graphics,State& currentState){
    Rectangle HomeButton = {0.0, 0.0, graphics.homeButton.width, graphics.homeButton.height};
    Vector2 mousePosition = GetMousePosition();
    if(CheckCollisionPointRec(mousePosition,HomeButton)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            DrawTextureEx(graphics.startscreen,{0.0f, 0.0f},0.0f,8.0f,WHITE);

        }
    }
} */