/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include <vector>
#include <random>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;


SquareMaze::SquareMaze(){
    height_=0;
    width_=0;
}

bool SquareMaze::canTravel(int x,int y,int dir )const{
    if((dir == 0 && x >= width_ - 1) || (dir == 1 && y >= height_ - 1) || (dir == 2 && x <= 0) || (dir == 3 && y <= 0)){
        return false;
    }

    if(x>=width_ || y>=height_) return false;

    if(dir==0){ //&& x+1<width_-1 && !boundaries[(x+1)+y*(width_)].first){
        return !boundaries[(x)+y*(width_)].first;
    }
    if(dir==1){// && y+1<height_-1 && !boundaries[x+(y+1)*(width_)].second ){
        return !boundaries[(x)+y*(width_)].second;
    }
    if(dir ==2){ //&& x-1>0 && !boundaries[(x-1)+y*(width_)].first){
        // return true;
        if(x<1){
            return false;
        }

        else{
            return !boundaries[(x-1)+y*(width_)].first;
        }
    }
    if(dir==3) {//&& y-1>0 && !boundaries[x+(y-1)*(width_)].second){
        // return true;
        if(y<1){
            return false;
        }
        else{
            return !boundaries[(x)+(y-1)*(width_)].second;
        }
    }
    return false;

    // if(x>= width_ || y>= height_){
    //     return false;
    // }
    // //std::cout<<x<<" "<<" "<<y<<std::endl;

    // if(dir == 0){
    //     //Checking the condition if the current location is the right-wall.
    //     //std::cout<<x<<y<<" "<<!wall_[x][y].r<<"right"<<std::endl;
    //     return !boundaries[x+y*(width_].first;

    // }

    // if(dir == 1){
    //     //Checking the condition if the current location is the bottom wall.
    //     //std::cout<<x<<y<<" "<<!wall_[x][y].d<<"down"<<std::endl;
    //     return !wall_[x+y*(width_].first;
    // }

    // //This chunk of the code checks if it can travel left.
    // if(dir == 2){

    //     if(x < 1){
    //     //std::cout<<x<<y<<" "<<"left"<<"false"<<std::endl;
    //         return false;
    //     }
    //     else{
    //     //std::cout<<x<<y<<" "<<!wall_[x][y-1].r<<"left"<<std::endl;
    //         return !wall_[x+y*(width_].r;
    //     }
}
void SquareMaze::makeMaze(int width, int height){

    width_=width;
    height_=height;
    for(int i=0; i<(height_*width_); i++){
        boundaries.push_back(make_pair(true,true));
    }
    sets.addelements(height*width);
    random_device rando;
    mt19937 g(rando());
    uniform_int_distribution<int> index(0, (height_*width_)-1);
    uniform_int_distribution<int> wf(0,1);
    int size= (height_*width_);
    int counter=0;
    while(sets.size(0)<size){
        int cell= index(g);
        int wall=wf(g);
        int row= cell/width;
        int col= cell%width;
        if(row<(height-1)){
            if(sets.find(cell)!=sets.find(cell+width)){
                setWall(cell%width, cell/width, 1, false);
                sets.setunion(cell,cell+width);
            }
        }
        if(col<(width-1)){
            if(sets.find(cell)!=sets.find(cell+1)){
                setWall(cell%width, cell/width, 0, false);
                sets.setunion(cell,cell+1);
            }
        }
    }
}
void SquareMaze::setWall(int x, int y, int dir, bool exists){
    //dir==1 means floor 
    dir?boundaries[x+(y*width_)].second=exists:boundaries[x+(y*width_)].first=exists;
    return;

}


