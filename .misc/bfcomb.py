from math import factorial
nst = int(input("Input number of stops: "))
nfl = int(input("Input highest floor: "))
combs = 0
for i in range(nst + 1):
    combs += factorial(nfl) / factorial(i) / factorial(nfl - i)

print("Number of combinations is: " + str(combs))