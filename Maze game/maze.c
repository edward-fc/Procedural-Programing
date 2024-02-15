#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct{
    int x, y;
}Player_position;
typedef struct {
    int MAX_row,MAX_col,start_pos_x,start_pos_y,end_pos_x,end_pos_y;
    char map[MAX_SIZE][MAX_SIZE];
} MAZE;

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