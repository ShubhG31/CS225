/* Your code here! */
#pragma once
#include <vector>
#include "./cs225/PNG.h"
#include "dsets.h"
#include <map>
using namespace std;
using namespace cs225;
class SquareMaze{
    public:
        SquareMaze();
        bool canTravel(int x,int y,int dir )const;
        void makeMaze(int width, int height);
        void setWall(int x, int y, int dir, bool exists);
        vector<int>solveMaze();
        PNG *drawMaze() const;
        PNG *drawMazeWithSolution();

        private:
            // first value is walls, 2nd value is the floor 
            vector<pair<bool,bool> > boundaries;
            int width_, height_; 
            vector<int> solution;
            vector<int> visited;
            // map<int,int> distance;
            DisjointSets sets;
            int longest;

};
