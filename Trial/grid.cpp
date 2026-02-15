#include"grid.h"//Using " " and not <> because <> checks the header files in standard library but not the folder that the .h file is currently in but " " checks the file inside Trial foler itself
#include<iostream>
#include "colors.h"
using namespace std;
Grid::Grid()
{
    numrows = 20;
    numcols = 10;
    cellsize = 30;
    Initialize();
    colors = GetCellColors();
}
 void Grid::Initialize()
 {
    for(int row = 0; row<numrows; row++)
    {
        for(int column = 0; column<numcols;column++)
        {
            grid[row][column] = 0;
        }
    }
 }
 void Grid::Print(){
    for(int row = 0;row<numrows;row++)
    {
        for(int column = 0;column<numcols;column++)
        {
            cout<<grid[row][column]<<" ";
        }
    cout<<endl;
    }
 }
 void Grid ::Draw()
 {
    for(int row = 0; row < numrows; row++)
    {
        for(int column = 0; column < numcols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellsize+1,row*cellsize+1,cellsize-1,cellsize-1,colors[cellValue]);
        }
    }
 }