#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char WALL, DIRECTION;
int WIDTH, HEIGHT;
vector<string> grid;

struct Position {        
    int x, y;
    
    Position& operator=(const Position& right) {
        if (this == &right)
            return *this;
     
        x = right.x;
        y = right.y;
     
        return *this;
    }
    
    Position& operator+=(const Position& right) {
        x = x + right.x;
        y = y + right.y;
        
        return *this;
    }
    
    Position(int x, int y): x(x), y(y) {}
};

bool isGrid(const Position& current) {
    return (current.x >= 0) && (current.x < WIDTH) && (current.y >= 0) && (current.y < HEIGHT);
}

bool isPikaptcha(const char& currentSquare) {
    return (currentSquare == '>' ||
                currentSquare == '<' ||
                    currentSquare == '^' ||
                        currentSquare == 'v');
}

struct Area {
    char square;
    Position position;
    
    Area& operator=(const Area& right)
    {
        if (this == &right)
            return *this;
            
        square = right.square;
        position = right.position;
        
        return *this;
    }
    
    Area& operator+=(const Area& right)
    {
        position += right.position;
        
        if (isGrid(position))
            square = grid[position.y][position.x];
        else
            square = '@';
        
        return *this;
    }
    
    Area(char square, Position position): square(square), position(position) {}
};

Area START('@', Position(0, 0)), END('@', Position(0, 0));

const Position EAST(1, 0);
const Position WEST(-1, 0);
const Position SOUTH(0, 1);
const Position NORTH(0, -1);

void input() {
    cin >> WIDTH >> HEIGHT; cin.ignore();
    
    grid.resize(HEIGHT);
    for (auto& row: grid)
        getline(cin, row);
        
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {   
            if (isPikaptcha(grid[y][x]))
            {
                DIRECTION = grid[y][x];
                grid[y][x] = '0';
                START = Area(DIRECTION, Position(x, y));
                END = START;
            }
            
            cerr << grid[y][x];
        }
        
        cerr << endl;
    }
    
    cerr << DIRECTION << " " << START.square << " " << START.position.x << " " << START.position.y;
        
    cin >> WALL;
}

bool isEmptySquare(const char& currentSquare) {
    return (currentSquare != '#' && currentSquare != '@');
}
 
void updateWayMap()
{
    if (WALL == 'L')
    {
        do
        {
            if (START.square == '>')
            {
                if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
                else if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
                else if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
            }
            else if (START.square == '<')
            {
                if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
                else if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
                else if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
            }
            else if (START.square == '^')
            {
                if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
                else if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
            }        
            else if (START.square == 'v')
            {
                if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
                else if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
            }              
        }
        while ((START.position.x != END.position.x) || (START.position.y != END.position.y));
    }
    else if (WALL == 'R')
    {
        do
        {
            if (START.square == '>')
            {
                if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
                else if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
                else if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
            }
            else if (START.square == '<')
            {
                if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
                else if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
                else if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
            }
            else if (START.square == '^')
            {
                if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
                else if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                } 
                else if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
            }        
            else if (START.square == 'v')
            {
                if (isGrid(Position(START.position.x - 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x - 1]))
                {
                    grid[START.position.y][START.position.x - 1] = (((grid[START.position.y][START.position.x - 1] - '0') + 1) + '0');
                    DIRECTION = '<';
                    START = Area(DIRECTION, Position(START.position.x - 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y + 1)) && isEmptySquare(grid[START.position.y + 1][START.position.x]))
                {
                    grid[START.position.y + 1][START.position.x] = (((grid[START.position.y + 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = 'v';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y + 1));
                }
                else if (isGrid(Position(START.position.x + 1, START.position.y)) && isEmptySquare(grid[START.position.y][START.position.x + 1]))
                {
                    grid[START.position.y][START.position.x + 1] = (((grid[START.position.y][START.position.x + 1] - '0') + 1) + '0');
                    DIRECTION = '>';
                    START = Area(DIRECTION, Position(START.position.x + 1, START.position.y));
                }
                else if (isGrid(Position(START.position.x, START.position.y - 1)) && isEmptySquare(grid[START.position.y - 1][START.position.x]))
                {
                    grid[START.position.y - 1][START.position.x] = (((grid[START.position.y - 1][START.position.x] - '0') + 1) + '0');
                    DIRECTION = '^';
                    START = Area(DIRECTION, Position(START.position.x, START.position.y - 1));
                }
            }              
        }
        while ((START.position.x != END.position.x) || (START.position.y != END.position.y));
    }
}   

void output() {
    for (const auto& row: grid)
        cout << row << endl;
}
    
int main() {
    input();
    updateWayMap();
    output();
}