#include "raylib.h"
#include "grid.h"

int main(void){
    Color darkblue = {44,44,127,255};
    InitWindow(300,600,"raylib Tetris");
    SetTargetFPS(60);
    Grid grid = Grid();
    grid.Print();
    while(WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(darkblue);
        EndDrawing();
    }
    CloseWindow();
}