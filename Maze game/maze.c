#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Maze Game: A basic game where players navigate a maze loaded from a file.
 * Maze characters: '#' for walls, ' ' for paths, 'S' for start, 'E' for exit.
 * Maze dimensions range from 5x5 to 100x100, and the shape is rectangular.
 * Players move using WASD (not keypress-triggered) and cannot pass through walls or the map edge.
 * Pressing 'M'/'m' shows the map with the player's location marked by 'X'. Reaching 'E' ends the game.
 */
int main(){
    MAZE Maze;
    // need a system to change the map
    char filename[30];
    printf("Insert maze filename:");
    scanf("%s",filename);
    //checking if filename is not empty
    if (filename == NULL)
    {
        printf("cant find file");
        return 1;
    }
    printf("%s",filename);
    FILE *f = open_file(filename, "r");
    // read the opened file which returns the len of the output
    int index_row = read_file(f,Maze.map);
    fclose(f);
    Maze.MAX_row = index_row;
    // // find the length of the colum
    int index_col = data_checker(Maze,Maze.MAX_row);
    Maze.MAX_col = index_col;
    //set start/end point
    //create a struct to store the coordanates then assigne them to the maze
    printf("%d %d",Maze.MAX_col,Maze.MAX_row);
    Player_position start_coor = find_start_postion(Maze);
    printf("%d %d",start_coor.x,start_coor.y);
    // Checking if start postition was found
    if (start_coor.x == 0 || start_coor.y == 0){
        return 1;
    }
    Maze.start_pos_x = start_coor.x;
    Maze.start_pos_y = start_coor.y;
    printf("\n\n");
    Player_position end_coor = find_end_postion(Maze);
    // Checking if end postition was found
    if (start_coor.x == 0 || start_coor.y == 0){
        return 1;
    }
    Maze.end_pos_x = end_coor.x;
    Maze.end_pos_y = end_coor.y;

    // set player position
    Player_position  Player = set_player_position(Maze);
    printf("%d %d\n",Player.x,Player.y);
    //loop to find player start and end position 
    int Game_State = 1;

    while (Game_State)
    {
        printf("Move (WASD) or Access the Map (M) or Exit (E): ");
        char move;
        scanf(" %c", &move);
        
        // switch function to show map or end game
        switch (move)
        {
            case 'E':
            case 'e':
                Game_State=0;
                return 1;
                break;
            case 'M':
            case 'm':
                print_MAZE(Maze,Player);
                break;
        }
        //Update Player movement        
        Player_position updated_player_movement = movePlayer(Maze,Player,move);
        Player.x = updated_player_movement.x;
        Player.y = updated_player_movement.y;
        // Check if the Wincondition has been met
        if (checkWinCondition(Maze,Player)){
            printf("Congratulations, you've found the end!");
            Game_State = 0;
        }
    }

    return 0;
}