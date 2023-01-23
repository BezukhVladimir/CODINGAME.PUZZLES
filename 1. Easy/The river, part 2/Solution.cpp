#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int RIVER;

void input() {
    cin >> RIVER; cin.ignore();
}
    
int change(int river) {
    for (const char& number: to_string(river))
        river += number - '0';
    
    return river;
}

string result() {
    for (int i = max(0.0, RIVER - 9 * (log10(RIVER) + 1)); i < RIVER; i++)          
        if (change(i) == RIVER)
            return "YES";
    
    return "NO";
}

int main() {
    input();
    cout << result();
}