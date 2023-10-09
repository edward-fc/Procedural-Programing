#include <stdio.h>
#include <string.h>
int main(){
    char name="edward";
    int i;
    printf("Please enter your name:");
    //scanf("%s",&name);
    int letters = strlen(name);
    char reverse=name;
    for ( i = 0; i < letters; i++)
    {
        char c = name[i];
        reverse[letters-i] = c;
        printf("%s",reverse);
    }
    printf("your reversed name is %s\n",reverse);
}