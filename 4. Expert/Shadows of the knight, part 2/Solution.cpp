#include <iostream>

using namespace std;

struct Area 
{
    int bottom, top;
	
    Area& operator=(const Area& right)
    {
	if (this == &right)
            return *this;
		
	top = right.top;
	bottom = right.bottom;
	
	return *this;
    }
		
    Area(int bottom, int top): bottom(bottom), top(top) {}
};

int WIDTH, HEIGHT;
int NUMBER_OF_JUMPS;
int x, y, lastX, lastY;
string hint = "UNKNOWN";
Area warm(0, 0), cold(0, 0), current(0, 0);
bool foundX = false, firstJump = true, outside = false;
	
void initialization()
{
    cin >> WIDTH >> HEIGHT >> NUMBER_OF_JUMPS >> x >> y; cin.ignore();
    warm = Area(0, WIDTH - 1);
    cold = Area(0, WIDTH - 1);
    current = Area(0, WIDTH - 1);
}

void input()
{	
    cin >> hint; cin.ignore();
}

bool found()
{
    int tempX = x, tempY = y;
	
    if (foundX)
	y = (current.bottom + current.top) / 2;
    else {
	x = (current.bottom + current.top) / 2;
	current = Area(0, HEIGHT - 1);
	warm = current;
	cold = current;
	foundX = true;
    }
	
    firstJump = true;
	
    return (x == tempX && y == tempY);
}		

int get(int value, int limit)
{
    int tempTop = current.top;
    int tempBottom = current.bottom;
    int give = tempTop + tempBottom - value;
	
    if (outside)
    {
	if (value == 0)
	    give /= 2;
	else if (value == limit)
	    give = (give + limit) / 2;
    }
	
    outside = false;
	
    if (give == value)
	give = value + 1;
    if (give < 0)
    {
	give = 0;
	outside = true;
    }
    else if (give > limit)
    {
	give = limit;
	outside = true;
    }
    
    int below = (give + value - 1) / 2;
    int above = (give + value + 1) / 2;
	
    if (give > value)
    {
	warm = Area(above, tempTop);
	cold = Area(tempBottom, below);
    }
    else if (give < value)
    {
	warm = Area(tempBottom, below);
	cold = Area(above, tempTop);
    }
	
    return give;
}

void jump()
{
    int tempX = x, tempY = y;
	
    if (hint == "SAME" && !firstJump && !found())
	return;
    else if (hint == "WARMER")
        current = warm;
    else if (hint == "COLDER")
	current = cold;
	
    if (current.bottom >= current.top && !found())
	return;
	
    if (foundX)
	y = get(y, HEIGHT - 1);
    else
	x = get(x, WIDTH - 1);
    
    firstJump = false;
    lastX = tempX;
    lastY = tempY;
}

void output()
{
    cout << x << " " << y << endl;
}
		
int main()
{
    initialization();
    while (true)
    {
	input();
	jump();
	output();
    }
}