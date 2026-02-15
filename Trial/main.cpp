#include "raylib.h"
#include "game.h"

int main(void){
    Color darkblue = {44,44,127,255};
    InitWindow(300,600,"raylib Tetris");
    SetTargetFPS(60);
   
    Game game = Game();
    
    while(WindowShouldClose()==false)
    {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkblue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}