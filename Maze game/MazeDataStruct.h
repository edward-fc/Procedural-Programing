
// #ifndef MAZE_DATA_STRUCT_H
// #define MAZE_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 102
//define player
typedef struct{
    int x, y;
}Player_position;
//define maze structure
typedef struct {
    int MAX_row,MAX_col,start_pos_x,start_pos_y,end_pos_x,end_pos_y;
    char map[MAX_SIZE][MAX_SIZE];
} MAZE;

/**
 * @brief Opens the file in the correct mode
 *
 * @param filename the name of the file to open
 * @param mode the mode (r/w/a/r+/w+/a+)
 * @return FILE* The file object to store the opened file in.
 */
FILE *open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, mode);
    return input;
}

/**
 * @brief Reads the data from the input file into an array of structs
 *
 * @param inputFile the open file object
 * @param output the array of readings
 * @return int Returns the number of readings from the file
 */
int read_file(FILE *inputFile, char output[MAX_SIZE][MAX_SIZE])
{
	//Initiation of variables
    int buffer_size = MAX_SIZE,function_count=0;
    
    char line_buffer[buffer_size];

    while(fgets(line_buffer, buffer_size, inputFile) != NULL){
        //grab the length of Data Steps   
        
        if (strlen(line_buffer)>100 || function_count > 100){
            return -1;
        }
        strcpy(output[function_count],line_buffer);
        function_count++;
    }
	return function_count;
}

/**
 * @brief Checks that there was data for each part of each reading in the file
 *
 * @param MAZE The array of data from the file
 * @param count The number of readings in the array
 * @return int Return 0 if there are no errors, 1 if you find an error.
 */
int data_checker(MAZE MAZE, int count)
{
    //check if array is not empty
	if (count <= 5 && count > 101){
		return 1;
	}
    //loop to check the length of each row and if there is string
    int col_index = strlen(MAZE.map[0]);
    for(int i = 0; i < count; i++){
        // to suppress the warning i use this 
        // https://stackoverflow.com/questions/3642010/can-i-compare-int-with-size-t-directly-in-c
        if (MAZE.map[i] == NULL || (strlen(MAZE.map[i]) != (size_t)col_index ) || strlen(MAZE.map[i]) <= 5 || strlen(MAZE.map[i]) > 101){
            return 1;
        }
    }
    
    for (int row_index = 0; row_index < count; row_index++)
    {
        for (int column_index = 0; column_index < col_index; column_index++)
        {
            if(MAZE.map[row_index][column_index] != ' ' && MAZE.map[row_index][column_index] != 'S' && MAZE.map[row_index][column_index] != 'E' && MAZE.map[row_index][column_index] != '#' && MAZE.map[row_index][column_index] != '\n'){
                return 1;
            }
        }
        
    }
    
    return col_index;
}

/**
 * @brief Load the maze into the terminal with the player as P
 *
 * @param MAZE The array of data from the file and containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 0 if there are no errors
 */
int print_maze(MAZE MAZE, Player_position Player)
{
    /* 
    first loop for row second loop for col then 
    check if row and col index are the coordanates of the player 
    if true print player 
    else print the map
    */
    printf("\n");
    for (int row_index = 0; row_index < MAZE.MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < MAZE.MAX_col; col_index++)
        {
            if (row_index == Player.x && col_index == Player.y){
                printf("%s","X");
            }
            else{
                printf("%c",MAZE.map[row_index][col_index]);
            }
            
        }
        
    }
    return 0;
        
}
/**
 * @brief Set the player position on the start
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 0 if there are no errors
 */
Player_position set_player_position(MAZE MAZE)
{
    Player_position player_position;
    player_position.x = MAZE.start_pos_x;
    player_position.y = MAZE.start_pos_y;
    return player_position;
}
/**
 * @brief Find the start position in the file if not returns 0,0
 * @param MAZE The array of data from the file
 * @return Return start_position coordanates if there are no errors
 */
