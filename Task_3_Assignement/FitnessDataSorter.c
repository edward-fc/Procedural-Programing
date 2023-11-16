#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer_size = 100,counter = 0;

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

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

FILE *open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, mode);
    return input;
}

int read_file(FILE *inputFile, FitnessData *dataArray)
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

int main() {
    FitnessData DATA[100];
    char filename[100];
    scanf(" %s",filename);
    char new_filename[100];
    strcpy(new_filename,filename);
    strcat(new_filename,".tsv");
    
    FILE *input = open_file(filename,"r");

    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }
    read_file(input,DATA);
    fclose(input);

    FILE *fptr;


    printf("%s\n",filename);


    fptr = fopen(new_filename ,"w");
    
    for (int i = 0; i<counter;i++){
        // printf("%d\t%s\t%s",DATA[i].steps,DATA[i].time,DATA[i].date);
        fprintf(fptr,"%d\t%s\t%s\n",DATA[i].steps,DATA[i].time,DATA[i].date);
    }

    // Close the file
    fclose(fptr);    
}
