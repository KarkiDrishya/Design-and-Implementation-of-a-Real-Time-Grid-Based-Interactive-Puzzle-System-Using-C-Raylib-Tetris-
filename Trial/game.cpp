#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
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
    if(gameOver && keyPressed !=0)
    {
        gameOver = false;
        Reset();
    }
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
    if(!gameOver)
    {
    currentBlock.Move(0, -1);
        if(IsBlockOutside()||BlockFits() == false)//If IsBlockOutside returns true, the next line code undos the move
            {
                currentBlock.Move(0,1);
            }
    }
}
void Game ::MoveBlockDown() // Moves Block down
{   
    if(!gameOver)
    {
    currentBlock.Move(1, 0);
        if(IsBlockOutside()|| BlockFits() == false)
            {
                currentBlock.Move(-1,0);
                LockBlock();
            }
    }
}
void Game ::MoveBlockRight() // Moves Block right
{
    if(!gameOver)
    {
    currentBlock.Move(0, 1);
        if(IsBlockOutside()||BlockFits() == false)
            {
                currentBlock.Move(0,-1);
            }
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
    if(IsBlockOutside()||BlockFits()==false)
    {
        currentBlock.UndoRotation();
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false) //gameover
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

bool Game::BlockFits() //used to check if the cells are empty or not
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles)
    {
        if(grid.IsCellEmpty(item.row, item.column)==false)
        {
            return false; //basically returns false if cell is not empty, true if it is empty
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
