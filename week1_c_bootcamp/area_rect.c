#include <stdio.h>
int main(){
    float length1;
    float length2;
    float area;
    printf("Hello, Please Enter the length1 of your rectangle:");
    scanf("%f",&length1);
    printf("Hello, Please Enter the length2 of your rectangle:");
    scanf("%f",&length2);
    area = length1*length2;
    printf("Your rectangle of %f length1 and %f length2 makes an area of %f\n",length1,length2,area);
    return 0;
}