#include <bits/stdc++.h>

using namespace std;

int main()
{
    string R; int L;
    cin >> R >> L; --L; cin.ignore();
    
    ostringstream oss(R);
    for (int i = 0; i < L; ++i)
    {
        istringstream iss(oss.str());
        oss.str("");
        
        int v;
        iss >> v;
        while (iss)
        {
            int t, n = 1;
            while (iss >> t && t == v)
                ++n;
                
            oss << n << " " << v << (iss ? " " : "");
            v = t;
        }
    }
    
    cout << oss.str() << endl;
}