#include <string>
#include <iostream>

using namespace std;

int main()
{
    int number, digit;
    cin >> number; cin.ignore();

    string result = "";
    bool negative = false;
    
    if (number < 0)
    {
        negative = true;
        number = abs(number);
    }
    
    bool T = false;
    
    if (number != 0)
    {
        do
        {
            digit = number % 3;
            
            if (T)
                digit += 1;
            
            if (digit == 2) {
                T = true;
                result += "T";
            } else if (digit > 2) {
                T = true;
                result += "0";
            } else if (!((digit == 0) && (number == 0))) {
                T = false; 
                result += to_string(digit);
            }
            
            if (number == 0)
                number = -1;
            else
                number = number / 3 | 0;
        }
        while (number >= 0);
        
        if (negative)
        {
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == 'T')
                    result[i] = '1';
                else if (result[i] == '1')
                    result[i] = 'T';
            }
        }
        
        for (int i = result.length() - 1; i >= 0; i--) 
            cout << result[i];
    }
    else
        cout << "0";
}