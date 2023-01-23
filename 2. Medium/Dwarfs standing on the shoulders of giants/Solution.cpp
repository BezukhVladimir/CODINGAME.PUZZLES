#include <bits/stdc++.h>

using namespace std;

const int root = -1;
unordered_map <int, vector<int>> successors;
unordered_map <int, int> cache;

int getMaxDepth (int max_depth, int person) {
    if (!cache[person]) {
        auto& S = successors[person];
        cache[person] = 1 + accumulate(begin(S), end(S), 0, getMaxDepth);
    }
    
    return max(max_depth, cache[person]);
}

int main() {
    int n; cin >> n;
    for (int i{0}; i != n; ++i) {
        int x, y; cin >> x >> y;
        successors[root].emplace_back(x);
        successors[x].emplace_back(y);
    }

    cout << getMaxDepth(0, root) - 1 << endl;
}