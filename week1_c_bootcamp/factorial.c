#include <stdio.h>
int main(){
    int a,i,factorial;
    factorial=1;
    printf("Enter a integres number");
    scanf("%d", &a);
    for ( i = 1; i < a+1; i++)
    {
        factorial=factorial*i;
    }
    printf("%i\n",factorial);
    return 0;
    
}