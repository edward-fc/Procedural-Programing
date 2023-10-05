import os

filename = "amysrecords.csv"
file = open(filename, 'r')
f = file.read() 
l = []
text = ""
for line in f:
    text += line
    l.append(line)
