
// #ifndef FITNESS_DATA_STRUCT_H
// #define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char row[100];
} MAZE_ROW;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

void tokeniseRecord(const char *input, const char *delimiter,
                    char *row) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    delimiter=",";
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    int count = 0;
    while (token != NULL){
        
        if (token != NULL) {
            strcpy(row, token);
        token = strtok(NULL, delimiter);
        count += 1;
    }
    strcpy(row, token);
    }
    // Free the duplicated string
    free(inputCopy);
    }

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
 * @param DATA The array of data from the file
 * @param Count The number of readings in the array
 * @return int Return 0 if there are no errors, 1 if you find an error.
 */
int data_checker(MAZE_ROW *DATA, int count)
{
	if (count == 0){
		return 1;
	}
    for(int i = 0; i< count; i++){
        if (DATA[i].row == NULL){
            return 1;
        }
    }
    return 0;
}

// #endif // FITNESS_DATA_STRUCT_H
