#include <string>
#include <iostream>

using namespace std;

int main()
{
    int LIGHT_X, LIGHT_Y, x, y; 
    cin >> LIGHT_X >> LIGHT_Y >> x >> y; cin.ignore();

    while (true)
    { 
        string step;
        
        if (y != LIGHT_Y) step += (y > LIGHT_Y) ? 'N' : 'S';
        if (x != LIGHT_X) step += (x > LIGHT_X) ? 'W' : 'E';
                
        if (step.find('N') != string::npos) y--;
        else if (step.find('S') != string::npos) y++;
        
        if (step.find('W') != string::npos) x--;
        else if (step.find('E') != string::npos) x++;
        
        cout << step << endl;
    }
}