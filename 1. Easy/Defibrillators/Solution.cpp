#include <cmath>
#include <string>
#include <cfloat>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Address
{
    int index;
    double longitude, latitude;
    string name, address, number;
    
    Address(int index, string name, string address,
	    string number, double longitude, double latitude):
        index(index), name(name), address(address),
	number(number), longitude(longitude), latitude(latitude) {}
};
    
int NUMBER;
string result;
vector<Address> addresses;
double x, y, mininalDistance = DBL_MAX;
double currentLongitude, currentLatitude;
const double RADIUS_OF_THE_EARTH = 6371.0;

void input()
{
    string temp;
    
    cin >> temp; cin.ignore();
    replace(temp.begin(), temp.end(), ',', '.');
    currentLongitude = stof(temp);
    
    cin >> temp; cin.ignore();
    replace(temp.begin(), temp.end(), ',', '.');
    currentLatitude = stof(temp);
    
    cin >> NUMBER; cin.ignore();
    for (int i = 0; i < NUMBER; i++)
    {
        int index;
        double longitude, latitude;
        string temp, name, address, number;
        
        getline(cin, temp, ';'); index = stoi(temp);
        getline(cin, name, ';');
        getline(cin, address, ';');
        getline(cin, number, ';');
        getline(cin, temp, ';');
	replace(temp.begin(), temp.end(), ',', '.');
	longitude = stof(temp);
        getline(cin, temp);
	replace(temp.begin(), temp.end(), ',', '.');
	latitude = stof(temp);
        
        addresses.emplace_back(Address(index, name, address, number, longitude, latitude));   
    }
}

void work()
{
    for (const auto& address: addresses)
    {
        double temp;
        
        x = (address.longitude - currentLongitude)
	    * cos((address.latitude + currentLatitude) / 2.0);
        y = (address.latitude - currentLatitude);
        temp = sqrt(x * x + y * y) * RADIUS_OF_THE_EARTH;
        
        if (mininalDistance > temp) 
        {
            mininalDistance = temp;
            result = address.name;
        }
    }
    
    cout << result;
}    

int main()
{
    input();
    work();    
}