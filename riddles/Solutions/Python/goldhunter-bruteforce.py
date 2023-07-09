# The inputs for the problem are:
#
# gold.jpg : 5 and 1.6.3.5.1.15.3.8.2.1.2.2.6.4
#
# goldlarge.jpg : 9 and 1.6.3.5.1.15.3.8.2.1.2.1.6.4.4.1.2.6.3.7.10.8.17.2.7.8.4.7.2.10.7.8.4.2.6.14.4.6.8.4.7.6.7.10

# Making the number in binary form with n-bits
def binary(number, n):
    # Replacing python prefix
    converted = str(bin(number).replace("0b", ""))
    # Adding zeros to the front to reach the desired bit representation
    for i in range(n - 1, -1, -1):
        if number < 2 ** (i - 1):
            converted = "0" + converted
    return converted


# Calculating specific number in the sequence
def calculate(row, column, sequence):
    math_thing = 2
    if row == 1:
        math_thing = 0
    else:
        for i in range(2, row, 1):
            math_thing += i + 1
    return int(sequence[math_thing + column - 1])


# Getting data
height = int(input("\nWhat is the height of the pyramid: "))
sequence = str(input("Input the pyramid sequence from top to bottom and left to right, seperated with dots: ")).split(".")

# List of every path in binary representation
# Adding the zero without the binary function
# because it won't behave...
paths = ["0" * (height - 1)]
paths_value = {}
# Adding the rest of the paths
for j in range(1, 2 ** (height - 1), 1):
    paths.append(binary(j, height))

# Going through every path where:
# 0 means going left and 1 means going right
for i in range(len(paths) - 1):
    paths_value[paths[i]] = 0
    row = 0
    column = 1
    for j in range(len(paths[i])):
        row += 1
        if paths[i][j] == '0':
            paths_value[paths[i]] += calculate(row, column, sequence)
        if paths[i][j] == '1':
            column += 1
            paths_value[paths[i]] += calculate(row, column, sequence)

# Sorting the dictionary and printing result
sorted_dict = dict(sorted(paths_value.items(), key=lambda x: x[1]))
print("\nThe best path is: |", list(sorted_dict.keys())[-1].replace("0", "Left ").replace("1", "Right ") + "| with value:", sorted_dict[list(sorted_dict.keys())[-1]])
