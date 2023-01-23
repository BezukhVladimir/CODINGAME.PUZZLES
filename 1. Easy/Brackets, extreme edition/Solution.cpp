#include <stack>
#include <string>
#include <iostream>

using namespace std;

string TEXT;
stack<char> brackets;

void input()
{
    cin >> TEXT; cin.ignore();
}

string result()
{
    for (const char &SYMBOL: TEXT)
    {
        switch (SYMBOL)
        {
        case '(': brackets.push(')'); break;
        case '[': brackets.push(']'); break;
        case '{': brackets.push('}'); break;
        case ')': case ']': case '}':
            if (brackets.empty() || brackets.top() != SYMBOL)
                return "false";
            brackets.pop();
            break;
        }
    }
    
    return brackets.empty() ? "true" : "false";
}

int main()
{
    input();
    cout << result();
}