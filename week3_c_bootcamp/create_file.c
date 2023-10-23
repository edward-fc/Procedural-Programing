#include <stdio.h>




int main(){
    char  filename[] = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror("");
        return 1;
    }
    // int number,number_lines = 10;
    // printf("enter %d number\n",number_lines);
    // for ( int i = 0; i < number_lines; i++)
    // {
    //     scanf("%d\n",&number);
    //     fprintf(file, "%d\n", number);
    // }
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }
    fclose(file);
    return 0;
}