#include <stdio.h>

int summa(int n) { return n ? n % 10 + summa(n / 10) : 0; }

main(r1, r2)
{
    if (r1 == 1)  scanf("%d%d", &r1, &r2);
    if (r1 == r2) printf("%d", r1);
    if (r1 > r2)  main (r1            , r2 + summa(r2));
    if (r1 < r2)  main (r1 + summa(r1), r2); 
}