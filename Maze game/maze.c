#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    MAZE Maze;
    // need a system to change the map
    char filename;;
    printf("Insert maze filename:");
    scanf(" %s",&filename);
    //checking if map was selected
    if (&filename == NULL)
    {
        printf("cant find file");
        return 1;
    }
    FILE *f = open_file(&filename, "r");
    // read the opened file which returns the len of the output
    Maze.MAX_row = read_file(f,Maze.map);
    fclose(f);
    // // find the length of the colum
    Maze.MAX_col = data_checker(Maze,Maze.MAX_row);
    //set start/end point
    //create a struct to store the coordanates then assigne them to the maze
    
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