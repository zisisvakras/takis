#include <stdio.h>

typedef unsigned long long llu;

int main(void) {
    register llu x = 0, sumx, suma, sumb, sumc;
    while (++x) {
        sumx = x*x*x*x;
        llu a = 1;
        la: ++a;
        if (a*a*a*a >= sumx) continue;
        suma = a*a*a*a;
        llu b = a;
        lb: ++b;
        if (suma + b*b*b*b >= sumx) goto la;
        sumb = b*b*b*b;
        llu c = b;
        lc: ++c;
        if (suma + sumb + c*c*c*c >= sumx) goto lb;
        sumc = c*c*c*c;
        llu d = c;
        while (suma + sumb + sumc + d*d*d*d < sumx) ++d;
        if (suma + sumb + sumc + d*d*d*d == sumx) {
            printf("%d^4 = %d^4 + %d^4 + %d^4 + %d^4\n", x, a, b, c, d);
            return 0;
        }
        goto lc;
    }
}