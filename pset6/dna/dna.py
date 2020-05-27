from sys import argv, exit
import csv
import re

db = argv[1]
seq = argv[2]

file = open(seq, "r")
sequence = file.read()

list_csv = []
with open(db) as csvFile:
    reader = csv.reader(csvFile)
    strs_grp = next(reader)
    for line_list in reader:
        list_csv.append(line_list)

for i in range(len(list_csv)):
    temp_list = list_csv[i][1:]
    for j in range(len(temp_list)):
        list_csv[i][j+1] = int(temp_list[j])

strs_count = []
for str_name in strs_grp[1:]:
    pattern = "(?:" + str_name + ")+"
    sub_seqs = re.findall(pattern, sequence)
    if len(sub_seqs)>=1:
        length = len(sub_seqs[0])
        for element in sub_seqs[1:]:
            temp = len(element)
            if temp > length:
                length = temp
        count = int(length/len(str_name))
        strs_count.append(count)

for i in range(len(list_csv)):
    if strs_count == list_csv[i][1:]:
        print(list_csv[i][0])
        exit(0)
print("No match")