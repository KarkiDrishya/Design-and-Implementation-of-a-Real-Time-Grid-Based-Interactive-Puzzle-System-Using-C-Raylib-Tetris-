#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"

int main(void){
    Color darkblue = {44,44,127,255};
    InitWindow(300,600,"raylib Tetris");
    SetTargetFPS(60);
    Grid grid = Grid();
    
    grid.Print();

    LBlock block = LBlock();
    
    while(WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(darkblue);

        grid.Draw();

        block.Draw();

        EndDrawing();
    }
    CloseWindow();
}