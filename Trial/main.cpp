#include "raylib.h"
#include "game.h"


double lastUpdateTime = 0;

bool EventTriggered(double interval) // this user defined function is used to bring down the blocks on its own
{
    double currentTime = GetTime(); //GetTime() function in raylib which gives how much time has passed since program started in sec
    if(currentTime - lastUpdateTime>=interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;

}

int main(void){
    Color darkblue = {44,44,127,255};
    InitWindow(300,600,"raylib Tetris");
    SetTargetFPS(60);
   
    Game game = Game();
    
    while(WindowShouldClose()==false)
    {
        game.HandleInput();
        if(EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkblue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}