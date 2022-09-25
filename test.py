x = int(input())
for i in range(0, x):

    z = ""
    for j in range(0, 2 * (i + 1) - 1):
        z = z + "*"
    y = ""
    for k in range(0, x - i - 1):
        y = y + " "
    print(y + z)