#include <bits/stdc++.h>

using namespace std;

int main() {
    int              N, val, max_s(0); 
    string           key, test;
    map<string, int> dic;

    cin >> N; cin.ignore();
    while (N-- && cin >> key >> val) 
    {
        dic[key] = val; cin.ignore();
        if (max_s < key.size()) max_s = key.size();
    }
    cin >> test; cin.ignore();

    bool is_ok(true);
    int st_idx(0), cur_idx(-1);
    string cur, res;
    while(is_ok && ++cur_idx < test.length())
    {
        cur += test[cur_idx];
        if (cur.size() > max_s) 
            is_ok = false; 
        else if (dic.find(cur) != dic.end()) 
        { 
            res += (char) dic[cur];
            cur.clear();
            st_idx = cur_idx + 1;
        }
    }
    is_ok = cur.empty();

    cout << (is_ok ? res : ("DECODE FAIL AT INDEX " + to_string(st_idx))) << endl;
}