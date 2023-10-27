#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct  {
	char date[11];
	char time[6];
	char steps[8];
} FITNESS_DATA ;


// Define any additional variables here



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



// Complete the main function
int main() {
    //Initialise the Fitness Data
    FITNESS_DATA DATA;
    FITNESS_DATA MEMORIE[3];
    //Open the file
    FILE *file = fopen("FitnessData_2023.csv","r");
    //Initiation of variables
    int buffer_size = 100,count=0,len=0;
    char line_buffer[buffer_size],delimiter = ',';
    //Take line by line until the end
    while(fgets(line_buffer, buffer_size, file) != NULL){
        //Use the function provided
        tokeniseRecord(line_buffer,&delimiter,DATA.date,DATA.time,DATA.steps);
        //grab the length of Data Steps
        len = strlen(DATA.steps)-1;
        //See if the end of the string still has a format
        if (*DATA.steps && DATA.steps[len] == '\n') {
            DATA.steps[len] = '\0';
            }
        
        //Copy the 3 first lines to print them later
        if ( count < 3) {
            strcpy(MEMORIE[count].date, DATA.date);
            strcpy(MEMORIE[count].time, DATA.time);
            strcpy(MEMORIE[count].steps, DATA.steps);
            }
        count++;
    }
    //Print the number of records in the file
    printf("Number of records in file: %d\n",count);
    //Print the Three first lines
    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n",MEMORIE[i].date,MEMORIE[i].time,atoi(MEMORIE[i].steps));
    }
    //Close the file
    fclose(file);
    return 0;
}