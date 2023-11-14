#include "utilities.h"

int main()
{
    // array of daily readings
    reading daily_readings[100];
    reading monthly_readings[31];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice , *month;
    int counter = 0;
    float mean = 0 , minimun , maximun;

    while (1)
    {
        FILE *input = open_file(filename,"r");
        if (!input)
        {
            printf("Error: File could not be opened\n");
            return 1;
        }

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            counter = 0;
            counter=read_file(input,daily_readings);
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }

            break;

        case 'B':
        case 'b':
            find_mean(daily_readings,counter);
            break;

        case 'C':
        case 'c':
            find_lowest(daily_readings,counter);
            break;

        case 'D':
        case 'd':
            find_highest(daily_readings,counter);
            break;

        case 'E':
        case 'e':
            printf("Enter month:");
            scanf(" %s",month);
            monthly_iron(daily_readings,monthly_readings,counter,month);
            break;

        case 'F':
        case 'f':
            printf("the range is: %.2f\n",find_highest(daily_readings,counter)
                                        -find_lowest(daily_readings,counter));
            float standard_deviation, mean;
            mean = find_mean(daily_readings,counter);
            for (int i = 0; i < counter; i++){
                standard_deviation += (daily_readings[i].bloodIron - mean)
                                *(daily_readings[i].bloodIron - mean);                
            }
            standard_deviation /= counter;
            standard_deviation = (standard_deviation); 
            printf("the standard deviation is: %.2f\n",standard_deviation);
            printf("the median is:%.2f\n",(find_highest(daily_readings,counter)
                                        +find_lowest(daily_readings,counter))/2);
            monthly_iron(daily_readings,monthly_readings,counter,"SEP");
            for (int i = 0; i < 19; i++){
                printf("%s,%.2f\n",monthly_readings[i].date
                                ,monthly_readings[i].bloodIron);
            }
            monthly_iron(daily_readings,monthly_readings,counter,"OCT");
            for (int i = 0; i < 30; i++){
                printf("%s,%.2f\n",monthly_readings[i].date
                                ,monthly_readings[i].bloodIron);
            }
            monthly_iron(daily_readings,monthly_readings,counter,"NOV");
            for (int i = 0; i < 8; i++){
                printf("%s,%.2f\n",monthly_readings[i].date
                                ,monthly_readings[i].bloodIron);
            }
            
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}