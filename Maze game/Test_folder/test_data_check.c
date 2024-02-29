#include "../MazeDataStruct.h"
/*
This is the test script to test the function data_checker
If the segmentation core dump
The bash will detect and it will fail
If the code returns the correct col_index
The test was sucessful
*/
int main(){
    MAZE maze;
    char filename[30];
    scanf(" %s",filename);
    FILE *f = open_file(filename,"r");
    int count = read_file(f,maze.map);
    int col_index = data_checker(maze,count);
    return col_index;
}