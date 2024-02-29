#include "../MazeDataStruct.h"
/*
This is the test script to test the function checkWincondition
If the segmentation core dump
The bash will detect and it will fail
If the code returns 0
The test was sucessful
*/
int main(){
    MAZE maze;
    Player_position player;
    player.x = 0;
    player.y = 0;
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
    player.x = maze.end_pos_x;
    player.y = maze.end_pos_y;
    if (checkWinCondition(maze,player)){
        return 0;
    }
    return 1;
}