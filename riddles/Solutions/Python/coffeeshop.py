# Getting necessary data
frds = int(input("\nNumber of friends in the grid: "))
c, r = [], []
for i in range(frds):
    c.append(int(input(f"\nColumn of friend {i + 1}: ")))
    r.append(int(input(f"Row of friend {i + 1}: ")))
c.sort()
r.sort()

# Executing solution and printing the result
if frds % 2 == 1: # Odd friend case
    i = int((frds - 1) / 2)
    print(f"\nThe optimal location for the coffee shop is: ({c[i]},{r[i]})")
else: # Even friend case
    i = int(frds / 2)
    print(f"\nThe optimal locations for the coffee shop are: ({c[i - 1]}-{c[i]},{r[i - 1]}-{r[i]})")
