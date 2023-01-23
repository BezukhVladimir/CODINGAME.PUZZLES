#include <iostream>

int summa(int n) { return n ? n % 10 + summa(n / 10) : 0; }

int main(int r1, int r2) {
    if (r1 ==  1) std::cin >> r1 >> r2;
    if (r1 == r2) std::cout << r1;
    if (r1 >  r2) main(r1, r2 + summa(r2));
    if (r1 <  r2) main(r1 + summa(r1), r2); 
}