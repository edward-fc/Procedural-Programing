#maze list
import random
maze=[]
list_item = ["#"," ","S","E"]
maze_row_index = 10
maze_collum_index = 30
for i in range(maze_row_index):
    row=[]
    for y in range(maze_collum_index):
        row.append("#")
    maze.append(row)
maze_row_index-=1
start_point = random.randint(1,maze_collum_index)
state = True     
square_index = [1,start_point]
while state:
    #make condition to randomly make a maze that conects
    if random.randint(0,1):
        #lets try and go left
        if square_index[1]-1 != 0:
            maze[square_index[0]][square_index[1]] = " "
            square_index[1] -= 1

    else:
        #lets try and go right
        if square_index[1]+1 != maze_collum_index:
            maze[square_index[0]][square_index[1]] = " "
            square_index[1] += 1

    if random.randint(0,1):
        #lets try and go down
        if square_index[0]+1 != maze_row_index:
            maze[square_index[0]][square_index[1]] = " "
            square_index[0] += 1
     
    else:
        #lts try and go up
        if square_index[0]-1 != maze_row_index:
            maze[square_index[0]][square_index[1]] = " "
            square_index[1] -= 1
    print(square_index)
    if square_index[0]+1 == maze_row_index:
        state = False
end_point = list_item[random.randint(2,3)]
start_point_text = "S"
if end_point == "S":
    start_point_text = "E"


maze[1][start_point] = start_point_text
maze[square_index[0]][square_index[1]] = end_point

f = open("Maze game/maze.csv", "w")
s=""
for element in maze:
    for squares in element:
        s += squares
    s+="\n"
f.write(s)
f.close()