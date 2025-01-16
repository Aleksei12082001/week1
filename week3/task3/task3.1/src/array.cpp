#include <iostream>
#include "array.hpp"

using namespace std;

std::pair<double, int> getNumbers(std::vector<double>& data_array, int SIZE) {
    int n;
    cout << "Введите количество чисел (максимум " << SIZE << "): ";
    cin >> n;

    if (n > SIZE || n <= 0) {
        throw invalid_argument("Некорректное количество чисел."); 
    }

    double max_value = -1e9; 
    int count = 0; 

    cout << "Введите числа: ";
    for (int i = 0; i < n; i++) {
        cin >> data_array[i];

        if (data_array[i] > max_value) {
            max_value = data_array[i];
            count = 1; 
        } else if (data_array[i] == max_value) {
            count++; 
        }
    }

    return {max_value, count}; 
}


