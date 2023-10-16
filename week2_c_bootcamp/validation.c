#include <stdio.h>
int main(){
    int loop =0,number;
    char term;
    while(loop == 0){
        scanf("%d%c",&number,&term);
        if (number > -2 && number <= 100){
            if (number == -1){
            printf("you have terminated the loop\n");
            loop++;
            }else{
                printf("you have chosen %d\n",number);
            }
        }else{
            printf("you have failed to enter a valid number\n");
        }
    }
    return 0;
}