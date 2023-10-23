#include <stdio.h>
#include <stdlib.h>

char average_numberfile(char filename[],char mode[]){
    FILE *file = fopen(filename, mode);
    int buffer_size = 100,count=0;
    float sum=0;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        sum += atof(line_buffer);
        count++;
    }
    sum = sum/count;
    printf("the average of the squres: %f\n",sum);
    fclose(file);
    return sum;
}

int main(){
    char filename[]= "squares.dat";
    float sum = average_numberfile(filename,"r");
    FILE *file = fopen(filename, "a+");

    float line = getc(file);

    while (line != EOF) {
        // Read the next character from the file
        line = getc(file);
    }
 
    // Check if the end-of-file indicator is
    // set for the file
    if (feof(file)){
        fprintf(file,"%f\n",sum);
    }else{
        printf("\n Something went wrong.");
    }

}