#include"game.h"
#include<random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
}

Block Game::GetRandomBlock()
{
    //This section of code is so that every blocks appear at least once before reappearing
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand()%blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}
std::vector<Block>Game::GetAllBlocks()
{
    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),Zblock()};
}