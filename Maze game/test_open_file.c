#include "MazeDataStruct.h"
/*
This is the test script to test the function open_file
If the segmentation core dump
The bash will detect and it will fail
If the code returns 0
The test was sucessful
*/
int main(){
    // Let test the open_file function
    char filename[10];
    scanf(" %s", filename);
    open_file(filename,"r");
    printf("sucess");
    return 0;
}