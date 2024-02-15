#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(char filename){
    MAZE Maze;
    Player_position Player;
    // Filename will be inserted by user
    FILE *f = open_file(filename, "r");
    // read the opened file which returns the len of the output
    Maze.MAX_row = read_file(f,Maze.map);
    fclose(f);
    // find the length of the colum
    Maze.MAX_col = strlen(Maze.map[0]);
    //set start/end point
    Maze.start_pos_x,Maze.start_pos_y = find_start_postion(Maze);
    Maze.end_pos_x, Maze.end_pos_y = find_end_postion(Maze);
    //loop to find player start and end position 



}