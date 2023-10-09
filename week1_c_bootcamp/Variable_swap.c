#include <stdio.h>
int main(){
    int a,b,c;
    scanf("%i",&a);
    scanf("%i",&b);
    c=a;
    a=b;
    b=c;
    printf("A = %i and B = %i\n",a,b);
    return 0;
}