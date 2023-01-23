#include <iostream>

using namespace std;

int main()
{
    int SIZE; cin >> SIZE; cin.ignore();
    
    for (int i = 0; i < SIZE; ++i)
        cout << string(i == 0, '.')
              + string(2 * (SIZE - 1) - i + (i > 0), ' ')
              + string(2 * i + 1, '*') << endl;
        
    for (int i = 0; i < SIZE; ++i)
        cout << string(SIZE - 1 - i, ' ')
	      + string(2 * i + 1, '*')
              + string(2 * (SIZE - i) - 1, ' ')
              + string(2 * i + 1, '*') << endl;
}