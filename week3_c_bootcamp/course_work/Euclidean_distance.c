#include <stdio.h>

typedef struct 
{
   float x;
   float y;
} POINT ;

void Euclidean_distance(float x1, float y1,float x2,float y2,float output){
    output = pow(pow(x1-x2,2)+pow(y1-y2,2),0.5);
}

int main(){
    int number_points = 5;
    POINT point[number_points];
    for (int i = 0; i < number_points; i++)
    {
        point[i].x=i*2;
        point[i].y=i*3;
    }

}