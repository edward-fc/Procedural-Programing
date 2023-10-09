#include <stdio.h>
#include <string.h>
int main(){
    char name[20];
    printf("Please enter your name:");
    scanf("%s",name);
    printf("%s",name);
    int j = strlen(name)-1;
    int i=0;
    while (i<j){
        printf("%d,%d\n",i,j);
        char c = name[i];
        name[i]=name[j];
        name[j]=c;
        i++;
        j--;
    }

    printf("your reversed name is %s\n",name);
}