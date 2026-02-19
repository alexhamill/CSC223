import random
import math
from statistics import NormalDist



avgshoptime = 15
avgcheckouttime = 3
shopstd = 3
checkoutstd = 1

def z_from_percentile(p):
    if  0 < p < 1:
        return NormalDist().inv_cdf(p)

def leave():
    print(line.pop(0), "finishes checkout and leaves.")
    timeinline.pop(0)

def enter():
    if len(store) > 0:
        cur = random.randint(0, len(store) - 1)
        line.append(store.pop(cur))
        ltime = round(z_from_percentile((random.randint(1,100)/100) * checkoutstd)+avgcheckouttime)
        timeinline.append(ltime)
        print(line[-1], "gets in line.")

def enterspecific(name):
    timeinstore.remove(timeinstore[store.index(name)])
    line.append(name)
    store.remove(name)
    ltime = round(z_from_percentile((random.randint(1,100)/100) * checkoutstd)+avgcheckouttime)
    timeinline.append(ltime)
    print(line[-1], "gets in line.")

timeinline = []
timeinstore = []
line = []
store = []
with open("shoppers.txt", "r") as f:
    store = f.readlines()

for i in range(len(store)):
    store[i] = store[i].strip()
    stime = round(z_from_percentile(random.randint(1,100)/100)* shopstd + avgshoptime)
    timeinstore.append(stime)

s = 0
l = 0

#each repersents one minute
time =0
while len(line) > 0 or len(store) > 0 or len(store) > 0:
    print ("Time: ", 9+(time//60),":",time%60)
    
    if len(line) > 0 and l >= timeinline[0]:
        l=0
        leave()
    i=0
    while i < len(store):
        if len(timeinstore) > 0 and timeinstore[i] < s and len(line) <= 10:
            enterspecific(store[i])
        else:
            i += 1

    # if len(store) > 0 and s >= timeinstore[0]:
    #     s=0
    #     enter()

    s += 1
    l += 1
    time += 1

# print(line)
# print(store)