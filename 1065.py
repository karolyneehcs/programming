val = []
even = 0

val.append(int(input()))
val.append(int(input()))
val.append(int(input()))
val.append(int(input()))
val.append(int(input()))

print(val)
for x in val:
    if (x % 2 == 0):
        even += 1

print(str(even) + ' valores pares')