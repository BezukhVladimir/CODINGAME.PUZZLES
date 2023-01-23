#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int WIDTH, HEIGHT;
vector<string> grid;

struct Position {        
    int x, y;
    
    Position& operator=(const Position& right)
    {
        if (this == &right)
            return *this;
     
        x = right.x;
        y = right.y;
     
        return *this;
    }
    
    Position& operator+=(const Position& right)
    {
        x = x + right.x;
        y = y + right.y;
        
        return *this;
    }
    
    Position(int x, int y): x(x), y(y) {}
};

bool isGrid(const Position& current) {
    return (current.x >= 0) && (current.x < WIDTH)
	&& (current.y >= 0) && (current.y < HEIGHT);
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

const Position EAST(1, 0);
const Position WEST(-1, 0);
const Position SOUTH(0, 1);
const Position NORTH(0, -1);

void input() {
    cin >> WIDTH >> HEIGHT; cin.ignore();
    
    grid.resize(HEIGHT);
    for (auto& row: grid)
        getline(cin, row);
}

bool isEmptySquare(const char& currentSquare) {
    return (currentSquare != '#' && currentSquare != '@');
}

char analysisOfAdjacentPassages(const Area& current) {
    int count = 0;
    
    Area temp = current;
    temp += Area('@', EAST);   
    if (isEmptySquare(temp.square))
        count++;
        
    temp = current;
    temp += Area('@', WEST);
    if (isEmptySquare(temp.square))
        count++;
        
    temp = current;
    temp += Area('@', SOUTH);
    if (isEmptySquare(temp.square))
        count++;
        
    temp = current;
    temp += Area('@', NORTH);
    if (isEmptySquare(temp.square))
        count++;
        
    return count + '0';
}    
    
void updateOfAdjacentPassages(vector<string>& grid) {
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x) {
            Area current(grid[y][x], Position(x, y));
            
            if (isEmptySquare(current.square))
                grid[y][x] = analysisOfAdjacentPassages(current);
        }
}

void output() {
    for (const auto& row: grid)
        cout << row << endl;
}
    
int main() {
    input();
    updateOfAdjacentPassages(grid);
    output();
}