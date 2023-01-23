#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int NUMBER, temperature;
    cin >> NUMBER;

    int closestToZero = (NUMBER > 0) ? 5526 : 0;
    
    for (int i = 0; i < NUMBER; ++i)
    {
        cin >> temperature;
        
        if (abs(temperature) < abs(closestToZero))
            closestToZero = temperature;
        else if (temperature == -closestToZero)
            closestToZero = abs(temperature);
    }
    
    cout << closestToZero << endl;
}