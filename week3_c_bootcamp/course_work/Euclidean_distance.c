#include <stdio.h>
#include <math.h>

typedef struct 
{
   float x;
   float y;
} POINT ;
float square_root(float number){
    float low =0, high = number, mid = 0;
    while (high - low > 0.0001) {
        mid = low + (high - low) / 2;
        if (mid*mid > number) {
            high = mid;
        } else {
            low = mid;
        } 
        return mid;   
        }
}
float Euclidean_distance(float x1, float y1,float x2,float y2){
    float output;
    output = square_root((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return output;
}

int main(){
    int number_points = 5;
    POINT point[number_points];
    for (int i = 0; i < number_points; i++)
    {
        point[i].x=i*2+10;
        point[i].y=i*6+5;
    }
    float output;
    for (int i=1;i<number_points;i++){
        output=Euclidean_distance((float) point[i-1].x,(float) point[i-1].x,(float) point[i].x,(float) point[i].x); 
        printf("%f\n",output);
    }
    return 0;
}