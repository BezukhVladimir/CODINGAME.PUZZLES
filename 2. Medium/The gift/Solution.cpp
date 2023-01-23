#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> budgets(N);
    for (auto& i: budgets)
	cin >> i;

    auto b = budgets.begin(),
	 e = budgets.end();
    sort(b, e);

    if (C > accumulate(b, e, 0))
        cout << "IMPOSSIBLE" << endl;
    else {
        for (auto i = b; i != e; ++i) {
            auto share = min(*i, C / int (e - i));
            cout << share << endl;
            C -= share;
        }
    }
}