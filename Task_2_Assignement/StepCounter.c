#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array





void fetch_store_data(FITNESS_DATA MEMORY[],char *filename,char *count){
    //Initialise the Fitness Data
    FITNESS_DATA DATA;
    //Open the file
    FILE *file = open_file(filename,"r");
    if (file)
    {       
    int function_count;
    //Take line by line until the end
    function_count = read_file(file,&DATA,MEMORY);
    char token[6];
    sprintf(token, "%d", function_count);
    strcpy(count,token);
    //Close the file
    fclose(file);
    }
}

int MENU(FITNESS_DATA DATA[]){
    int QUIT=1,rank=0,mean=0,longest=0,new_longest=0, new_run=1,rank_start=0,rank_end=0;
    char input, filename,token [50],count[6],minimun[6],maximun[6],fail=0;
    

    while(QUIT){
        printf ("Menu Options:\n");
        printf ("A: Specify the filename to be imported\n");
        printf ("B: Display the total number of records in the file\n");
        printf ("C: Find the date and time of the timeslot with the fewest steps\n");
        printf ("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf ("E: Find the mean step count of all the records in the file\n");
        printf ("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf ("Q: Quit\n");
        printf ("Enter choice:");
        scanf(" %c",&input);
        switch (input){
            case 'A':
            case 'a':
            
            printf("Input filename: ");
            scanf("%s",token);
            fetch_store_data(DATA,token,count);
            fail = data_checker(DATA,atoi(count));
            if (fail){
                printf("Could not find or open the file.\n");
                QUIT = 0;
                return 1;
            }
            else{
                printf("File successfully loaded.\n");
            }
            break;
            
            case 'B':
            case 'b':
            printf("Total records: %s\n",count);
            break;

            case 'C':
            case 'c':
            find_lowest(DATA,atoi(count));
            break;

            case 'D': 
            case 'd':
            find_highest(DATA,atoi(count));
            break;

            case 'E':
            case 'e':
            
            mean = find_mean(DATA,atoi(count));
            printf("Mean step count: %i\n",mean);
            break;

            case 'F':
            case 'f':
            for (int i = 0; i < atoi(count); i++){
                if (atoi(DATA[i].steps) > 500){
                    new_longest++; 
                    if (new_run){
                        new_run=0;
                        rank = i;
                    }
                }else{
                    if (new_longest>=longest){
                        longest = new_longest;
                        rank_start=rank;
                        rank_end = i-1;
                    }
                    new_run = 1;
                    new_longest=0;
                }
            }
            printf("Longest period start: %s %s\n",DATA[rank_start].date,DATA[rank_start].time);
            printf("Longest period end: %s %s\n",DATA[rank_end].date,DATA[rank_end].time);
            break;

            case 'q':
            case 'Q':
                QUIT=0;
                break;

            default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Complete the main function
int main() {
    char input, filename,output;
    FITNESS_DATA DATA[10000]; 
    //use while(scanf("%[AaBbCcDdEeFfQq]", &a) == 1) next time link https://stackoverflow.com/questions/19911923/using-the-scanf-function-in-while-loop
    
    if (MENU(DATA)){
        return 1;
    }
    // get_user_answer(&output);
    // printf("get user info%c\n",output);
    
    return 0;   
    }








