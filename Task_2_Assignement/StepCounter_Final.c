#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }


void A(FITNESS_DATA MEMORY[],char *filename,char *count){
    //Initialise the Fitness Data
    FITNESS_DATA DATA;
    //Open the file
    FILE *file = fopen(filename,"r");
    //Initiation of variables
    int buffer_size = 100,len=0,function_count=0;
    
    char line_buffer[buffer_size],delimiter = ',';
    //Take line by line until the end
    while(fgets(line_buffer, buffer_size, file) != NULL){
        //Use the function provided
        tokeniseRecord(line_buffer,&delimiter,DATA.date,DATA.time,DATA.steps);
        //grab the length of Data Steps
        len = strlen(DATA.steps)-1;
        //See if the end of the string still has a format
        if (DATA.steps && DATA.steps[len] == '\n') {
            DATA.steps[len] = '\0';
            }
        printf("%d\n",function_count);
        //Copy the 3 first lines to print them later
        
        strcpy(MEMORY[function_count].date, DATA.date);
        strcpy(MEMORY[function_count].time, DATA.time);
        strcpy(MEMORY[function_count].steps, DATA.steps);
            
        function_count++;
    }
    char token[6];
    sprintf(token, "%d", function_count);
    strcpy(count,token);
    //Close the file
    fclose(file);
}

// Complete the main function
int main() {
    char input, filename,count[6],token [50];
    int QUIT = 1;
    FITNESS_DATA DATA[10000]; 
    while (QUIT){
        printf ("\n");
        printf ("Select A to Specify the filename to be imported\n");
        printf ("Select B to  Display the total number of records in the file\n");
        printf ("Select C to  Find the date and time of the timeslot with the fewest steps\n");
        printf ("Select D to Find the data and time of the timeslot with the largest number of steps\n");
        printf ("Select E to Find the mean step count of all the records in the file\n");
        printf ("Select F to Find the longest continuous period where the step count is above 500 steps\n");
        printf ("Select Q to quit\n");
        scanf("%c",&input);

        switch (input)
        {
            case 'A':; 
            case 'a':;  
            scanf("%s\n",token);
            // sprintf(filename, "%s", token);
            A(DATA,token,count);
                        break;
            

            case 'B':;
            case 'b':;
            printf("total count %s\n",count);
                        break;
            case 'C': 
            case 'c': 
                        break;
            case 'D': 
            case 'd': 
                        break;
            case 'E': 
            case 'e': 
                        break;
            case 'F': 
            case 'f': 
                        break;
            case 'q':
            case 'Q':;
            QUIT=0;
            break;

            default:  break;
        }
    }
        return 0;
        }









