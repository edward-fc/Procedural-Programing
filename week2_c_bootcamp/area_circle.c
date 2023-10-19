#include <stdio.h>
int len_str(char str[]){
    int a=0;
    while (str[a] != '\0'){
        printf("%c\n",str[a+1]);
        a++;
    }
    return a;
}
int concatstr(char str1[],char str2[]){
    int i;
    char str3 = str1;
    for ( i = 0; i < len_str(str2); i++)
    {
        str3 += str2[i];
    }
    return str3;
    }
int isPrime(int input){
    int i,result = 0;
    for ( i = 2; i < input; i++){
        if (input%i == 0){
            result = 1;
        }
    }
    return result;    
}
float area_circle(float radius){
    float area_circle;
    area_circle = radius*radius*3.14159;
    return area_circle;
}
float volume_sphere(float radius){
    float volume_sphere;
    volume_sphere = (4/3)*3.14159*radius*radius*radius;
    return volume_sphere;
}
int main(){
    printf("%d",concatstr("hi9","hello"));
}