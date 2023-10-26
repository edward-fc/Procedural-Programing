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
    FITNESS_DATA DATA;
    FITNESS_DATA MEMORIE[3];
    FILE *file = fopen("FitnessData_2023.csv","r");
    int buffer_size = 100,count=0;
    char line_buffer[buffer_size],delimiter = ',';
    while(fgets(line_buffer, buffer_size, file) != NULL){
        tokeniseRecord(line_buffer,&delimiter,DATA.date,DATA.time,DATA.steps);
        if ( count < 3) {
            strcpy(MEMORIE[count].date, DATA.date);
            strcpy(MEMORIE[count].time, DATA.time);
            strcpy(MEMORIE[count].steps, DATA.steps);
            }
        count++;
    }
    printf("Number of records in file: %d\n",count);
    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%s",MEMORIE[i].date,MEMORIE[i].time,MEMORIE[i].steps);
    }
    
    fclose(file);
    return 0;
}