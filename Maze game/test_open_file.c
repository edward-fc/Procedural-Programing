#include "MazeDataStruct.h"
/* If the segmentation core dump
* the bash will detect and it will fail
* If the code returns 0
* The test was sucessful
*/
int main(){
    // Let test the open_file function
    char filename[10];
    scanf(" %s", filename);
    open_file(filename,"r");
    printf("sucess");
    return 0;
}