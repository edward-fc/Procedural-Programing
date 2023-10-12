#include <stdio.h>

int main(){
    int my_array[5],i,sum=0;
    for ( i = 0; i < 5; i++)
    {
        my_array[i]=i;
    }
    
    for (i = 0; i < 5; i++)
    {
        sum += my_array[i];
    }
    printf("%d\n",sum);
}