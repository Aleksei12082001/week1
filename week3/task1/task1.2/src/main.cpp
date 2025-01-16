#include <iostream>
#include "dayscalculator.hpp"

using namespace std;

int main() {
    int month, year;

    cout << "Введите номер месяца (1-12): ";
    cin >> month;
    cout << "Введите год: ";
    cin >> year;

    try {
        int days = getDaysInMonth(month, year);
        cout << "Количество дней в " << month << " месяце " << year << " года: " << days << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}

