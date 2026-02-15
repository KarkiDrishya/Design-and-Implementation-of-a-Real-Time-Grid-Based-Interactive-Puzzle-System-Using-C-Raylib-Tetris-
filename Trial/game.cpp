#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    // This section of code is so that every blocks appear at least once before reappearing
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}
std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), Zblock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed(); // GetKeyPressed() is a raylib function that is used to detect the user input
    switch (keyPressed)
    {
    case KEY_LEFT: // KEY_LEFT is the left arrow key in the keyboard (<-)
        MoveBlockLeft();
        break;
    case KEY_RIGHT: // KEY_RIGHT is the right arrow key in the keyboard (->)
        MoveBlockRight();
        break;
    case KEY_DOWN: // KEY_Down is the down arrow key in the keyboard
        MoveBlockDown();
        break;
    case KEY_UP://KEY_UP is used to rotate the blocks
        RotateBlock();
        break;
    }
}
void Game ::MoveBlockLeft() // Moves Block left
{
    currentBlock.Move(0, -1);
        if(IsBlockOutside())//If IsBlockOutside returns true, the next line code undos the move
            {
                currentBlock.Move(0,1);
            }
}
void Game ::MoveBlockDown() // Moves Block down
{
    currentBlock.Move(1, 0);
        if(IsBlockOutside())
            {
                currentBlock.Move(-1,0);
            }
}
void Game ::MoveBlockRight() // Moves Block right
{
    currentBlock.Move(0, 1);
        if(IsBlockOutside())
            {
                currentBlock.Move(0,-1);
            }
}

bool Game::IsBlockOutside() //checks whether the block is outside or not
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
        for(Position item : tiles)
            {
                if(grid.IsCellOutside(item.row,item.column))
                {
                    return true;
                }
            }
        return false;
}

void Game :: RotateBlock()
{
    currentBlock.Rotate();
}