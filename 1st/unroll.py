def sequence(unroll, primes):
    modulo = 1
    for i in range(unroll):
        modulo *= primes[i]
    modulo += primes[unroll - 1]
    steps = []
    for i in range(modulo):
        steps.append(i + 1)
    for i in range(modulo):
        for j in range(unroll):
            if (i + 1) % primes[j] == 0:
                steps[i] = 0            
    step_seq = []
    step_counter = 0
    for i in range(primes[unroll], len(steps), 1):
        if steps[i] == 0:
            step_counter += 1
        else:
            step_seq.append(step_counter + 1)
            step_counter = 0
    step_seq.append(primes[unroll] - 1)
    return step_seq


primes = [2,3,5,7,11,13,17,19,23,29,31]
unroll = int(input("How many primes to unroll for mertens: "))
step_seq = sequence(unroll, primes)
unrollp = int(input("How many primes to unroll for perfect: "))
step_seqp = sequence(unrollp, primes)

squares = "if("
for i in range(unroll - 1):
    squares += f"j % {primes[i]**2} == 0 ||"
squares += f"j % {primes[unroll - 1]**2} == 0" + ") {\n"

# file stuff
tab = "    "
mertsumd = open('unrolled.c', 'w')
mertsumd.write("#include <stdio.h>\n#define MAXEXP 8\n\nint main() {\n\n")
mertsumd.write(tab + "int mertens_bound = 19;\n")
mertsumd.write(tab + "int mertens_zp = 0;\n")
mertsumd.write(tab + "int mertens_prev = 0;\n")
mertsumd.write(tab + "int j = 0;\n\n")
mertsumd.write(tab + "for (int i = 1; i <= MAXEXP; i++) {\n")
mertsumd.write(tab*2 + "while (j < mertens_bound) {\n\n")
mertsumd.write(tab*3 + "j++;\n\n")
mertsumd.write(tab*3 + squares)
mertsumd.write(tab*4 + "if (mertens_prev == 0) {\n")
mertsumd.write(tab*5 + "mertens_zp++;\n")
mertsumd.write(tab*4 + "}\n")
mertsumd.write(tab*4 + "if (mertens_bound - 18 <= j) {\n")
mertsumd.write(tab*5 + "printf(\"M(%d) = %d\\n\", j, mertens_prev);\n")
mertsumd.write(tab*4 + "}\n")
mertsumd.write(tab*4 + "continue;\n")
mertsumd.write(tab*3 + "}\n\n")
mertsumd.write(tab*3 + "int mobius_temp = j;\n")
mertsumd.write(tab*3 + f"int mobius_factor = {primes[unroll]};\n")
mertsumd.write(tab*3 + "int mobius_factor_count = 0;\n")
mertsumd.write(tab*3 + "int mobius_bool = 1;\n\n")

for i in range(unroll):
    mertsumd.write(tab*3 + f"if(mobius_temp % {primes[i]} == 0)" + " {\n")
    mertsumd.write(tab*4 + f"mobius_temp /= {primes[i]};\n")
    mertsumd.write(tab*4 + "mobius_factor_count++;\n")
    mertsumd.write(tab*3 + "}\n")

mertsumd.write("\n" + tab*3 + "while (mobius_factor * mobius_factor <= mobius_temp) {\n")

for i in range(len(step_seq)):
    mertsumd.write(tab*4 + "if (mobius_temp % mobius_factor == 0) {\n")
    mertsumd.write(tab*5 + "mobius_temp /= mobius_factor;\n")
    mertsumd.write(tab*5 + "if (mobius_temp % mobius_factor == 0) {\n")
    mertsumd.write(tab*6 + "mobius_bool = 0;\n")
    mertsumd.write(tab*6 + "break;\n")
    mertsumd.write(tab*5 + "}\n")
    mertsumd.write(tab*5 + "mobius_factor_count++;\n")
    mertsumd.write(tab*4 + "}\n")
    mertsumd.write(tab*4 + f"mobius_factor += {step_seq[i]};\n")

