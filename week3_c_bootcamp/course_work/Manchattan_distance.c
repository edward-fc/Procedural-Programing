#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
   int x;
   int y;
} POINT ;
int main(){
    int input_number=5;
    POINT point[input_number];
    int M,i=0;
    for (i = 0; i < input_number; i++)
    {
        point[i].x=i*6;
        point[i].y=i*2;
    }
    for (i=1;i<input_number;i++){
        M+= abs(point[i-1].x- point[i].x) +  abs(point[i-1].y- point[i].y);
    }
    printf("%d\n",(1/i)*M);
}
