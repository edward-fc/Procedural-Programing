#include <stdio.h>

int main(){
    int my_array[10],i,memory;
    for ( i = 0; i < 10; i++)
    {
        my_array[i]=i*2;
    }
    memory = my_array[9];
    for ( i = 9; i > 0; i--){
        printf("%d\n",my_array[i]);
        my_array[i] = my_array[i-1];
        }
    my_array[0]=memory;
    
    for ( i = 0; i < 10; i++){
        printf("%d ",my_array[i]);
        }
    }