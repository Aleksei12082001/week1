#include <iostream>
#include <vector>
#include "median.hpp"

using namespace std;

int main() {
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество чисел должно быть больше нуля." << endl;
        return 1;
    }

    vector<int> numbers(n);
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    double median = findMedian(numbers);
    cout << "Медиана: " << median << endl;

    return 0;
}

