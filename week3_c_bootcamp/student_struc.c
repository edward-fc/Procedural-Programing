#include <stdio.h>

typedef struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} STUDENT ;

int main () {
    STUDENT new_student;
    scanf("%s\n",new_student.name);
    scanf("%s\n",new_student.student_id);
    scanf("%u \n",&new_student.mark);
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}