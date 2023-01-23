#include <string>
#include <iostream>

using namespace std;

int main()
{
    int xEnd, yEnd, NUMBER_OF_JUMPS, x, y, x0 = 0, y0 = 0;
    cin >> xEnd >> yEnd >> NUMBER_OF_JUMPS >> x >> y; cin.ignore();

    while (true)
    {
        string message; cin >> message; cin.ignore();
        
        for (const char& symbol: message)
        {
            switch (symbol)
            {
                case 'R': x0 = x; break;
                case 'D': y0 = y; break;
                case 'L': xEnd = x; break;
                case 'U': yEnd = y; break;               
            }
        }
        
        x = (x0 + xEnd) >> 1;
        y = (y0 + yEnd) >> 1;
        cout << x << " " << y << endl;
    }
}