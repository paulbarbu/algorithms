//g++ -Wall --std=c++11
#include <queue>
#include <iostream>
#include <array>
#include <utility>

#define MAZE_SIZE 100

typedef std::array<std::array<int, MAZE_SIZE>, MAZE_SIZE> maze;
typedef std::pair<int, int> point;

int dLine[]   = {-1, 1, 0,  0};
int dColumn[] = { 0, 0, 1, -1};

maze leeSolveMaze(const maze &initial, int size, const point &entry, const point &exit){
    maze r;

    //initialize the result matrix so every step can be optimized at first
    int maxSteps = size*size + 1;
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            r[i][j] = maxSteps;
        }
    }

    std::queue<point> q;
    point current;

    q.push(entry);
    r[entry.first][entry.second]=1;
    while(!q.empty()){
        int nextLine, nextCol;
        current = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            nextLine = current.first + dLine[i];
            nextCol = current.second + dColumn[i];
            if(r[nextLine][nextCol] > r[current.first][current.second] &&
                    initial[nextLine][nextCol] != 1){
                r[nextLine][nextCol] = r[current.first][current.second] + 1;
                q.push(std::make_pair(nextLine, nextCol));
            }

            if(nextLine == exit.first && nextCol == exit.second){
                return r;
            }
        }
    }

    return r;
}

void displayPath(const maze &solvedMaze, const point &entry, const point &exit){
    int currentLine = exit.first;
    int currentCol = exit.second;
    int nextLine, nextCol;

    if(currentLine != entry.first || currentCol != entry.second){
        for(int i=0; i<4; i++){
            nextLine = currentLine + dLine[i];
            nextCol = currentCol + dColumn[i];

            if(solvedMaze[nextLine][nextCol] == solvedMaze[currentLine][currentCol]-1){
                displayPath(solvedMaze, entry, std::make_pair(nextLine, nextCol));
                std::cout<<currentLine<<" "<<currentCol<<"\n";
                return; //don't continue to go on all possible paths, one is enough
            }
        }
    }
    else{
        std::cout<<entry.first<<" "<<entry.second<<"\n";
    }
}

int main(){
    int size = 5; //the maze is 5x5
    //the array is bordered with obstacles so we don't get out of it
    std::array<std::array<int, 100>, 100> solvedMaze, initial =
    {{
     {{1,1,1,1,1,1,1}},
     {{1,0,1,0,0,0,1}},
     {{1,0,1,1,1,0,1}},
     {{1,0,0,0,1,0,1}},
     {{1,0,1,0,1,0,1}},
     {{1,0,0,0,0,0,1}},
     {{1,1,1,1,1,1,1}}
    }};

    point entry = std::make_pair(1, 1);
    point exit = std::make_pair(1, 3);

    solvedMaze = leeSolveMaze(initial, size, entry, exit);

    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            std::cout.width(2);
            std::cout<<solvedMaze[i][j]<< " ";
        }
        std::cout<<"\n";
    }

    displayPath(solvedMaze, entry, exit);
}

