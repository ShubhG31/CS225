#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    cout << "Add your own tests here! Modify main.cpp" << endl;
    SquareMaze maze;
    maze.makeMaze(5,5);
    PNG* img = maze.drawMaze();
    img->writeToFile("my.png");
    std::vector<int> i = maze.solveMaze();
    for (auto j : i){
        std::cout << j << ' ';
    }
    std::cout<<std::endl;
    return 0;
}
