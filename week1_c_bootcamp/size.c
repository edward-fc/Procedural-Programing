#include <stdio.h>
int main(){
    int a;
    float b;
    double c;
    char d;
    printf("This is the maximun size of int: %zu\n",sizeof(a));
    printf("This is the maximun size of float: %zu\n",sizeof(b));
    printf("This is the maximun size of doucle: %zu\n",sizeof(c));
    printf("This is the maximun size of str: %zu\n",sizeof(d));
    return 0;

}