Player_position find_start_postion(MAZE MAZE){
    Player_position start_coordanates;
    int count = 0;
    for (int row_index = 0; row_index < MAZE.MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < MAZE.MAX_col; col_index++)
        {
            if (MAZE.map[row_index][col_index] == 'S') {
                start_coordanates.x = row_index;
                start_coordanates.y = col_index;
                count += 1;
            }          
        }
        
    }
    if (count == 1){
        return start_coordanates;
    }
    // safety net to define the variable to check if the start point was found
    // or if it was found multiple times
    start_coordanates.x = 0;
    start_coordanates.y = 0;
    return start_coordanates;
    
}
/**
 * @brief Find the end position in the file and if not returns 0,0
 * @param MAZE The array of data from the file
 * @return Return end_position coordanates if there are no errors
 */
Player_position find_end_postion(MAZE MAZE){
    Player_position end_coordanates;
    int count = 0;
    
    for (int row_index = 0; row_index < MAZE.MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < MAZE.MAX_col; col_index++)
        {
            if (MAZE.map[row_index][col_index] == 'E') {
                end_coordanates.x = row_index;
                end_coordanates.y = col_index;
                count += 1;
            }          
        }
        
    }
    if (count == 1){
        return end_coordanates;
    }
    // safety net to define the variable to check if the start point was found
    end_coordanates.x = 0;
    end_coordanates.y = 0;
    // or if it was found multiple times
    return end_coordanates;
}
/**
 * @brief Get input to move Player with WASD 
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 0 if there are no errors and return 1 if there is a error
 */
Player_position movePlayer(MAZE MAZE, Player_position Player,char move)
{
    // not using pointer means functions returns updated player struct
    Player_position updated_pos;
    updated_pos.x = Player.x;
    updated_pos.y = Player.y;
    
    switch (move)
    {
    case 'W':
    case 'w':
        
        if (MAZE.map[Player.x-1][Player.y] == ' ' || MAZE.map[Player.x-1][Player.y] == 'S' || MAZE.map[Player.x-1][Player.y] == 'E'){
                updated_pos.x = Player.x-1;
        }
        break;
    case 'S':
    case 's':
        if (MAZE.map[Player.x+1][Player.y] == ' ' || MAZE.map[Player.x+1][Player.y] == 'S' || MAZE.map[Player.x+1][Player.y] == 'E'){
                updated_pos.x = Player.x+1;

        }
        break;
    case 'D':
    case 'd':
        if (MAZE.map[Player.x][Player.y+1] == ' ' || MAZE.map[Player.x][Player.y+1] == 'S' || MAZE.map[Player.x][Player.y+1] == 'E'){
                updated_pos.y = Player.y+1;

        }
        break;
    case 'A':
    case 'a':
        if (MAZE.map[Player.x][Player.y-1] == ' ' || MAZE.map[Player.x][Player.y-1] == 'S' || MAZE.map[Player.x][Player.y-1] == 'E'){
                updated_pos.y = Player.y-1;
        }
        break;
    // case 'E':
    // case 'e':
    case 'M':
    case 'm':
        break;
    default:
        printf("Invalid move\n");
        break;
    }
    // Checking if we haven't passed the border of the map
    if (updated_pos.x == -1){
        updated_pos.x += 1;
    }
    if (updated_pos.x == MAZE.MAX_row){
        updated_pos.x -= 1;
    }
    if (updated_pos.y == -1){
        updated_pos.y += 1;
    }
    if (updated_pos.y == MAZE.MAX_col){
        updated_pos.y -= 1;
    }
    return updated_pos;
}
/**
 * @brief Check Win Condition then end the loop
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 1 ends the loop and return 0 there is an error or no win condition
 */
int checkWinCondition(MAZE MAZE, Player_position Player)
{
    if (Player.x == MAZE.end_pos_x && Player.y == MAZE.end_pos_y)
    {
        return 1;
    }
    return 0;
    
}
// #endif // MAZE_DATA_STRUCT_H
