#include <stdio.h>

int main(){
    char string[100];
    int length =0;
    scanf(" %s",&string);
    while(string[length]){
        length++;
    }
    printf("%d\n",length);
    char new_array[length+1];
    int i=0;
    while(i<length){
        printf("%s\n",string[i]);
        new_array[i]=string[i];
        printf("%s\n",new_array[i]);
        i++;
    }
    printf("%s\n",new_array);
}