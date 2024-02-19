#include "MazeDataStruct.h"

int main(){
    MAZE maze;
    char filename[20];
    scanf(" %s",filename);
    FILE *f = open_file(filename,"r");
    int count = read_file(f,maze.map);
    int col_index = data_checker(maze,count);
    return col_index;
}