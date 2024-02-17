#maze list
import random
maze=[]
list_item = ["#"," ","S","E"]
maze_row_index = 40
maze_collum_index = 100
for i in range(maze_row_index):
    row=[]
    for y in range(maze_collum_index):
        row.append("#")
    maze.append(row)
maze_row_index-=1
start_point = random.randint(1,maze_collum_index-2)
state = True     
square_index = [1,start_point]
while state:
    print(square_index[1]-1 != 0,square_index[1]-1)
    #make condition to randomly make a maze that conects
    #lets try and go left
    if square_index[1]-1 != 0:
        if random.randint(0,1):
            maze[square_index[0]][square_index[1]] = " "
            square_index[1] -= 1
    #lets try and go right
    if square_index[1]+1 != maze_collum_index-1:
        if random.randint(0,1):
            maze[square_index[0]][square_index[1]] = " "
            square_index[1] += 1

    #lets try and go down
    if square_index[0]+1 != maze_row_index:
        if random.randint(0,1):
            maze[square_index[0]][square_index[1]] = " "
            square_index[0] += 1
     
    #lts try and go up
    if square_index[0]-1 != 1:
        if random.randint(0,1):
            maze[square_index[0]][square_index[1]] = " "
            square_index[0] -= 1
    if square_index[0]+1 == maze_row_index:
        state = False
end_point = list_item[random.randint(2,3)]
start_point_text = "S"
if end_point == "S":
    start_point_text = "E"


maze[1][start_point] = start_point_text
maze[square_index[0]][square_index[1]] = end_point

f = open("Maze game/maze3.csv", "w")
s=""
for element in maze:
    for squares in element:
        s += squares
    s+="\n"
f.write(s)
print(s)
f.close()