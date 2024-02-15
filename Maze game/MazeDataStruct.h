
// #ifndef FITNESS_DATA_STRUCT_H
// #define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
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
 * @param dataArray the array of readings
 * @return int Returns the number of readings from the file
 */
int read_file(FILE *inputFile, char output[100][100])
{
	//Initiation of variables
    int buffer_size = 100,len=0,function_count=0;
    
    char line_buffer[buffer_size],delimiter = ',';

    while(fgets(line_buffer, buffer_size, inputFile) != NULL){
        //strcpy(output,line_buffer);
        //grab the length of Data Steps   
        strcpy(output[function_count],line_buffer);
        function_count++;
    }
	return function_count;
}

/**
 * @brief Checks that there was data for each part of each reading in the file
 *
 * @param MAZE The array of data from the file
 * @param Count The number of readings in the array
 * @return int Return 0 if there are no errors, 1 if you find an error.
 */
int data_checker(MAZE *MAZE, int count)
{
	if (count == 0){
		return 1;
	}
    for(int i = 0; i< count; i++){
        if (MAZE->map[i] == NULL){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Load the maze into the terminal with the player as P
 *
 * @param MAZE The array of data from the file and containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 0 if there are no errors
 */
int print_MAZE(MAZE *MAZE, Player_position Player)
{
    for (int row_index = 0; row_index < MAZE->MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < MAZE->MAX_col; col_index++)
        {
            if (row_index == Player.x && col_index == Player.y){
                printf("%s","P");
            }
            else{
                printf("%c",MAZE->map[row_index][col_index]);
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
void set_player_position(MAZE *MAZE, Player_position Player)
{
    Player.x = MAZE->start_pos_x;
    Player.y = MAZE->start_pos_y;
}
/**
 * @brief Find the start position in the file
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @return int Return 0 if there are no errors
 */
int find_start_postion(MAZE *MAZE){
    int record_row_index,record_col_index;
    for (int row_index = 0; row_index < MAZE->MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < MAZE->MAX_col; col_index++)
        {
            if (MAZE->map[row_index][col_index] == "S") {
                record_row_index = row_index;
                record_col_index = col_index;
            }          
        }
        
    }
    return record_row_index,record_col_index;
}
/**
 * @brief Find the end position in the file
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @return int Return 0 if there are no errors
 */
int find_end_postion(MAZE *MAZE){
    int record_row_index,record_col_index;
    for (int row_index = 0; row_index < MAZE->MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < MAZE->MAX_col; col_index++)
        {
            if (MAZE->map[row_index][col_index] == "E") {
                record_row_index = row_index;
                record_col_index = col_index;
            }          
        }
        
    }
    return record_row_index,record_col_index;
}
/**
 * @brief Get input to move Player with WASD 
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 0 if there are no errors and return 1 if there is a error
 */
void movePlayer(MAZE *MAZE, Player_position Player,char input)
{
    int recorded_x = Player.x,recorded_y = Player.y;
    if (input == "W"){
        if (MAZE->map[Player.x+1][Player.y] == " "){
                Player.x += 1;
        }
    }
    if (input == "S"){
        if (MAZE->map[Player.x+1][Player.y] == " "){
                Player.x -= 1;
        }
    }
    if (input == "D"){
        if (MAZE->map[Player.x+1][Player.y] == " "){
                Player.y += 1;
        }
    }
    if (input == "A"){
        if (MAZE->map[Player.x+1][Player.y] == " "){
                Player.y -= 1;
        }
    }
    if (Player.x == recorded_x || Player.y == recorded_y){
        return 1;
    }
    return 0;
}
/**
 * @brief Check Win Condition then end the loop
 * @param MAZE The array of data from the file and 
 * containing the len of the file and start/end positions
 * @param Player_position The coordonates of Player at all times on the MAP
 * @return int Return 0 ends the loop and return 1 there is an error or no win condition
 */
void checkWinCondition(MAZE *MAZE, Player_position Player)
{
    if (Player.x == MAZE->end_pos_x && Player.y == MAZE->end_pos_y)
    {
        return 0;
    }
    return 1;
    
}
// #endif // FITNESS_DATA_STRUCT_H
