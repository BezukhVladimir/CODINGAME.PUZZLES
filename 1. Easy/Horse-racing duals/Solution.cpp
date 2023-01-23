#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int NUMBER, result = 10000000;
    cin >> NUMBER; cin.ignore();
    
    int horses[NUMBER];    
    for (int i = 0; i < NUMBER; i++)
    {
        cin >> horses[i]; cin.ignore();
    }
    
    sort(horses, horses + NUMBER);
    
    for (int i = 1; i < NUMBER; i++)
        result = min(result, horses[i] - horses[i - 1]);
    
    cout << result;    
}