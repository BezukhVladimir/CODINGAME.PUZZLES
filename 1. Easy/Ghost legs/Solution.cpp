#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int WIDTH, HEIGHT;
    cin >> WIDTH >> HEIGHT; cin.ignore();
    
    string ORIGINAL_TOP, top;
    getline(cin, ORIGINAL_TOP);
    top = ORIGINAL_TOP;
    
    for (int i = 0; i < HEIGHT - 2; i++)
    {
        string line;
        getline(cin, line);
        
        for (int j = 0; j < WIDTH - 3; j += 3)
        {
            if (line[j + 1] == '-')
                swap(top[j], top[j + 3]);
        }
    }
    
    string ORIGINAL_BOTTOM;
    getline(cin, ORIGINAL_BOTTOM);
        
    map<char, char> result; 
    
    for (int i = 0; i < (WIDTH + 2) / 3; i++)
        result[top[i * 3]] = ORIGINAL_BOTTOM[i * 3];
        
    for (int i = 0; i < (WIDTH + 2) / 3; i++)    
        cout << ORIGINAL_TOP[i * 3] << result[ORIGINAL_TOP[i * 3]] << endl;
}