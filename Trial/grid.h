#pragma once // preprocessor directive that tells the compiler to include the header file one time even if it is referred to it multiple times
#include <vector>
#include <raylib.h>
using namespace std;

class Grid
{
private:
    int numrows;
    int numcols;
    int cellsize;
    vector<Color> colors;

public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column); // this checks whether the cell is going outside the boundary or not
    int grid[20][10];
};