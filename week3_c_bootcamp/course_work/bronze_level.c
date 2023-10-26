#include <stdio.h>

typedef struct coordinates
{
    char x[10];
    char y[10];
} COORDINATES ;

int main(){
    COORDINATES new_coordinates;
    char list[10];
    int i;
    for ( i = 0; i < 10; i++){
        new_coordinates.x[i] = i;
        new_coordinates.y[i] = i+2;
        printf("(%d,%d)\n",new_coordinates.x[i],new_coordinates.y[i]);
    }
    
}