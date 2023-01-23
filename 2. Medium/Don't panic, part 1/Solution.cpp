#include <map>
#include <string>
#include <iostream>

using namespace std;

map<int, int> ELEVATORS_AND_EXIT;
const string LEFT = "LEFT"; const string RIGHT = "RIGHT"; const string WAIT = "WAIT"; const string BLOCK = "BLOCK";
int NUMBER_OF_FLOORS, WIDTH, NUMBER_OF_ROUNDS, EXIT_FLOOR, EXIT_POSITION,
    TOTAL_NUMBER_OF_CLONES, NUMBER_OF_ADDITIONAL_ELEVATORS, NUMBER_OF_ELEVATORS;
    
void initialization()
{
    cin >> NUMBER_OF_FLOORS >> WIDTH >> NUMBER_OF_ROUNDS >> EXIT_FLOOR >> EXIT_POSITION
	>> TOTAL_NUMBER_OF_CLONES >> NUMBER_OF_ADDITIONAL_ELEVATORS >> NUMBER_OF_ELEVATORS;
    
    for (int i = 0; i < NUMBER_OF_ELEVATORS; i++)
    {
        int elevatorFloor, elevatorPosition;
        cin >> elevatorFloor >> elevatorPosition; cin.ignore();
        ELEVATORS_AND_EXIT[elevatorFloor] = elevatorPosition;
    }
    
    ELEVATORS_AND_EXIT[EXIT_FLOOR] = EXIT_POSITION;
}

void game()
{
    while (true)
    {
        string direction;
        int cloneFloor, clonePosition;
        
        cin >> cloneFloor >> clonePosition >> direction; cin.ignore();
        
        if ((direction == LEFT) && (clonePosition >= ELEVATORS_AND_EXIT[cloneFloor])
	    || (direction == RIGHT) && (clonePosition <= ELEVATORS_AND_EXIT[cloneFloor]))
            cout << WAIT << endl;
        else
            cout << BLOCK << endl;
    }
}

int main()
{
    initialization();
    game();
}