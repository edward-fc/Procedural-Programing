#include <stdio.h>
int main(){
    int a =5;
    switch (a)
    {
    case 0:
        printf("you have chosen the ooption 0\n");
    break;
    case 1:
        printf("you have chosen the ooption 1\n");
    break;
    case 2:
        printf("you have chosen the ooption 2\n");
    break;
    case 3:
        printf("you have chosen the ooption 3\n");
    break;
    case 4:
        printf("you have chosen the ooption 4\n");
    break;
    default:printf("you have failed to chose an option between 0-4\n");
    break;
    }
    return 0;
}