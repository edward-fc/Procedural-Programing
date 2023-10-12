import os

filename = "amysrecords.csv"
file = open(filename, 'r')
f = file.read() 
l = []
Rank = []
Name = []
Group = []
Year = []
memory = ""
counter = 0
circle = 1
for line in f:
    if line != ",":
        memory += line
    else:
        if circle == 1:
            Rank.append(memory)   
        if circle == 2:
            Name.append(memory)
        if circle == 3:
            Group.append(memory)
        if circle == 4:
            Year.append(memory)
            counter+=1
        if counter==4:
            counter=0
        circle=0
        memory =""
        circle+=1

print(Rank)