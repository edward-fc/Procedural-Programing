#include "../MazeDataStruct.h"
/*
This is the test script to test the function read_file
If the segmentation core dump
The bash will detect and it will fail
If the code returns correct row length
The test was sucessful
*/
int main(){
    MAZE maze;
    char filename[30];//"../test_data/maze.csv"
    scanf("%s",filename);
    FILE *f = open_file(filename,"r");
    int count = read_file(f,maze.map);
    printf("%d",count);
    return count;
}