#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(char filename){
    MAZE MAZE;
    Player_position Player;
    // Filename will be inserted by user
    FILE *f = open_file(filename, "r");
    // read the opened file which returns the len of the output
    MAZE.MAX_row = read_file(f,MAZE.map);
    fclose(f);
    // find the length of the colum
    MAZE.MAX_col = strlen(MAZE.map[0]);
    //loop to find player start and end position 



}