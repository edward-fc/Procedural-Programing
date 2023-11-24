
// #ifndef FITNESS_DATA_STRUCT_H
// #define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer_size = 100,counter = 0;

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
void tokeniseRecord(char *record, char *delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
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
int read_file(FILE *inputFile, FITNESS_DATA *dataArray)
{
    counter = 0;
    char line[buffer_size];
    while (fgets(line, buffer_size, inputFile))
    {
        // split up the line and store it in the right place
        // using the & operator to pass in a pointer to the bloodIron so it stores it
        tokeniseRecord(line,",", dataArray[counter].date,dataArray[counter].time, &dataArray[counter].steps);
        counter++;
    }
    return counter;
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
        if (DATA[i].steps == 0){
            return 1;
        }
    }
    return 0;
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
    int maximun = DATA[0].steps;
	int rank = 0;
    for(int i = 1; i < count;i++){
        if (maximun < DATA[i].steps){
            maximun = DATA[i].steps;
			rank=i;
        }
    }
    return rank;
}
