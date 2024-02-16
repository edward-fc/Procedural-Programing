# Compile and RUN the MAZE script
gcc maze.c -o maze


// Test the Functions in the MAZEDataStruct.h
filename1=maze.csv
gcc test_open_file.c -o test_open_file
./test_open_file | echo filename1