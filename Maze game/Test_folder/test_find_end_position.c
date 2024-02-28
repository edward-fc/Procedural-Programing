#include "../MazeDataStruct.h"
/*
This is the test script to test the function find_end_position
If the segmentation core dump
The bash will detect and it will fail
If the code returns 0
The test was sucessful
*/
char main(){
    MAZE maze;
    Player_position player;
    player.x = 0;
    player.y =0;
    char filename[20];
    scanf(" %s",filename);
    FILE *f = open_file(filename,"r");
    int count = read_file(f,maze.map);
    int col_index = data_checker(maze,count);
    maze.MAX_row = count;
    maze.MAX_col = col_index;
    Player_position end_coor = find_end_postion(maze);
    maze.end_pos_x = end_coor.x;
    maze.end_pos_y = end_coor.y;
    printf("%d,%d",maze.end_pos_x,maze.end_pos_y);
    return 0;
}