# The inputs for the problem are:
#
# gold.jpg : 5 and 0.1.6.3.5.1.15.3.8.2.1.2.2.6.4
#
# goldlarge.jpg : 9 and 0.1.6.3.5.1.15.3.8.2.1.2.1.6.4.4.1.2.6.3.7.10.8.17.2.7.8.4.7.2.10.7.8.4.2.6.14.4.6.8.4.7.6.7.10

# Getting data
height = int(input("\nWhat is the height of the pyramid: "))
sequence = str(input("Input the pyramid sequence from top to bottom and left to right, seperated with dots: ")).split(".")

# Initializing matrix with desired dimensions
pyramid = [[0 for j in range(height)] for i in range(height)]

# Putting sequence in grid
for i in range(height):
    for j in range(i + 1):
        pyramid[i][j] = int(sequence[int(1/2*i*(i + 1)) + j])

# Executing the algorithm described by solution
for i in range(1, height): # rows
    for j in range(i + 1): # columns
        if j == 0: # left most column
            pyramid[i][j] += pyramid[i - 1][j] 
        elif j == i: # right most column
            pyramid[i][j] += pyramid[i - 1][j - 1]
        else:
            if pyramid[i - 1][j - 1] < pyramid[i - 1][j]:
                pyramid[i][j] += pyramid[i - 1][j]
            else:
                pyramid[i][j] += pyramid[i - 1][j - 1]

# Finding highest value point
best, col = 0, 0
for i in range(height):
    if best < pyramid[height - 1][i]:
        best, col = pyramid[height - 1][i], i

# Preparing answer
answer = "| with value: " + str(best)
for i in range(height - 1, 0, -1):
    if col == 0:
        answer = "Left " + answer
    elif col == i:
        answer = "Right " + answer
        col -= 1
    else:
        if pyramid[i - 1][col - 1] < pyramid[i - 1][col]:
            answer = "Left " + answer
        else:
            answer = "Right " + answer
            col -= 1

# Printing the result
print("\nThe best path is: |", answer)