vector<int> SquareMaze::solveMaze(){
    for(int x=0; x<(width_*height_);x++){
        visited.push_back(0);
    }

    map<int,int> parent;
    //vector<int> direction;
    queue<int> BFS;
    //direction.push_back(-1);
    //parent.push_back(-1);
    // map<int,int> prev;
    BFS.push(0);
    visited[0] = 1;
    // prev[0]=-1;
    // distance[0]=0;
    int v;
    int y;
    int x; 
    while(!BFS.empty()){
        v=BFS.front();
        BFS.pop();
        y=v/width_;
        x=v%width_;
        if(canTravel(x, y, 0)){
            if(visited[(y)*width_ + x+1]==0){
                BFS.push((y)*width_ + x+1);
                visited[(y)*width_ + x+1]=1;
                // distance[(y)*width_ + x+1]=distance[(y)*width_ + x]+ 1;
                // prev[(y)*width_ + x+1] = v;
                parent[(y)*width_ + x+1]=v;
                //direction[(y*width_)+x+1]=0;


            }
        }
        if(canTravel(x, y, 1)){
            if(visited[(y+1)*width_ + x]==0){
                BFS.push((y+1)*width_ + x);
                visited[(y+1)*width_ + x]=1;
                // distance[(y+1)*width_ + x]=distance[(y)*width_ + x]+1;
                //  prev[(y+1)*width_ + x] = v;
                parent[(y+1)*width_ + x]=v;
                //direction[((y+1)*width_)+x]=1;
            }
        }
        if(canTravel(x, y,2)){
            if(visited[(y)*width_ + x - 1]==0){
                BFS.push((y)*width_ + x - 1);
                visited[(y)*width_ + x - 1]=1;
                // distance[(y-1)*width_ + x]=distance[(y-1)*width_ + x]+1;
                //  prev[(y-1)*width_ + x] = v;
                parent[(y)*width_ + x - 1]=v;
                //direction[((y)*width_)+x - 1]=2;
            }
        }

        if(canTravel(x, y, 3)){
            if(visited[(y-1)*width_ + x]==0){
                BFS.push((y-1)*width_ + x);
                visited[(y-1)*width_ + x]=1;
                // distance[(y)*width_ + x-1]=distance[(y)*width_ + x]+1;
                //  prev[(y)*width_ + x-1] = v;
                parent[(y-1)*width_ + x]=v;
                //direction[((y-1)*width_)+x]=3;
            }
        }

    }

    // for(i to width){
    //     int maxdistance
    //     int maxi
    //     distance[i]
    //     compare distance[i] to maxdistance (change maxdistance and maxi if larger)        
        
    // }
    int MAXi=0;
    int MAXl=0;

    for(int i=0;i<width_;i++){
        int start=0;
        int end= i+ (height_-1)*width_;
        int cur=0;

        while(end!=start){
            end=parent[end];
            cur++;
        }

        if(cur>MAXl){
            MAXl=cur;
            MAXi=i;
        }
    }

    int maximum= MAXi + (width_-1) *width_;
    longest=maximum;
    stack<int> s;
    //std::cout <<"ended" <<std::endl;
    while(maximum!=0){
        int prev = parent[maximum];
        int diff = maximum - parent[maximum];
        //std::cout <<"ended" <<std::endl;
        if(diff ==1){
            s.push(0);
        }
        else if(diff==width_){
            s.push(1);
        }
        else if(diff == -1){
            s.push(2);
        }

        else if(diff == -1*width_){
            s.push(3);
        }
        maximum=prev;
    }
    //std::cout <<"ended" <<std::endl;
    while(!s.empty()){
        solution.push_back(s.top());
        s.pop();
    }

    return solution;
    // std::cout <<"ended" <<std::endl;
    // int maximum = -1;
    // int size=height_* width_;
    // cout<<size<<endl;
    // int i = size - width_;
    // cout << i <<endl;
    // cout << (i<size) <<endl;
    // while(true){
    //     std::cout<< "here" << ' ';
    //     int j=i;
    //     int c=0;
    //     vector<int> paths;
    //     while(parent.at(j)!=-1){
    //         paths.push_back(direction[j]);
    //         j=parent[j];
    //         c++;
    //     }
    //     if(c>maximum){
    //         solution=paths;
    //         maximum=c;
    //     }
    //     i++;
    // }
    // std::reverse(solution.begin(),solution.end());
    // return solution;
    }
    // int highest_length = -1;
    // for(int i = size_ - width_; i <size_ ; i++){
    //     int j = i;
    //     int counter = 0;
    //     std::vector<int> temp_path;
    //     while(parents[j].parent != -1){
    //         //std::cout<<parents[j].direction;
    //         temp_path.push_back((parents[j].direction));
    //         //std::cout<<parents[j].direction;
    //         //Setting j to the index of the parent;
    //         j = parents[j].parent;
    //         counter++;
    //     }
    //     if(counter> highest_length){
    //         solution_ = temp_path;
    //         highest_length = counter;
    //     }
    // }







