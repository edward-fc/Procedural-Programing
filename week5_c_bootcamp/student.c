#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int Task[2][5];
    } Student;

int main(){
    Student students[4] = {
    {"Alex Turner"},
    {"Bob Williams"},
    {"Sophia Mendes"},
    {"Laura Cerroni"}};
    srand(time(NULL));
    for (int z = 0; z< 2; z++){
        for(int i = 0; i<4; i++){
            for (int j = 0; j<5; j++){
                students[i].Task[z][j] = 100 - (rand() % 30);
            }
        }
    }
    for (int z = 0; z<2; z++){
        printf("Semester %i:\n",z+1);
        for(int i = 0; i<4; i++){
            printf("\n%s: \n",students[i].name);
            for (int j = 0; j<5; j++){
                printf("%i ",students[i].Task[z][j]);
            }
        }
        printf("\n");
    }
}