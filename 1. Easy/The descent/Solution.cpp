#include <iostream>

using namespace std;

int main()
{
    int height, index; 
    
    while (true)
    {
        int maxHeight = 0;
        
        for (int i = 0; i < 8; i++)
        {
            cin >> height; cin.ignore();
            
            if (height > maxHeight)
            {
                maxHeight = height;
                index = i;
            }
        }
        
        cout << index << endl;
    }
}