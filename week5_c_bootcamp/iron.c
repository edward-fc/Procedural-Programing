#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    float row[5];
}IRON;

typedef struct
{
    char date[20];
    float bloodIron;
} reading;

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

int main(){
    IRON iron[5];
    reading dataArray[100];
    FILE* file = fopen("input.txt","r");
    int buffer_size = 100,count,num[200],counter=0;
    char line[buffer_size];
    while (fgets(line, buffer_size, file))
    {
        // split up the line and store it in the right place
        // using the & operator to pass in a pointer to the bloodIron so it stores it
        tokeniseRecord(line, ",", dataArray[counter].date, &dataArray[counter].bloodIron);
        counter++;
    }
    int row[5];
    row[0] = 0,row[0] = 0,row[0] = 0,row[0] = 0,row[0] = 0;
    for(int i = 0; i < counter; i++){
        if (dataArray[i].bloodIron > 11 && dataArray[i].bloodIron < 11.9)
        {
            iron[0][row[0]]=dataArray[i].bloodIron;
        }
        if (dataArray[counter].bloodIron > 12 && dataArray[counter].bloodIron < 12.9)
        {
            iron[1][row[1]]=dataArray[i].bloodIron;
        }
        if (dataArray[counter].bloodIron > 13 && dataArray[counter].bloodIron < 13.9)
        {
            iron[2][row[2]]=dataArray[i].bloodIron;
        }
        if (dataArray[counter].bloodIron > 14 && dataArray[counter].bloodIron < 14.9)
        {
            iron[3][row[3]]=dataArray[i].bloodIron;
        }
        if (dataArray[counter].bloodIron > 15 && dataArray[counter].bloodIron < 15.9)
        {
            iron[4][row[4]]=dataArray[i].bloodIron;
        }
    }
    return counter;
    fclose(file);
    return 0;

}