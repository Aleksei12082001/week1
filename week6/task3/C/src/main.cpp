#include <iostream>
#include "symbol.hpp"

using namespace std;

int main() {
    string test;
    cout << "Введите строку со скобками: ";
    cin >> test;

    if (isValid(test)) {
        cout << "Строка валидна." << endl;
    } else {
        cout << "Строка не валидна." << endl;
    }

    return 0;
}


