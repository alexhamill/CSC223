import random

def leave1():
    if len(line) > 0:
        print(line.pop(0), "finishes checkout and leaves line 1.")

def leave2():
    if len(line2) > 0:
        print(line2.pop(0), "finishes checkout and leaves line 2.")

def enter1():
    if len(store) > 0:
        cur = random.randint(0, len(store) - 1)
        line.append(store.pop(cur))
        print(line[-1], "gets in line 1.")

def enter2():
    if len(store) > 0:
        cur = random.randint(0, len(store) - 1)
        line2.append(store.pop(cur))
        print(line2[-1], "gets in line 2.")

line = []
line2 = []
store = []
with open("shoppers.txt", "r") as f:
    store = f.readlines()

for i in range(len(store)):
    store[i] = store[i].strip()


while len(line) > 0 or len(line2) > 0 or len(store) > 0:
    if (len(line) >= 10):
        leave1()
    elif (len(line2) >= 10):
        leave2()
    else:
        if random.randint(0, 3) == 0:
            if random.randint(0, 1) == 0:
                leave1()
            else:
                leave2()
        else:
            if random.randint(0, 1) == 0:
                enter1()
            else:
                enter2()
    # print("Line 1:", line)
    # print("Line 2:", line2)
    # print("Store:", store)
