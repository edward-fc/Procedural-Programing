# Compile and RUN the MAZE script
gcc maze.c -o maze


# Test the open_file function for 4 different files
#first test for 
gcc test_open_file.c -o test_open_file
filename1="maze.csv"
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
else
    echo "Something when wrong with the exit status: $exit_status"
fi
# Test the read_file function with correct number of row
gcc test_open_file.c -o test_open_file
filename1="maze.csv"
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
else
    echo "Something when wrong with the exit status: $exit_status"

gcc test_open_file.c -o test_open_file
filename1="maze1.csv"
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
else
    echo "Something when wrong with the exit status: $exit_status"
fi

gcc test_open_file.c -o test_open_file
filename1="maze2.csv"
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
else
    echo "Something when wrong with the exit status: $exit_status"
fi

gcc test_open_file.c -o test_open_file
filename1="maze3.csv"
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
else
    echo "Something when wrong with the exit status: $exit_status"
fi