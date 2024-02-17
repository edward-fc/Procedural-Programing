# Compile and RUN the MAZE script
gcc maze.c -o maze

# Initialize counters
total_tests=0
passed_tests=0

# Test the open_file function for 4 different files
#First test for 10x10
echo "Test the function open and read for maze 10x10"
#compile the test
gcc test_open_file.c -o test_open_file
filename1="maze.csv"
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

# Test the read_file function with correct number of row (answer expected 10)
gcc test_read_file.c -o test_read_file
let total_tests+=1
output=$(echo $filename1 | ./test_read_file)
#get the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 10 ]; then
    echo "The program readed the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During reading, Something when wrong with the exit status: $exit_status"
fi

echo //

#Second test for maze 10x20
echo "Test the function open and read for maze 10x20"
gcc test_open_file.c -o test_open_file
filename1="maze1.csv"
let total_tests+=1
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During opening, Something when wrong with the exit status: $exit_status"
fi

# Test the read_file function with correct number of row (answer expected 10)
gcc test_read_file.c -o test_read_file
let total_tests+=1
output=$(echo $filename1 | ./test_read_file)
#get the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 10 ]; then
    echo "The program readed the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During reading, Something when wrong with the exit status: $exit_status"
fi

echo //

#Third test for maze 30x60
echo "Test the function open and read for maze 30x60"
gcc test_open_file.c -o test_open_file
filename1="maze2.csv"
let total_tests+=1
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During opening, Something when wrong with the exit status: $exit_status"
fi

# Test the read_file function with correct number of row (answer expected 30)
gcc test_read_file.c -o test_read_file
let total_tests+=1
output=$(echo $filename1 | ./test_read_file)
#get the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 30 ]; then
    echo "The program readed the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During reading, Something when wrong with the exit status: $exit_status"
fi

echo //

#Fourth test for maze 50x100
echo "Test the function open and read for maze 50x100"
gcc test_open_file.c -o test_open_file
filename1="maze3.csv"
let total_tests+=1
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During opening, Something when wrong with the exit status: $exit_status"
fi

# Test the read_file function with correct number of row (answer expected 10)
gcc test_read_file.c -o test_read_file
let total_tests+=1
output=$(echo $filename1 | ./test_read_file)
#get the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 50 ]; then
    echo "The program readed the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During reading, Something when wrong with the exit status: $exit_status"
fi

echo //

#5 test for maze 100x100
echo "Test the function open and read for maze 100x100"
gcc test_open_file.c -o test_open_file
filename1="maze4.csv"
let total_tests+=1
output=$(echo $filename1 | ./test_open_file)
# Capture the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 0 ]; then
    echo "The program opened the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During opening, Something when wrong with the exit status: $exit_status"
fi

# Test the read_file function with correct number of row (answer expected 10)
gcc test_read_file.c -o test_read_file
let total_tests+=1
output=$(echo $filename1 | ./test_read_file)
#get the exit status
exit_status=$?
#check the exit status
if [ $exit_status -eq 100 ]; then
    echo "The program readed the file sucessfully for $filename1"
    let passed_tests+=1
else
    echo "During reading, Something when wrong with the exit status: $exit_status"
fi

# Report results
echo "$passed_tests/$total_tests tests were successful."