PNG *SquareMaze::drawMaze() const{
    PNG* image = new PNG(width_ *10 + 1, height_ * 10 +1);
    for(int y =0; y<height_*10 + 1; y++){
        image->getPixel(0, y).l = 0;
    }
    for(int x = 10; x<width_ * 10 + 1; x++){
        image->getPixel(x, 0).l = 0;
    }
    
    for(int x = 0; x < width_; x++){
        for(int y = 0; y < height_; y++){
            //blacking the right wall.
            if(boundaries[x+y*(width_)].first){
                for(int i = 0; i< 11; i++){
                    image->getPixel((x + 1)*10, y*10 + i).l = 0 ;
                }
            }
            if(boundaries[x+y*(width_)].second){
                for(int i = 0; i< 11; i++){
                    image->getPixel(x*10 + i, (y+1)*10).l = 0;
                }
            }
        }
    }

    return image;
}
PNG *SquareMaze::drawMazeWithSolution(){    
    PNG *solve = drawMaze();
    vector<int> solution = solveMaze();
    int x_counter=5;
    int y_counter=5;

//     for(int i=1;i<=9;i++){
//         HSLAPixel& pix = solve->getPixel((longest%width_) * 10 - i, ((longest/height_) + 1) * 10);
//         pix.l = 1;
//   }

    for(unsigned int i=0; i<solution.size();i++){
        if(solution[i]==0){
            for(int j=0; j<=10; j++){
                HSLAPixel & Solution_pixel = solve->getPixel(x_counter+j, y_counter);
                Solution_pixel.h=0;
                Solution_pixel.s=1;
                Solution_pixel.l=0.5;
                Solution_pixel.a=1;
            }
            x_counter+=10;
        }
        else if(solution[i]==1){
            for(int j=0; j<=10; j++){
                 HSLAPixel & Solution_pixel = solve->getPixel(x_counter, y_counter+j);
                Solution_pixel.h=0;
                Solution_pixel.s=1;
                Solution_pixel.l=0.5;
                Solution_pixel.a=1;
            }
            y_counter+=10;
        }
        else if(solution[i]==2){
            for(int j=0; j<=10; j++){
                 HSLAPixel & Solution_pixel = solve->getPixel(x_counter-j, y_counter);
                Solution_pixel.h=0;
                Solution_pixel.s=1;
                Solution_pixel.l=0.5;
                Solution_pixel.a=1;
            }
            x_counter-=10;
        }
        else if(solution[i]==3){
            for(int j=0; j<=10; j++){
                HSLAPixel & Solution_pixel = solve->getPixel(x_counter, y_counter-j);
                Solution_pixel.h=0;
                Solution_pixel.s=1;
                Solution_pixel.l=0.5;
                Solution_pixel.a=1;
            }
            y_counter-=10;
        }
    }
    for(int i=1;i<10;i++){
        HSLAPixel& pix = solve->getPixel(x_counter -5 +i, (y_counter + 5));
        pix.l = 1;
    }
    return solve;
}