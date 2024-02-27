#include "MazeDataStruct.h"
/*
This is the test script to test the function read_file
If the segmentation core dump
The bash will detect and it will fail
If the code returns 0
The test was sucessful
*/
int main(){
    MAZE maze;
    char filename[20];
    scanf(" %s",filename);
    FILE *f = open_file(filename,"r");
    int count = read_file(f,maze.map);
    return count;
}