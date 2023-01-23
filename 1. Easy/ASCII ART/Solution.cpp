#include <string>
#include <cctype>
#include <iostream>

using namespace std;

int main()
{
    int WIDTH, HEIGHT, shift;
    string TEXT, line;

    cin >> WIDTH >> HEIGHT;
    getline(cin, TEXT);
   
    for (int i = 0; i < HEIGHT; ++i) {
        getline(cin, line);
        
        for (const char& symbol: TEXT) {
            shift = isalpha(symbol) ? toupper(symbol) - 65 : 26;
            cout << line.substr(WIDTH * shift, WIDTH);
        }
        
        cout << endl;
    }
}