#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declaring this value so I can use it in different places
#define buffer_size 100
int counter = 0;

/**
 * @brief Struct to hold each daily reading, contains the date as a string
 *        and the bloodIron as a floating point number.
 *
 */
typedef struct
{
    char date[20];
    float bloodIron;
} reading;

/**
 * @brief Adapted version of the tokeniseRecord function which you should now be familiar with - this one is adapted for this data file
 *        as it has fewer outputs and gives you the bloodIron as a float
 *
 * @param input the line of the file to be split
 * @param delimiter what character it should split on
 * @param date the place where the date will be stored
 * @param bloodIron the place where the bloodIron will be stored.
 */
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, float *bloodIron)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        // turns the blood iron into a float - similar to atoi().
        // we have to tell C that bloodIron is a pointer so it stores it.
        *bloodIron = atof(token);
    }

    // Free the duplicated string
    free(inputCopy);
}

// SUGGESTED FUNCTIONS

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
int read_file(FILE *inputFile, reading *dataArray)
{
    counter = 0;
    char line[buffer_size];
    while (fgets(line, buffer_size, inputFile))
    {
        // split up the line and store it in the right place
        // using the & operator to pass in a pointer to the bloodIron so it stores it
        tokeniseRecord(line, ",", dataArray[counter].date, &dataArray[counter].bloodIron);
        counter++;
    }
    return counter;
}

/**
 * @brief Checks that there was data for each part of each reading in the file
 *
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return int Return 0 if there are no errors, 1 if you find an error.
 */
int data_checker(reading *dataArray, int numReadings)
{
    for(int i = 0; i< numReadings; i++){
        if (dataArray[i].date == NULL){
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
float find_mean(reading* dataArray, int numReadings)
{
    float mean = 0;
    for (int i=0; i<counter;i++){
        mean += dataArray[i].bloodIron;
    }
    mean /= counter;
    printf("Your average blood iron was %.2f\n", mean);
}

/**
 * @brief Finds and returns the highest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The highest blood iron reading
 */
float find_highest(reading* dataArray, int numReadings)
{
    float maximun = dataArray[0].bloodIron;
    for(int i = 1; i < numReadings;i++){
        if (dataArray[i].bloodIron > maximun){
            maximun = dataArray[i].bloodIron;
        }
    }
    printf("Your highest blood iron was %.2f\n", maximun);
    return maximun;
}

/**
 * @brief Finds and returns the lowest blood iron reading
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 * @return float The lowest blood iron reading
 */
float find_lowest(reading* dataArray, int numReadings)
{
    float minimun = dataArray[0].bloodIron;
    for(int i = 1; i < numReadings;i++){
        if (dataArray[i].bloodIron < minimun){
            minimun = dataArray[i].bloodIron;
        }
    }
    printf("Your lowest blood iron was %.2f\n", minimun);
    return minimun;
}


/**
 * @brief Ask the user for the month to find, and then print out all readings containing that month.
 * 
 * @param dataArray The array of data from the file
 * @param numReadings The number of readings in the array
 */
void monthly_iron(reading* dataArray,reading* monthlyreturn, int numReadings,char* month)
{
    for(int i =0; i<numReadings;i++){
        if(strstr(dataArray[i].date, month)){
            printf("%s,%.2f\n",dataArray[i].date,dataArray[i].bloodIron);
            dataArray[i].bloodIron = monthlyreturn[i].bloodIron;
            strcpy(dataArray[i].date, monthlyreturn[i].date);
        }
    }
}