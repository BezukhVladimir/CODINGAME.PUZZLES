#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

struct Position
{
    int x, y;
    
    Position(int x, int y): x(x), y(y) {}
};   

int number;
double result = 0;
vector<Position> towns;

double squaredDistance(const Position& one, const Position& two) {
    return (one.x - two.x) * (one.x - two.x) + (one.y - two.y) * (one.y - two.y);
}

void input() {
    cin >> number; cin.ignore();
    
    for (int i = 0; i < number; i++)
    {
        int x, y;
        cin >> x >> y; cin.ignore();
        towns.emplace_back(Position(x, y));
    }
}

void simpleGreedyAlgorithm() {
    Position firstTown = towns[0];
    
    while (number - 1) {
        int minimalIndex;
        double minimalDistance = 20000.0f;
        
        for (int i = 1; i < number; i++)
        {
            double distance = squaredDistance(towns[0], towns[i]);
                                  
            if (distance < minimalDistance)
            {
                minimalDistance = distance;
                minimalIndex = i;                
            }
        }
        
        swap(towns[0], towns[minimalIndex]);
        towns.erase(towns.begin() + minimalIndex);
        result += sqrt(minimalDistance);
        number--;
    }
    
    result += sqrt(squaredDistance(towns[0], firstTown));
}
    
int main() {
    input();
    simpleGreedyAlgorithm();    
    cout << round(result);
}