#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int WIDTH, HEIGHT, ROTATE;
vector<string> grid;

void input()
{
    cin >> WIDTH >> HEIGHT >> ROTATE; cin.ignore();
    
    grid.resize(HEIGHT);
    for (auto& row: grid)
        getline(cin, row);
}

void sorting()
{
    for (auto& row: grid)
        sort(row.begin(), row.end(), greater<char>());
}    

void out90()
{
    sorting();    
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
            cout << grid[j][i];
            
        cout << endl;
    }
}

void out180()
{
    sorting();
    for (const auto& row: grid)
        cout << row << endl;
} 

int main()
{
    input();
    (ROTATE % 2) ? out90() : out180(); 
}