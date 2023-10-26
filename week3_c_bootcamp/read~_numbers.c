#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* file = fopen("input.txt","r");
    int buffer_size = 100,count,num[200],counter=0;
    char line_buffer[buffer_size],line_buffer2[buffer_size],new_line[buffer_size];
    while(fgets(line_buffer,buffer_size,file)){
        if (atoi(line_buffer) > 1000){
            count++;
        }
        num[counter]=atoi(line_buffer);
        printf("%s\n",line_buffer);
    }
    for ( counter = 0; counter < 201; counter++)
    {
        while(fgets(line_buffer,buffer_size,file)){
            if (atoi(line_buffer)+num[counter] == 2020){printf("these number make 2020: %d,%s\n",num[counter],line_buffer);}
            printf("%d\n",num[0]);
            }
    }
    printf("%d\n",count);
    fclose(file);
    return 0;

}