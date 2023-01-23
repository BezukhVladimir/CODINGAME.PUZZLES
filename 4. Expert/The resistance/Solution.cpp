#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, string> alphabet{{'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
			   {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
                           {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
                           {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
                           {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
                           {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
                           {'Y', "-.--"}, {'Z', "--.."}};
map<string, int> dic;

int main() {
    string L;
    int N, longest{0};
    cin >> L >> N;

    for(int i{0}; i != N; ++i) {
        string W, morse_W;
        cin >> W;

        for(const char& c : W)
            morse_W += alphabet[c];

        ++dic[morse_W];
	longest = max(longest, static_cast<int>(morse_W.length()));
    }

    long *multiplicities{new long[L.length() + 1]};
    multiplicities[0] = 1;
    for(int i{1}; i <= L.length(); ++i)
    {
	multiplicities[i] = 0;
	for(int j{min(i, longest)}; j > 0; --j)
        {
	    string candidate{L.substr(L.length() - i, j)};
	    if(dic.find(candidate) != dic.end())
		multiplicities[i] += dic[candidate] * multiplicities[i - j];
	}
    }
	
    cout << multiplicities[L.length()] << endl;
}