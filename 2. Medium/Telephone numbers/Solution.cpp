#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();

    set<string> nums;
    for (int i{0}; i != N; ++i) {
        string telephone;
        cin >> telephone; cin.ignore();

        for(int j{1}; j <= telephone.size(); ++j)
            nums.insert(telephone.substr(0, j));
    }

    cout << nums.size() << endl;
}