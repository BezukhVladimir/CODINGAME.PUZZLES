#include <map>
#include <iostream>

std::map<std::string, int> resistors;

double parse(bool series)
{
    std::string token; double result = 0, value;
    while (std::cin >> token)
    {
        if (token == ")") return result;
        if (token == "]") return 1.0 / result;

        if (token == "(")      value = parse(true);
        else if (token == "[") value = parse(false);
        else                   value = resistors[token];

        if (series) result += value;
        else        result += 1.0 / value;
    }

    return result;
}

int main()
{
    std::string name; int N; std::cin >> N; 
    for (int i = 0; i != N; ++i) 
        std::cin >> name >> resistors[name];

    printf("%.1f", parse(true));
}