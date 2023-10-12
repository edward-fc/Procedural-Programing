#include <stdio.h>
int main(){
    char str[6] = "Hello", reverse[6];
    int a,b=4;
    for (a = 0; a<5; a++,b--)
    {
        reverse[b]=str[a];
    }
    printf("this is the reverse of %s is %s\n",str,reverse);
}