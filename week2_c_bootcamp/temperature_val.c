#include <stdio.h>
int main(){
    int temperature = 41;
    if (temperature >= -10 && temperature <= 40){
        printf("the temperature is valid\n");
    }else{
        printf("the temperature isnt valid\n");
    }
    return 0;
}