#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    char *filename = "maze.csv",output[100][100],maze[100][100];
    FILE *file = open_file(filename,"r");
    int count = read_file(file,output);
    for (int row = 0; row < count; row++)
    {
        for (int col = 0; col < strlen(output[row]); col+=2)
        {
            if (("%c",output[row][col]) == "S")
            {
                printf("P");
            }
            else{
                printf("%c",output[row][col]);
            }
            
            // strcpy(*maze,&output[row][col]);
            
        
        }
    }
    
}