
# Initialize counters
total_tests=0
passed_tests=0

open_file_test() {
    # Test the open_file function
    echo "Test the function open: $1"
    #compile the test
    gcc test_open_file.c -o test_open_file
    filename1="$2"
    let total_tests+=1
    output=$(echo $filename1 | ./test_open_file)
    # Capture the exit status
    exit_status=$?
    #check the exit status
    if [ $exit_status -eq 0 ]; then
        echo "The program opened the file sucessfully for $filename1"
        let passed_tests+=1
    else
        echo "during opening, Something when wrong with the exit status: $exit_status"
    fi
}

read_file_test() {
    # Test the read_file function with correct number of row
    gcc test_read_file.c -o test_read_file
    let total_tests+=1
    filename1="$1"
    output=$(echo $filename1 | ./test_read_file)
    #get the exit status
    exit_status=$?
    #check the exit status
    if [ $exit_status -eq $2 ]; then
        echo "The program readed the file sucessfully for $filename1"
        let passed_tests+=1
    else
        echo "During reading, Something when wrong with the exit status: $exit_status"
    fi
}

data_checker_test() {
    #Test the function int data_checker(MAZE MAZE, int count) in MazeDataStruct.h

    gcc test_data_check.c -o test_data_check
    let total_tests+=1
    filename1="$1"
    output=$(echo $filename1 | ./test_data_check)
    #get the exit status
    exit_status=$?
    #check the exit status
    if [ $exit_status -eq $2 ]; then
        echo "The file data is sucessfully extracted from the file $filename1"
        let passed_tests+=1
    else
        echo "During data check, Something when wrong with the exit status: $exit_status and the output $output"
    fi
}
complete_maze() {
    #update the total number of test run
    let total_tests+=1

    # compile and run maze.c
    gcc maze.c -o maze
    executable="./maze"

    #initialise the line number from the instruction 
    line_number="$1"

    # read instructions from file and remove comma
    instructions=$(sed -n "${line_number}p" instructions.txt | tr -d ',')
    echo $instructions

    # Feed instructions to the executable one by one
    for (( i=0; i<${#instructions}; i++ )); do
        echo "${instructions:$i:1}"
    #execute the program
    done | $executable
    #get exit status
    exit_status=$?

    if [ $exit_status -eq 0 ]; then
        echo "Sucessful completed the maze."
        let passed_tests+=1
    else
        echo "During maze, Something when wrong with the exit status: $exit_status must be wrong maze file or wrong instructions"
    fi
}


open_file_test "10x10" "maze.csv"
read_file_test "maze.csv" 10
data_checker_test "maze.csv" 11
complete_maze 1

echo //

open_file_test "10x20" "maze1.csv"
read_file_test "maze1.csv" 10
data_checker_test "maze1.csv" 21
complete_maze 2

echo //

open_file_test "30x60" "maze2.csv"
read_file_test "maze2.csv" 30
data_checker_test "maze2.csv" 61
complete_maze 3

echo //

open_file_test "50x100" "maze3.csv"
read_file_test "maze3.csv" 50
data_checker_test "maze3.csv" 101
complete_maze 4

echo //

open_file_test "100x100" "maze4.csv"
read_file_test "maze4.csv" 100
data_checker_test "maze4.csv" 101
complete_maze 5


# Report results
echo "$passed_tests/$total_tests tests were successful."
