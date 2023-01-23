#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;    

unsigned SIZE; int LIGHT;
vector<string> GRID;
vector<vector<unsigned>> lightmask;

void initialization()
{
    cin >> SIZE >> LIGHT;
        
    GRID.resize(SIZE), lightmask.resize(SIZE);    
    for (unsigned j = 0; j < SIZE; ++j)
    {
        GRID[j].resize(SIZE), lightmask[j].resize(SIZE);
        
        for (unsigned i = 0; i < SIZE; ++i)
            cin >> GRID[j][i], lightmask[j][i] = 0;
    }
}

void createLight(int &y, int &x)
{
    for (int j = 0; j < SIZE; ++j)
        for (int i = 0; i < SIZE; ++i)
            lightmask[j][i] += max(0, LIGHT - max(abs(x - i), abs(y - j)));
}
     
void findToCandles()
{
    for (int y = 0; y < SIZE; ++y)
        for (int x = 0; x < SIZE; ++x)
            if (GRID[y][x] == 'C')
                createLight(y, x);
}

void output(unsigned &result)
{
    cout << result;
}

void countDarkness()
{
    unsigned counter = 0;
    
    for (unsigned y = 0; y < SIZE; ++y)
        for (unsigned x = 0; x < SIZE; ++x)
            if (lightmask[y][x] == 0)
                counter++;
 
    output(counter);
}   

int main()
{
    initialization();
    findToCandles();
    countDarkness();
}