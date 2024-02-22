#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    MAZE Maze;
    // Filename
    char choose_map,*filename;;
    printf("Choose map (1,2,3,4,5)");
    scanf(" %c",&choose_map);
    switch (choose_map){
        case '1':
            filename = "maze.csv";
            break;
        case '2':
            filename = "maze1.csv";
            break;
        case '3':
            filename = "maze2.csv";
            break;
        case '4':
            filename = "maze3.csv";
            break;
        case '5':
            filename = "maze4.csv";
            break;
    }
    if (filename == NULL)
    {
        return 1;
    }
    FILE *f = open_file(filename, "r");
    // read the opened file which returns the len of the output
    Maze.MAX_row = read_file(f,Maze.map);
    fclose(f);
    // // find the length of the colum
    Maze.MAX_col = data_checker(Maze,Maze.MAX_row);
    printf("%d\n",Maze.MAX_col);
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
    int Game_State = 1, nb_move = 0;

    while (Game_State)
    {
        printf("Move (WASD) or Access the Map (M) or Exit (E): ");
        char move;
        scanf(" %c", &move);
        
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
        
        Player_position updated_player_movement = movePlayer(Maze,Player,move);
        Player.x = updated_player_movement.x;
        Player.y = updated_player_movement.y;

        nb_move++;  
        if (checkWinCondition(Maze,Player)){
            printf("Congratulations, you've found the end! You did it in only %d\n",nb_move);
            Game_State = 0;
        }
        if (nb_move > 200){
            Game_State = 0;
        }
    }

    return 0;
}