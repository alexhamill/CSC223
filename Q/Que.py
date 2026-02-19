import random

line = []
store = []
with open("shoppers.txt", "r") as f:
    store = f.readstores()

for i in range(len(store)):
    store[i] = store[i].strip()

while len(store) > 0:
    if (len(line) >= 10):
        leave()
    elif (len(line) == 0):
        enter()


def leave():
    print(line.pop(0), "leaves the store.")

def enter():
    cur = random.randint(0, len(store) - 1)
    line.append(store.pop(cur))

print(line)
print(store)