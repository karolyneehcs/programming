val = int(input())

for x in range(1, val + 1):
    if (x % 2 == 0):
        print(str(x) + '^2 = ' + str(x * x))