#include <string>
#include <iostream>

using namespace std;

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    bool previousBit = MESSAGE[0] & 0x40;

    cout << (previousBit ? "0 " : "00 ");
    
    for (const auto& symbol: MESSAGE)
    {        
        for (unsigned char bitmask = 0x40; bitmask != 0; bitmask >>= 1)
        {
            bool currentBit = (symbol & bitmask);
            cout << ((currentBit == previousBit)
		     ? "0" : (previousBit = currentBit) ? " 0 0" : " 00 0");
        }
    }
}