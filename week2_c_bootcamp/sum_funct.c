#include <stdio.h>
float sum (float a, float b);

float sum (float a, float b){
    float c;
    c=a+b;
    return c;
}
int main(){
    float a =2.2,b=3.5;
    printf("%f",sum(a,b));
    return 0;
}
