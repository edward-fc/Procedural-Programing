#include <stdio.h>
typedef struct 
{
    int value1;
    int value2;
    int value3;
} MATRIX;
int main(){
    MATRIX matrixA[3]= {
    {1, 2},
    {-1, 3},
    {4, 1}};
    MATRIX matrixB[2]= {
    {1, 3, -1},
    {4, 2, 0}};
    MATRIX matrixC[3];

    for (int y = 0; y<3; y++){
        matrixC[y].value1 = matrixA[y].value1*matrixB[0].value1 + matrixA[y].value2*matrixB[1].value1;
        matrixC[y].value2 = matrixA[y].value1*matrixB[0].value2 + matrixA[y].value2*matrixB[1].value2;
        matrixC[y].value3 = matrixA[y].value1*matrixB[0].value3 + matrixA[y].value2*matrixB[1].value3;
        printf("%i %i %i\n",matrixC[y].value1,matrixC[y].value2,matrixC[y].value3);
    }
}