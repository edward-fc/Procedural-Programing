#include <stdio.h>

int main(){
    char filename[]="squares.dat";
    FILE *file = fopen(filename,"w");
    int number;
    printf("enter a positif integers:");
    scanf("%d",&number);

    for (int i = 0; i < number+1; i++)
    {
        fprintf(file, "%d\n", i*i);
    }
    fclose(file);
    return 0;

    
}