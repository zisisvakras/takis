from math import factorial

# Getting necessary information
rows = int(input("\nEnter the number of rows: "))
columns = int(input("Enter the number of columns: "))

# Calculating the answer based on combinatorics
answer = int(factorial(rows + columns - 2) / (factorial(rows - 1) * factorial(columns - 1)))

# Printing the result
print("\nThe different paths are:", answer)
