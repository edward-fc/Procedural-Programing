#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    MAZE Maze;
    Player_position Player;
    // Filename
    char filename[20] = "maze.csv";
    FILE *f = open_file(filename, "r");
    printf("%d",f->_fileno);
    // read the opened file which returns the len of the output
    Maze.MAX_row = read_file(f,Maze.map);
    fclose(f);
    // // find the length of the colum
    // Maze.MAX_col = strlen(Maze.map[0]);
    // //set start/end point
    // Maze.start_pos_x,Maze.start_pos_y = find_start_postion(Maze);
    // Maze.end_pos_x, Maze.end_pos_y = find_end_postion(Maze);
    // //loop to find player start and end position 
    // int Game_State = 1;
    // while (Game_State)
    // {
    //     print_MAZE(Maze,Player);

    //     printf("Move (WASD): ");
    //     char move;
    //     scanf(" %c", &move);

    //     movePlayer(Maze,Player,move);
    //     if (checkWinCondition(Maze,Player)){
    //         printf("Congratulations, you've found the end!\n");
    //         Game_State = 0;
    //     }        
    // }
    return 0;
}