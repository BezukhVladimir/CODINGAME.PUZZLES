#include <cmath>
#include <iostream>
#include <algorithm>

int main() {
    size_t R, V, C, N; std::cin >> R >> V;
    size_t robbers[R] = {};
    
    while(std::cin >> C >> N)
        *std::min_element(robbers, robbers + R)
            += std::pow(10, N) * std::pow(5, C - N);
    
    std::cout << *std::max_element(robbers, robbers + R);
}