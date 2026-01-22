#include"grid.h"//Using " " and not <> because <> checks the header files in standard library but not the folder that the .h file is currently in but " " checks the file inside Trial foler itself
#include<iostream>
using namespace std;
Grid::Grid()
{
    numrows = 20;
    numcols = 10;
    cellsize = 30;
    Initialize();
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
 vector<Color>Grid::GetCellColors(){
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0 , 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

 }