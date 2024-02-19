#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    MAZE Maze;
    // Filename
    char filename[20] = "maze.csv";
    FILE *f = open_file(filename, "r");
    // read the opened file which returns the len of the output
    Maze.MAX_row = read_file(f,Maze.map);
    fclose(f);
    // // find the length of the colum
    Maze.MAX_col = strlen(Maze.map[0]);
    //set start/end point
    //create a struct to store the coordanates then assigne them to the maze
    Player_position start_coor = find_start_postion(Maze);
    Maze.start_pos_x = start_coor.x;
    Maze.start_pos_y = start_coor.y;

    Player_position end_coor = find_end_postion(Maze);
    Maze.end_pos_x = end_coor.x;
    Maze.end_pos_y = end_coor.y;

    // set player position
    Player_position  Player = set_player_position(Maze);
    printf("%d %d\n",Player.x,Player.y);
    //loop to find player start and end position 
    int Game_State = 1;
    while (Game_State)
    {
        print_MAZE(Maze,Player);

        printf("Move (WASD): ");
        char move;
        scanf(" %c", &move);
        Player_position updated_player_movement = movePlayer(Maze,Player,move);
        printf("%d %d\n",updated_player_movement.x,updated_player_movement.y);
        Player.x = updated_player_movement.x;
        Player.y = updated_player_movement.y;

        printf("%d %d\n",Player.x,Player.y);
        if (checkWinCondition(Maze,Player)){
            printf("Congratulations, you've found the end!\n");
            Game_State = 0;
        }        
    }
    return 0;
}