
// #ifndef FITNESS_DATA_STRUCT_H
// #define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[8];
} FITNESS_DATA;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

void tokeniseRecord( const char *input, const char *delimiter,
                    char *row[1],char *reste[10]) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    delimiter=",";
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    strcpy(row[0], token);
    token = strtok(NULL, delimiter);
    printf("%s",token);
    strcpy(reste[0], token);
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
int read_file(FILE *inputFile, FITNESS_DATA *DATA,FITNESS_DATA *MEMORY)
{
	//Initiation of variables
    int buffer_size = 100,len=0,function_count=0;
    
    char line_buffer[buffer_size],delimiter = ',';

    while(fgets(line_buffer, buffer_size, inputFile) != NULL){
        //Use the function provided
        tokeniseRecord(line_buffer,&delimiter,DATA->date,DATA->time,DATA->steps);
        //grab the length of Data Steps
        len = strlen(DATA->steps)-1;
        //See if the end of the string still has a format
        if (DATA->steps && DATA->steps[len] == '\n') {
            DATA->steps[len] = '\0';
            }
        //Copy the 3 first lines to print them later
        
        strcpy(MEMORY[function_count].date, DATA->date);
        strcpy(MEMORY[function_count].time, DATA->time);
        strcpy(MEMORY[function_count].steps, DATA->steps);
            
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
int data_checker(FITNESS_DATA *DATA, int count)
{
	if (count == 0){
		return 1;
	}
    for(int i = 0; i< count; i++){
        if (DATA[i].steps == NULL){
            return 1;
        }
    }
    return 0;
}


/**
 * @brief Calculates and returns the mean of the readings in the array
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The mean of the readings.
 */
float find_mean(FITNESS_DATA* dataArray, int numReadings)
{
    float mean = 0;
    for (int i=0; i<numReadings;i++){
        mean += atoi(dataArray[i].steps);
    }
    mean /= numReadings;
    return mean;
}

/**
 * @brief Finds and returns the highest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The highest blood iron reading
 */
int find_highest(FITNESS_DATA* DATA, int count)
{
    int maximun = atoi(DATA[0].steps);
	int rank;
    for(int i = 1; i < count;i++){
        if (maximun < atoi(DATA[i].steps)){
            maximun = atoi(DATA[i].steps);
			rank=i;
        }
    }
    printf("Largest steps: %s %s\n",DATA[rank].date,DATA[rank].time);
    return maximun;
}

/**
 * @brief Finds and returns the lowest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The lowest blood iron reading
 */
int find_lowest(FITNESS_DATA* DATA, int count)
{
	int minimun = atoi(DATA[0].steps);
	int rank;
    for(int i = 1; i < count;i++){
        if (minimun > atoi(DATA[i].steps)){
            minimun = atoi(DATA[i].steps);
			rank=i;
        }
    }
    printf("Fewest steps: %s %s\n",DATA[rank].date,DATA[rank].time);
    return minimun;
}


// #endif // FITNESS_DATA_STRUCT_H
