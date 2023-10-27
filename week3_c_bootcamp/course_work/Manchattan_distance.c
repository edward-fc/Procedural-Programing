#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
   float x;
   float y;
} POINT ;
int main(){
    int input_number=5,i=0;
    POINT point[input_number];
    float M=0;
    for (i = 0; i < input_number; i++)
    {
        point[i].x=i*6;
        point[i].y=i*2;
    }
    
    for (i=1;i<input_number;i++){
        M+= abs(point[i-1].x- point[i].x) +  abs(point[i-1].y- point[i].y);
    }
    printf("%f\n",(1/(float) i)*M);
}
