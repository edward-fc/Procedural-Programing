#include <stdio.h>
int main(){
    int grade =70;
    if (grade >= 0 && grade <= 100){
        if (grade < 50){
            printf("you have failed\n");
        }else if(grade >= 70){
            printf("you have passed with distinction\n");
        }else{
            printf("you have passed\n");
        }
    }
    
}