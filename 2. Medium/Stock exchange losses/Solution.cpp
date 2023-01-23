#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    
    int value, spike = 0, loss = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (value > spike) spike = value;
        if ((value - spike) < loss) loss = value - spike;
    }

    cout << loss << endl;
}