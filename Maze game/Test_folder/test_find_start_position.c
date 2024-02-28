#include "../MazeDataStruct.h"
/*
This is the test script to test the function find_start_position
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
    int col_index = data_checker(maze,count);
    maze.MAX_row = count;
    maze.MAX_col = col_index;
    Player_position start_coor = find_start_postion(maze);
    maze.start_pos_x = start_coor.x;
    maze.start_pos_y = start_coor.y;
    printf("%d,%d",maze.start_pos_x,maze.start_pos_y);
    return 0;
}