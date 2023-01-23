#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Tribute
{
    string name = ""; 
    vector<string> killed;
    string killer = "Winner";

    Tribute(const string& n) {
        name = n;    
    }

    friend ostream& operator<<(ostream& output, const Tribute& tribute) {
        output << "Name: " << tribute.name;
        output << "\nKilled: ";
        
	if (tribute.killed.empty())
            output << "None";
        else {
            for (auto it = tribute.killed.begin(); it != tribute.killed.end(); ++it) {
                output << *it;

                if (next(it) != tribute.killed.end())
                    output << ", ";
            }
        }
        
	output << "\nKiller: " << tribute.killer << '\n';

        return output;
    }
};

int main() {
    size_t N; cin >> N; cin.ignore();

    vector<Tribute> tributes; 
    for (size_t i = 0; i != N; ++i) {
        string playerName;
        getline(cin, playerName);
        tributes.emplace_back(Tribute(playerName));
    }

    size_t turns; cin >> turns; cin.ignore();
    for (size_t i = 0; i != turns; ++i) {
        string killer, killed;

        cin >> killer;

        auto it_killer
		= find_if(tributes.begin(), tributes.end(),
		  [killer](Tribute tribute) { return tribute.name == killer; });

        cin >> killed;
        while (true) {
            cin >> killed;
            if (killed.back() == ',') 
            {
                killed.pop_back();
                (*it_killer).killed.emplace_back(killed);

                auto it_killed
			= find_if(tributes.begin(), tributes.end(),
			  [killed](Tribute tribute) { return tribute.name == killed; });
                
		(*it_killed).killer = killer;
            } else {
                (*it_killer).killed.emplace_back(killed);

                auto it_killed
			= find_if(tributes.begin(), tributes.end(),
			  [killed](Tribute tribute) { return tribute.name == killed; });
                (*it_killed).killer = killer;

                break;
            }
        }
    }

    sort(tributes.begin(), tributes.end(),
	[](const Tribute& t1, const Tribute& t2) -> bool { return t1.name < t2.name; });

    for (auto& t: tributes)
        sort(t.killed.begin(), t.killed.end());

    for (auto it = tributes.begin(); it != tributes.end(); ++it)
    {
        cout << *it;

        if (next(it) != tributes.end())
            cout  << '\n';
    }
}