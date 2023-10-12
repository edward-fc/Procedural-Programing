#include <stdio.h>
int main(){
    int i,my_array[10];
    int max=10;
    for ( i = 0; i < 10; i++)
    {
        my_array[i]=i*2;
    }
    for ( i = 0; i < sizeof(my_array)/sizeof(my_array[0]); i++)
    {
        if (my_array[i] > max)
        {
            max = my_array[i];
        }
        
    }
    printf("%d\n",max);
}