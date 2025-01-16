#include <iostream>
#include "age.hpp"

using namespace std;

int main() {
    int age;

    cout << "Введите ваш возраст: ";
    cin >> age;

    if (age < 0) {
        cout << "Возраст не может быть отрицательным." << endl;
        return 1;
    }

    cout << "Ваш возраст: " << getAgeString(age) << endl;  

    return 0;
}

