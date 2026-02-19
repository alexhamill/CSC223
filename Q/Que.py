line = []
with open("shoppers.txt", "r") as f:
    line = f.readlines()

for i in range(len(line)):
    line[i] = line[i].strip()

print(line)