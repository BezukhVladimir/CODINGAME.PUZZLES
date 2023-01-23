#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N, Q;
map<string, string> mime_types;

int main()
{
    cin >> N >> Q; cin.ignore();
    
    for (int i = 0; i < N; i++)
    {
        string type, extension;
        cin >> type >> extension; cin.ignore();

        transform(type.begin(), type.end(), type.begin(), ::tolower);
        mime_types[type] = extension;
    }
    
    for (int i = 0; i < Q; i++) 
    {
        string file_name;
        getline(cin, file_name);

        transform(file_name.begin(), file_name.end(), file_name.begin(), ::tolower);
        int index = file_name.rfind('.');

        if (index != string::npos)
        {
            string type = file_name.substr(index + 1);
            string extension = mime_types[type];

            if (extension != "")
            {
                cout << extension << endl;
                continue;
            }
        }
        
        cout << "UNKNOWN" << endl;
    }
}