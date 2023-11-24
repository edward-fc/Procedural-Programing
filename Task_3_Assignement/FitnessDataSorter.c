#include "FitnessDataStruct.h"

int main() {
    FITNESS_DATA DATA[100];
    char filename[100];
    printf("Enter Filename: ");
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
    
    int count;
    count = read_file(input,DATA);
    fclose(input);

    if (data_checker(DATA,count)){
        return 1;
    }

    

    FILE *fptr = fopen(new_filename ,"w");;


    int rank;
    for (int i = 0; i< count;i++){
        int rank = 0;
        rank = find_highest(DATA,count);
        fprintf(fptr,"%s\t%s\t%d\n",DATA[rank].date,DATA[rank].time,DATA[rank].steps);
        DATA[rank].steps = 0;
    }

    // Close the file
    fclose(fptr);
    printf("Data sorted and written to %s\n",new_filename); 
    return 0;
}
