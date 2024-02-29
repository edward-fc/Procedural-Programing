#This is a test script that will near the entirety of the MazeDataStruct.h file and the maze.c 
# Some test must pass and some must fail

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
    if [ $exit_status == 0 ]; then
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
    if [ $exit_status == $2 ]; then
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
    if [ $exit_status == $2 ]; then
        echo "The file data is sucessfully extracted from the file $filename1"
        let passed_tests+=1
    else
        echo "During data check, Something when wrong with the exit status: $exit_status and the output $output"
    fi
}
find_end_position_test() {
    #Test the function Player_position find_end_postion(MAZE MAZE) in MazeDataStruct.h

    gcc test_find_end_position.c -o test_find_end_position
    let total_tests+=1
    filename1="$1"
    output=$(echo $filename1 | ./test_find_end_position)
    #get the exit status
    exit_status=$?
    #check the exit status
    if [ $exit_status == 0 ] && [ $output == $2 ]; then
        echo "The end coordonates were sucessfully found from the file $filename1 and the coordonates are $output"
        let passed_tests+=1
    else
        echo "During the process of finding the end positions, Something when wrong with the exit status: $exit_status and the output $output"
    fi
}

find_start_position_test() {
    #Test the function Player_position find_start_postion(MAZE MAZE) in MazeDataStruct.h

    gcc test_find_start_position.c -o test_find_start_position
    let total_tests+=1
    filename1="$1"
    output=$(echo $filename1 | ./test_find_start_position)
    #get the exit status
    exit_status=$?
    #check the exit status
    if [ $exit_status == 0 ] && [ $output == $2 ]; then
        echo "The start coordonates were sucessfully found from the file $filename1 and the coordonates are $output"
        let passed_tests+=1
    else
        echo "During the process of finding the start positions, Something when wrong with the exit status: $exit_status and the output $output"
    fi
}

test_checkWinCondition() {
    #Test the function Player_position checkWinCondition(MAZE,PLAYER_Position) in MazeDataStruct.h

    gcc test_checkWinCondition.c -o test_checkWinCondition
    let total_tests+=1
    filename1="$1"
    output=$(echo $filename1 | ./test_checkWinCondition)
    #get the exit status
    exit_status=$?
    #check the exit status
    if [ $exit_status == 0 ]; then
        echo "The Win Condition was sucessful to detect"
        let passed_tests+=1
    else
        echo "During the process of check Win Condition, Something when wrong with the exit status: $exit_status"
    fi
}

