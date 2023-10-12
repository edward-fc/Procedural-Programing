#include <stdio.h>
int main(){
    int myarray[6]= {6,5946,6,4,8,9456},i,a,duplicate;
    for ( i = 0; i < 6; i++)
    {
        printf("%d\\n",myarray[i]);
        for ( a = 0; a < 6; a++)
        {
            if (a=!i)
            {
                 if (myarray[i]=myarray[a]){
                    duplicate = myarray[i];
                 }
            }
        }
        
    }
    printf("%d\n",duplicate);  
    return 0;
}