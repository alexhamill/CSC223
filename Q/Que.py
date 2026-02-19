import random

def leave():
    print(line.pop(0), "finishes checkout and leaves.")

def enter():
    if len(store) > 0:
        cur = random.randint(0, len(store) - 1)
        line.append(store.pop(cur))
        print(line[-1], "gets in line.")


line = []
store = []
with open("shoppers.txt", "r") as f:
    store = f.readlines()

for i in range(len(store)):
    store[i] = store[i].strip()


while len(line) > 0 or len(store) > 0:
    if (len(line) >= 10):
        leave()
    else:
        if random.randint(0, 3) == 0:
            leave()
        else:
            enter()
