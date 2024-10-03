#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Maze Game: A basic game where players navigate a maze loaded from a file.
 * Maze characters: '#' for walls, ' ' for paths, 'S' for start, 'E' for exit.
 * Maze dimensions range from 5x5 to 100x100, and the shape is rectangular.
 * Players move using WASD (not keypress-triggered) and cannot pass through walls or the map edge.
 * Pressing 'M'/'m' shows the map with the player's location marked by 'X'. Reaching 'E' ends the game.
 */
int main(int argc, char *argv[]){
    MAZE Maze;
    // need check if there are not mutliple arguments
    if (argc != 2){
        return 1;
    }
    
    char *filename = argv[1];
    //checking if filename is not empty
    // stack overflow to see catch error that the file doesnt exist
    // https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
    if (filename == NULL || access(filename,F_OK))
    {
        printf("No file found or filename does not exist\n");
        return 2;
    }
    FILE *f = open_file(filename, "r");
    // read the opened file which returns the len of the output
    Maze.MAX_row  = read_file(f,Maze.map);
    // If true means that the file has row bigger than 100 characteres
    fclose(f);
    if (Maze.MAX_row == -1){
        printf("over 100 characteres");
        return 3;
    }
    
    // // find the length of the colum
    Maze.MAX_col  = data_checker(Maze,Maze.MAX_row);
    // if Max_col then maze is invalid
    if (Maze.MAX_col == 1){
        return 3;
    }
    //set start/end point
    //create a struct to store the coordanates then assigne them to the maze
    Player_position start_coor = find_start_postion(Maze);
    printf("%d %d",start_coor.x,start_coor.y);
    // Checking if start postition was found
    if (start_coor.x == 0 || start_coor.y == 0){
        printf("There are ever too many Start points or none at all\n");
        return 3;
    }
    Maze.start_pos_x = start_coor.x;
    Maze.start_pos_y = start_coor.y;

    Player_position end_coor = find_end_postion(Maze);
    // Checking if end postition was found
    if (end_coor.x == 0 || end_coor.y == 0){
        printf("There are ever too many End points or none at all\n");
        return 3;
    }
    Maze.end_pos_x = end_coor.x;
    Maze.end_pos_y = end_coor.y;

    // set player position
    Player_position  Player = set_player_position(Maze);
    printf("%d %d\n",Player.x,Player.y);

    //loop with function like printMaze and Moveplayer and way to see map 
    // exit program and exit point when reached the end 
    int Game_State = 1;

    while (Game_State)
    {
        //get user input
        printf("Move (WASD) or Access the Map (M) or Exit (E): ");
        char move;
        scanf(" %c", &move);
        
        // switch function to show map or end game
        switch (move)
        {
            // case 'E':
            // case 'e':
            //     Game_State=0;
            //     break;
            case 'M':
            case 'm':
                print_maze(Maze,Player);
                break;
            case 'W':
            case 'w':
            case 'A':
            case 'a':
            case 'S':
            case 's':
            case 'D':
            case 'd':
                //Update Player movement with user input    
                Player_position updated_player_movement = movePlayer(Maze,Player,move);
                Player.x = updated_player_movement.x;
                Player.y = updated_player_movement.y;
                break;
            default:
            return 1;
        }

        // Check if the Wincondition has been met
        if (checkWinCondition(Maze,Player)){
            printf("Congratulations, you've found the end!");
            Game_State = 0;
        }
    }

    return 0;
}