mertsumd.write(tab*3 + "}\n")
mertsumd.write(tab*3 + "if (mobius_temp != 1) {\n")
mertsumd.write(tab*4 + "mobius_factor_count++;\n")
mertsumd.write(tab*3 + "}\n\n")
mertsumd.write(tab*3 + "if (mobius_bool) {\n")
mertsumd.write(tab*4 + "if (mobius_factor_count % 2 == 0) {\n")
mertsumd.write(tab*5 + "mertens_prev++;\n")
mertsumd.write(tab*4 + "} else {\n")
mertsumd.write(tab*5 + "mertens_prev--;\n")
mertsumd.write(tab*4 + "}\n")
mertsumd.write(tab*3 + "}\n\n")
mertsumd.write(tab*3 + "if (mertens_prev == 0) {\n")
mertsumd.write(tab*4 + "mertens_zp++;\n")
mertsumd.write(tab*3 + "}\n")
mertsumd.write(tab*3 + "if (mertens_bound - 18 <= j) {\n")
mertsumd.write(tab*4 + "printf(\"M(%d) = %d\\n\", j, mertens_prev);\n")
mertsumd.write(tab*3 + "}\n")
mertsumd.write(tab*2 + "}\n")
mertsumd.write(tab*2 + "if(i != MAXEXP) {\n")
mertsumd.write(tab*3 + "printf(\"..........\\n\");\n")
mertsumd.write(tab*2 + "}\n")
mertsumd.write(tab*2 + "mertens_bound = mertens_bound * 10 - 81;\n")
mertsumd.write(tab + "}\n")
mertsumd.write(tab + "printf(\"\\nFound %d zero points of the Mertens function\\n\\n\", mertens_zp);\n\n")
mertsumd.write(tab + "int perfect_bound = mertens_zp * 1000;\n")
mertsumd.write(tab + "int abundant_counter = 0;\n")
mertsumd.write(tab + "int deficient_counter = 0;\n\n")
mertsumd.write(tab + "printf(\"Checking numbers in the range [2,%d]\\n\\n\", perfect_bound);\n\n")
mertsumd.write(tab + "for (int i = 2; i <= perfect_bound; i++) {\n\n")
mertsumd.write(tab*2 + "int divisor = 2;\n")
mertsumd.write(tab*2 + "int divisor_sum = 1;\n")
mertsumd.write(tab*2 + "int before;\n\n")
mertsumd.write(tab*2 + "int temp = i;\n\n")

for i in range(unrollp): 
    mertsumd.write(tab*2 + "before = divisor_sum;\n")
    mertsumd.write(tab*2 + "while (temp % divisor == 0) {\n")
    mertsumd.write(tab*3 + "divisor_sum = divisor_sum * divisor + before;\n")
    mertsumd.write(tab*3 + "temp /= divisor;\n")
    mertsumd.write(tab*2 + "}\n")
    mertsumd.write(tab*2 + f"divisor = {primes[i + 1]};\n\n")

mertsumd.write(tab*2 + "while (divisor * divisor <= temp) {\n")

for i in range(len(step_seqp)):
    mertsumd.write(tab*3 + "before = divisor_sum;\n")
    mertsumd.write(tab*3 + "while (temp % divisor == 0) {\n")
    mertsumd.write(tab*4 + "divisor_sum = divisor_sum * divisor + before;\n")
    mertsumd.write(tab*4 + "temp /= divisor;\n")
    mertsumd.write(tab*3 + "}\n")
    mertsumd.write(tab*3 + f"divisor += {step_seqp[i]};\n\n")
    
mertsumd.write(tab*2 + "}\n")
mertsumd.write(tab*2 + "if (temp != 1) {\n")
mertsumd.write(tab*3 + "divisor_sum *= temp + 1;\n")
mertsumd.write(tab*2 + "}\n")
mertsumd.write(tab*2 + "divisor_sum -= i;\n\n")
mertsumd.write(tab*2 + "if(divisor_sum == i) {\n")
mertsumd.write(tab*3 + "printf(\"Found perfect number: %d\\n\", i);\n")
mertsumd.write(tab*2 + "} else if (divisor_sum < i) {\n")
mertsumd.write(tab*3 + "deficient_counter++;\n")
mertsumd.write(tab*2 + "} else {\n")
mertsumd.write(tab*3 + "abundant_counter++;\n")
mertsumd.write(tab*2 + "}\n")
mertsumd.write(tab + "}\n\n")
mertsumd.write(tab + "printf(\"\\nFound %d deficient numbers\\n\", deficient_counter);\n")
mertsumd.write(tab + "printf(\"Found %d abundant numbers\\n\", abundant_counter);\n")
mertsumd.write("}\n")