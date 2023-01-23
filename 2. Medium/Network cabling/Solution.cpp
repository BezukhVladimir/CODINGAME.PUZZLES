#include <bits/stdc++.h>

/*
* To have the minimal total length we must:
*  - Get the median (! not the average !) value for all houses Y position
*  - Sum all the absolute differences between house Y and the above median
*/

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();

    std::vector<long> ys;
    long minX = std::numeric_limits<long>::max();
    long maxX = std::numeric_limits<long>::min();
    for (int i = 0; i != N; ++i) {
        long X, Y;
        std::cin >> X >> Y; std::cin.ignore();
        
        if (X > maxX) { maxX = X; }
        if (X < minX) { minX = X; }
        ys.push_back(Y);
    }
    
    // we could sort also, but we only need the median 
    std::nth_element(ys.begin(), ys.begin() + N / 2, ys.end());
    long median = ys[N / 2];
    
    // accumulate the differences between each house Y and the found median value
    long minL = std::accumulate(ys.begin(), ys.end(), maxX - minX, 
                    [median](long acc, long v) { return acc+abs(v-median);});

    std::cout << minL;
}