#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define MAX_SIZE 102

typedef struct {
    int MAX_row,MAX_col,start_pos_x,start_pos_y,end_pos_x,end_pos_y;
    char map[MAX_SIZE][MAX_SIZE];
} MAZE;

// Using a random_number function found on stackoverflow
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c

int random_number(int min_num, int max_num)
    {
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        srand(time(NULL));
        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
    }


// Function prototypes
MAZE initialize_maze(MAZE maze){
    /*
    Create a Maze full of wall
    */
    for (int row_index; row_index < maze.MAX_row; row_index++){
        for (int column_index = 0; column_index < maze.MAX_col ; column_index++)
        {
            strcpy(&maze.map[row_index][column_index],"#");
        }
    }
    printf("Maze initialized !\n");
    return maze;
}

MAZE generate_maze(MAZE maze, int movement_coefficient){
    // lets randomize the start position use the border it is easier
    // UP/DOWN then Left/Right
    // Then put the end position at the opposite side
    int dire_x[4] = {1,-1,0,0},dire_y[4] = {0,0,1,-1}, end_zone=0;
    if (random_number(0,1)){
        //UP
        printf("Up or down");
        if (random_number(0,1)){
            maze.start_pos_x = 0;
            maze.start_pos_y = random_number(1,maze.MAX_col-1);
            maze.end_pos_x = maze.MAX_row-1;
            // get the end y position after the algorithm
            printf("UP");
            dire_x[1] = 0;
        }
        
        //DOWn
        else{
            maze.start_pos_x = maze.MAX_row-1;
            maze.start_pos_y = random_number(1,maze.MAX_col-1);
            maze.end_pos_x = 0;
            printf("Down");
            dire_x[0] = 0;
        }
    }
    else{
        // Left
        printf("left or right");
        if (random_number(0,1)){
            maze.start_pos_x = random_number(1,maze.MAX_row-1);
            maze.start_pos_y = 0;
            maze.end_pos_y = maze.MAX_col-1;
            end_zone = 1;
            printf("Left");
            dire_y[3] = 0;
        }
        // Right
        else{
            maze.start_pos_x = random_number(1,maze.MAX_row-1);
            maze.start_pos_y = maze.MAX_col-1;
            maze.end_pos_y = 0;
            end_zone = 1;
            printf("Rigth");
            dire_y[2] = 0;
        }
    }
    // Now we have the start and the row and column that we want to finish 
    int End_point = 1, current_x = maze.start_pos_x, current_y=maze.start_pos_y, memory_rand, count;
    printf("Current Pos:%d,%d\n End pos: %d,%d",current_x,current_y,maze.end_pos_x,maze.end_pos_y);
    while(End_point){
        // usleep(random_number(10000,100000));
        // Lets try and go left
        int rand_index = random_number(0,3);

        if ((rand_index != memory_rand))
        {
            memory_rand = rand_index;
            count = random_number(1,movement_coefficient);

            for (int i = 0; i < count; i++)
            {    

                if (dire_x[rand_index] == -1)
                {
                    if (current_x+dire_x[rand_index] >= 0)
                    {
                        current_x += dire_x[rand_index];
                        maze.map[current_x][current_y]=' ';
                    }
                }
                if (dire_x[rand_index] == 1)
                {
                    if (current_x+dire_x[rand_index] < maze.MAX_row)
                    {
                        current_x += dire_x[rand_index];
                        maze.map[current_x][current_y]=' ';
                    }
                }
                if (dire_y[rand_index] == -1)
                {
                    if (current_y+dire_y[rand_index] >= 0)
                    {
                        current_y += dire_y[rand_index];
                        maze.map[current_x][current_y]=' ';
                    }
                }
                if (dire_y[rand_index] == 1)
                {
                    if (current_y+dire_y[rand_index] < maze.MAX_col)
                    {
                        current_y += dire_y[rand_index];
                        maze.map[current_x][current_y]=' ';
                    }
                }
                if (end_zone)
                {
                    if (maze.end_pos_y == current_y)
                    {
                        End_point = 0;
                        maze.end_pos_x = current_x;
                    }
                }
                else
                {
                    if (maze.end_pos_x == current_x)
                    {
                        End_point = 0;
                        maze.end_pos_y = current_y;
                    }
                }
        }
            printf("Current pos:%d,%d,rand:%d\n",current_x,current_y,rand_index);
        }
        else
        {
            count++;
        }
        
    }
    return maze;
}
void save_maze_to_file(const MAZE *maze, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < maze->MAX_row; i++) {
        for (int j = 0; j < maze->MAX_col; j++) {
            fputc(maze->map[i][j], file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    // Create and initialize maze structure
    MAZE maze;

    char *filename = argv[1];
    maze.MAX_col = atoi(argv[2]);
    maze.MAX_row = atoi(argv[3]);

    if (maze.MAX_row < 5 || maze.MAX_col < 5 || maze.MAX_row  > 100 || maze.MAX_col > 100) {
        printf("Error: Maze dimensions must be between 5 and 100.\n");
        return 1;
    }

    
    maze = initialize_maze(maze);
    maze = generate_maze(maze,ceil((maze.MAX_col+maze.MAX_row)/8)); //make a coeficient proportional of the size of the maze
    if (maze.MAX_col>10 && maze.MAX_row>10)
    {
        maze = generate_maze(maze,ceil((maze.MAX_col+maze.MAX_row)/8));
    }
    if (maze.MAX_col>60 && maze.MAX_row>60)
    {
        maze = generate_maze(maze,ceil((maze.MAX_col+maze.MAX_row)/8));
        maze = generate_maze(maze,ceil((maze.MAX_col+maze.MAX_row)/8));
    }

    printf("\n");

    for (int row_index = 0; row_index < maze.MAX_row; row_index++)
    {
        for (int col_index = 0; col_index < maze.MAX_col; col_index++)
        {
            if (row_index == maze.start_pos_x && col_index == maze.start_pos_y){
                printf("S");
                maze.map[maze.start_pos_x][maze.start_pos_y] = 'S';
            }
            else 
            {
                if (row_index == maze.end_pos_x && col_index == maze.end_pos_y){
                printf("E");
                maze.map[maze.end_pos_x][maze.end_pos_y] = 'E';
            }
            
            else
            {
                printf("%c",maze.map[row_index][col_index]);
            }
            }
            
        }
        printf("\n");
    }

    // Save the maze to a file
    save_maze_to_file(&maze, filename);

    printf("Maze successfully generated and saved to %s\n", filename);
    return 0;
}