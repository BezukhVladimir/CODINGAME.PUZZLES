#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Argument {
    int value; // $index or value
    bool isReference;
    
    Argument(int value, bool isReference):
        value(value), isReference(isReference) {}
};

struct Data {
    string command;
    Argument firstArgument;
    Argument secondArgument;
    
    Data(string command, Argument firstArgument, Argument secondArgument):
        command(command), firstArgument(firstArgument), secondArgument(secondArgument) {}
};

int NUMBER;
vector<Data> DATABASE;

bool isReference(const string& argument) {
    return argument[0] == '$';
}

int getIndex(const string& argument) {
    return stoi(argument.substr(1));
}

long int getValue(int& index);

void changeFirstArgumentValue(int& index) {
    DATABASE[index].firstArgument.value = getValue(DATABASE[index].firstArgument.value);
    DATABASE[index].firstArgument.isReference = false;
}

void changeSecondArgumentValue(int& index) {
    DATABASE[index].secondArgument.value = getValue(DATABASE[index].secondArgument.value);
    DATABASE[index].secondArgument.isReference = false;
}

long int getValue(int& index)  {
    if (DATABASE[index].command == "VALUE") {
        if (DATABASE[index].firstArgument.isReference) {
            changeFirstArgumentValue(index);
            return DATABASE[index].firstArgument.value;
        } else {
            return DATABASE[index].firstArgument.value;
        }
    }

    if (DATABASE[index].command == "ADD") {
        if (DATABASE[index].firstArgument.isReference) {
            if (DATABASE[index].secondArgument.isReference) {
                changeFirstArgumentValue(index);
                changeSecondArgumentValue(index);
                return DATABASE[index].firstArgument.value + DATABASE[index].secondArgument.value;
            } else {
                changeFirstArgumentValue(index);
                return DATABASE[index].firstArgument.value + DATABASE[index].secondArgument.value;
            }
        } else {
            if (DATABASE[index].secondArgument.isReference) {
                changeSecondArgumentValue(index);
                return DATABASE[index].firstArgument.value + DATABASE[index].secondArgument.value;
            } else
                return DATABASE[index].firstArgument.value + DATABASE[index].secondArgument.value;
        }
    }

    if (DATABASE[index].command == "SUB") {
        if (DATABASE[index].firstArgument.isReference) {
            if (DATABASE[index].secondArgument.isReference) {
                changeFirstArgumentValue(index);
                changeSecondArgumentValue(index);
                return DATABASE[index].firstArgument.value - DATABASE[index].secondArgument.value;
            } else {
                changeFirstArgumentValue(index);
                return DATABASE[index].firstArgument.value - DATABASE[index].secondArgument.value;
            }
        } else {
            if (DATABASE[index].secondArgument.isReference) {
                changeSecondArgumentValue(index);
                return DATABASE[index].firstArgument.value - DATABASE[index].secondArgument.value;
            } else
                return DATABASE[index].firstArgument.value - DATABASE[index].secondArgument.value;
        }
    }

    if (DATABASE[index].command == "MULT") {
        if (DATABASE[index].firstArgument.isReference) {
            if (DATABASE[index].secondArgument.isReference) {
                changeFirstArgumentValue(index);
                changeSecondArgumentValue(index);
                return DATABASE[index].firstArgument.value * DATABASE[index].secondArgument.value;
            } else {
                changeFirstArgumentValue(index);
                return DATABASE[index].firstArgument.value * DATABASE[index].secondArgument.value;
            }
        } else {
            if (DATABASE[index].secondArgument.isReference) {
                changeSecondArgumentValue(index);
                return DATABASE[index].firstArgument.value * DATABASE[index].secondArgument.value;
            } else
                return DATABASE[index].firstArgument.value * DATABASE[index].secondArgument.value;
        }
    }
}

void input() { // Создание базы данных 
    cin >> NUMBER; cin.ignore();

    for (int i = 0; i < NUMBER; i++) // _ == 10001
    {
        Argument firstArgument = Argument(10001, false);
        Argument secondArgument = Argument(10001, false);
        string command, arg1, arg2;
        cin >> command >> arg1 >> arg2; cin.ignore();

        if (isReference(arg1))
            firstArgument = Argument(getIndex(arg1), true);
        else
            firstArgument = Argument(stoi(arg1), false);

        if (command != "VALUE")
        {
            if(isReference(arg2))
                secondArgument = Argument(getIndex(arg2), true);
            else
                secondArgument = Argument(stoi(arg2), false);
        }
        
        DATABASE.emplace_back(Data(command, firstArgument, secondArgument));
    }
}

void output() {
    for (int i = 0; i < NUMBER; ++i) {
        cout << getValue(i) << endl;
    }
}

int main() {
    input();
    output();
}