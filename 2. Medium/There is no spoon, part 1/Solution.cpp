#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Position
{        
    int x, y;
    
    Position & operator=(const Position &RIGHT)
    {
        if (this == &RIGHT)
            return *this;
     
        x = RIGHT.x;
        y = RIGHT.y;
     
        return *this;
    }
    
    Position & operator+=(const Position &RIGHT)
    {
        x = x + RIGHT.x;
        y = y + RIGHT.y;
        
        return *this;
    }
    
    friend ostream& operator<<(ostream &out, const Position &RIGHT)
    {
        return out << RIGHT.x << " " << RIGHT.y << " ";
    }
    
    Position(int x, int y): x(x), y(y) {}
};

unsigned WIDTH, HEIGHT;
vector<string> GRID;

const Position EAST(1, 0);
const Position SOUTH(0, 1);
const Position ALONE(-1, -1);

void input()
{
    cin >> WIDTH >> HEIGHT; cin.ignore();
    
    GRID.resize(HEIGHT);
    for (auto &row: GRID)
        getline(cin, row);
}

bool isGrid(const Position &CURRENT)
{
    return (CURRENT.x >= 0) && (CURRENT.x < WIDTH) && (CURRENT.y >= 0) && (CURRENT.y < HEIGHT);
}

bool isNode(const Position &CURRENT)
{
    return (GRID[CURRENT.y][CURRENT.x] == '0');
}

Position directionalAnalysis(Position &current, const Position &DIRECTION)
{   
    current += DIRECTION;

    if (!isGrid(current))
	return ALONE;
    
    if (isNode(current))
	return current;
    
    return directionalAnalysis(current, DIRECTION);    
}

void out(Position &node)
{
    Position temp = node;
    
    cout << temp << directionalAnalysis(temp, EAST) 
                 << directionalAnalysis(node, SOUTH) << endl;
}

void work()
{
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
        {
            Position current(j, i);

            if (isNode(current))
                out(current);
        }
}

int main()
{
    input();
    work();
}