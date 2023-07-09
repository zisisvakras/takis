# Getting necessary information
rows = int(input("\nEnter the number of rows: "))
columns = int(input("Enter the number of columns: "))
# Initializing matrix with desired dimensions
grid = [[0 for j in range(columns)] for i in range(rows)]
# Assigning every point the value described by solution
for i in range(rows):
    for j in range(columns):
        if j == 0 or i == 0:
            grid[i][j] = 1
        else:
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1]
# Printing last element of matrix
print("\nThe different paths are:", grid[-1][-1])
