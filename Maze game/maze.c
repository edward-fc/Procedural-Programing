#include "MazeDataStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    char *filename = "maze.csv",output[100][100];
    FILE *file = open_file(filename,"r");
    int count = read_file(file,output);
    for (int i = 0; i < count; i++)
    {
        printf("%s",output[i]);
    }
    
    
}