complete_maze() {
    #update the total number of test run
    let total_tests+=1

    # compile and run maze.c
    gcc ../maze.c -o ../maze
    executable=".././maze"

    #initialise the line number from the instruction 
    line_number="$1"

    # read instructions from file and remove comma 
    # sed -n "${line_number}p" script.txt is to get string from a specific line https://www.gnu.org/software/sed/manual/sed.html
    # then we pipeline it to tr -d to delete the charcteres that we don't want https://linuxcommand.org/lc3_man_pages/tr1.html
    instructions=$(sed -n "${line_number}p" script.txt | tr -d ',')
    
    {
    # enter the filename first
    echo $2
    # Feed instructions to the executable one by one
    for (( i=0; i<${#instructions}; i++ )); do
        echo "${instructions:$i:1}"
    #execute the program
    done 
    # the /dev/null 2>&1 was found by https://www.squash.io/preventing-terminal-print-from-bash-scripts-in-linux/#:~:text=Running%20a%20Bash%20Script%20in%20Silent%20Mode,-Running%20a%20bash&text=the%20null%20device.-,The%20%E2%80%9C%3E%20%2Fdev%2Fnull%202%3E%261%E2%80%9D%20syntax,error%20messages%20in%20the%20terminal.
    } | $executable >/dev/null 2>&1

    #get exit status
    exit_status=$?

    if [ $exit_status == 0 ]; then
        echo "Sucessful completed the maze."
        let passed_tests+=1
    else
        echo "During maze, Something when wrong with the exit status: $exit_status must be wrong maze file or wrong instructions"
    fi
}

# Initialize counters
total_tests=0
passed_tests=0

open_file_test "10x10" "../test_data/maze.csv"
read_file_test "../test_data/maze.csv" 10
data_checker_test "../test_data/maze.csv" 11
find_end_position_test "../test_data/maze.csv" "1,7"
find_start_position_test "../test_data/maze.csv" "8,5"
test_checkWinCondition "../test_data/maze.csv"
complete_maze 1 "../test_data/maze.csv"

echo //

open_file_test "10x20" "../test_data/maze1.csv"
read_file_test "../test_data/maze1.csv" 10
data_checker_test "../test_data/maze1.csv" 21
find_end_position_test "../test_data/maze1.csv" "1,18"
find_start_position_test "../test_data/maze1.csv" "8,14"
test_checkWinCondition "../test_data/maze1.csv"
complete_maze 2 "../test_data/maze1.csv"

echo //

open_file_test "30x60" "../test_data/maze2.csv"
read_file_test "../test_data/maze2.csv" 30
data_checker_test "../test_data/maze2.csv" 61
find_end_position_test "../test_data/maze2.csv" "28,27"
find_start_position_test "../test_data/maze2.csv" "1,20"
test_checkWinCondition "../test_data/maze2.csv"
complete_maze 3 "../test_data/maze2.csv"

echo //

open_file_test "50x100" "../test_data/maze3.csv"
read_file_test "../test_data/maze3.csv" 50
data_checker_test "../test_data/maze3.csv" 101
find_end_position_test "../test_data/maze3.csv" "1,57"
find_start_position_test "../test_data/maze3.csv" "48,43"
test_checkWinCondition "../test_data/maze3.csv"
complete_maze 4 "../test_data/maze3.csv"

echo //

open_file_test "100x100" "../test_data/maze4.csv"
read_file_test "../test_data/maze4.csv" 100
data_checker_test "../test_data/maze4.csv" 101
find_end_position_test "../test_data/maze4.csv" "37,98"
find_start_position_test "../test_data/maze4.csv" "92,1"
test_checkWinCondition "../test_data/maze4.csv"
complete_maze 5 "../test_data/maze4.csv"

echo //

# Report results
echo Test Results
echo "$passed_tests/$total_tests tests were successful."

# lets make tests with non conform maps 
echo 
# Initialize counters
total_tests=0
passed_tests=0

open_file_test "10x10" "../test_data/maze_invalid.csv"
read_file_test "../test_data/maze_invalid.csv" 10
data_checker_test "../test_data/maze_invalid.csv" 11
find_end_position_test "../test_data/maze_invalid.csv" "1,7"
find_start_position_test "../test_data/maze_invalid.csv" "8,5"
test_checkWinCondition "../test_data/maze_invalid.csv"
complete_maze 1 "../test_data/maze_invalid.csv"

echo //

open_file_test "10x20" "../test_data/maze1_invalid.csv"
read_file_test "../test_data/maze1_invalid.csv" 10
data_checker_test "../test_data/maze1_invalid.csv" 21
find_end_position_test "../test_data/maze1_invalid.csv" "1,18"
find_start_position_test "../test_data/maze1_invalid.csv" "8,14"
test_checkWinCondition "../test_data/maze1_invalid.csv"
complete_maze 2 "../test_data/maze1_invalid.csv"

echo //

open_file_test "30x60" "../test_data/maze2_invalid.csv"
read_file_test "../test_data/maze2_invalid.csv" 30
data_checker_test "../test_data/maze2_invalid.csv" 61
find_end_position_test "../test_data/maze2_invalid.csv" "28,27"
find_start_position_test "../test_data/maze2_invalid.csv" "1,20"
test_checkWinCondition "../test_data/maze2_invalid.csv"
complete_maze 3 "../test_data/maze2_invalid.csv"

echo //

open_file_test "50x100" "../test_data/maze3_invalid.csv"
read_file_test "../test_data/maze3_invalid.csv" 50
data_checker_test "../test_data/maze3_invalid.csv" 101
find_end_position_test "../test_data/maze3_invalid.csv" "1,57"
find_start_position_test "../test_data/maze3_invalid.csv" "48,43"
test_checkWinCondition "../test_data/maze3_invalid.csv"
complete_maze 4 "../test_data/maze3_invalid.csv"

echo //

open_file_test "100x100" "../test_data/maze4_invalid.csv"
read_file_test "../test_data/maze4_invalid.csv" 100
data_checker_test "../test_data/maze4_invalid.csv" 101
find_end_position_test "../test_data/maze4_invalid.csv" "37,98"
find_start_position_test "../test_data/maze4_invalid.csv" "92,1"
test_checkWinCondition "../test_data/maze4_invalid.csv"
complete_maze 5 "../test_data/maze4_invalid.csv"

echo //

# Report results
echo Test Results for non comfrom maps
echo "$passed_tests/$total_tests tests were successful."