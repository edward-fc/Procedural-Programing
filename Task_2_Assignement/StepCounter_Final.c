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
    delimiter=",";
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
char get_user_answer(){
    char token;
    scanf("%[AaBbCcDdEeFfQq]", &token);
    return token;
}
void MENU(FITNESS_DATA DATA[]){
    int QUIT=1,rank=0;
    char input, filename,token [50],count[6],minimun[6];
    

    while(QUIT){
        printf ("\n");
        printf ("Menu Options:\n");
        printf ("A: Specify the filename to be imported\n");
        printf ("B: Display the total number of records in the file\n");
        printf ("C: Find the date and time of the timeslot with the fewest steps\n");
        printf ("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf ("E: Find the mean step count of all the records in the file\n");
        printf ("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf ("Q: Quit\n");
        printf ("Enter choice: \n");
        scanf(" %c",&input);
        switch (input){
            case 'A':
            case 'a':
            printf("Enter the file name of the data:\n");
            scanf("%s\n",token);
            A(DATA,token,count);
            break;
            
            case 'B':
            printf("total count %s\n",count);
            break;

            case 'b':
            printf("total count %s\n",count);
            break;

            case 'C':
            strcpy(minimun, DATA[0].steps);
            for(int i=0; i<atoi(count);i++){
                if (atoi(minimun) < atoi(DATA[i].steps)){
                    strcpy(minimun, DATA[i].steps);
                    rank=i;
                }
            }
            printf("the date and time of the timeslot with the fewest steps: %s and %s\n",DATA[rank].time,DATA[rank].date);
            break;

            case 'c':
            strcpy(minimun, DATA[0].steps);
            for(int i=0; i<atoi(count);i++){
                if (atoi(minimun) < atoi(DATA[i].steps)){
                    strcpy(minimun, DATA[i].steps);
                    rank=i;
                }
            }
            printf("the date and time of the timeslot with the fewest steps: %s and %s\n",DATA[rank].time,DATA[rank].date);
            break;

            case 'D':break; 
            case 'd':break;

            case 'E':break;
            case 'e':break;

            case 'F':break;
            case 'f':break;

            case 'q':
            case 'Q':
            // if (input == "q" || input == "Q" ){
                QUIT=0;
            // }
            break;
        }
    }
}
// Complete the main function
int main() {
    char input, filename,output;
    FITNESS_DATA DATA[10000]; 
    //use while(scanf("%[AaBbCcDdEeFfQq]", &a) == 1) next time link https://stackoverflow.com/questions/19911923/using-the-scanf-function-in-while-loop
    
    MENU(DATA);
    // get_user_answer(&output);
    // printf("get user info%c\n",output);
    
    return 0;   
    }








