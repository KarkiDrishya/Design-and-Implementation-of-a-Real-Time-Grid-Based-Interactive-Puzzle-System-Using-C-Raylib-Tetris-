//This file contains the tetrominoes rotation states

#include"block.h"
#include"position.h"

class LBlock: public Block
{
public:
    LBlock() //Green Block (L-shaped Block)
    {
        id = 1 ;
        cells[0] = {Position(0,2), Position(1,0),Position(1,1),Position(1,2)};
        cells[1] = {Position(0,1), Position(1,1),Position(2,1),Position(2,2)};
        cells[2] = {Position(1,0), Position(1,1),Position(1,2),Position(2,0)};
        cells[3] = {Position(0,0), Position(0,1),Position(1,1),Position(2,1)};
    }
};

class JBlock: public Block
{
    public:
        JBlock()//Red Block(J shaped Block)
        {
            id = 2 ;
            cells[0] = {Position(0,0),Position(1,0),Position(1,1),Position(1,2)};
            cells[1] = {Position(0,1),Position(0,2),Position(1,1),Position(2,1)};
            cells[2] = {Position(1,0),Position(1,1),Position(1,2),Position(2,2)};
            cells[3] = {Position(0,1),Position(1,1),Position(2,0),Position(2,1)};
        }
};

class IBlock: public Block
{
    public:
        IBlock()//Orange block (I shaped Block)
        {
            id = 3;
            cells[0] = {Position(1,0),Position(1,1),Position(1,2),Position(1,3)};
            cells[1] = {Position(0,2),Position(1,2),Position(2,2),Position(3,2)};
            cells[2] = {Position(2,0),Position(2,1),Position(2,2),Position(2,3)};
            cells[3] = {Position(0,1),Position(1,1),Position(2,1),Position(3,1)};
        }
};

class OBlock: public Block
{
    public:
        OBlock()//Yellow block (O shaped Block)
        {
            id = 4;
            cells[0] = {Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
            cells[1] = {Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
            cells[2] = {Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
            cells[3] = {Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
        }
};

class SBlock : public Block
{
    public:
        SBlock() //Pink block (S shaped block)
        {
            id = 5;
            cells[0] = {Position(0,1),Position(0,2),Position(1,0),Position(1,1)};
            cells[1] = {Position(0,1),Position(1,1),Position(1,2),Position(2,2)};
            cells[2] = {Position(1,1),Position(1,2),Position(2,0),Position(2,1)};
            cells[3] = {Position(0,0),Position(1,0),Position(1,1),Position(2,1)};
        }
};

class TBlock : public Block
{
    public:
        TBlock()//cyan block(T shaped block)
        {
            id = 6;
            cells[0] = {Position(0,1),Position(1,0),Position(1,1),Position(1,2)};
            cells[1] = {Position(0,1),Position(1,1),Position(1,2),Position(2,1)};
            cells[2] = {Position(1,0),Position(1,1),Position(1,2),Position(2,1)};
            cells[3] = {Position(0,1),Position(1,0),Position(1,1),Position(2,1)};
        }
};

class Zblock : public Block
{
    public:
        Zblock()//blue block(Z shaped block)
        {
            id = 7;
                cells[0] = {Position(0,0),Position(0,1),Position(1,1),Position(1,2)};
                cells[1] = {Position(0,2),Position(1,1),Position(1,2),Position(2,1)};
                cells[2] = {Position(1,0),Position(1,1),Position(2,1),Position(2,2)};
                cells[3] = {Position(0,1),Position(1,0),Position(1,1),Position(2,0)};
        }
};