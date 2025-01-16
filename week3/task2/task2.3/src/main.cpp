#include <iostream>
#include "eratosthenes.hpp"

using namespace std;

int main() {
    int limit;

    cout << "Введите верхнюю границу для поиска простых чисел: ";
    cin >> limit;

    if (limit < 2) {
        cout << "Пожалуйста, введите число больше или равное 2." << endl;
        return 1;
    }

    vector<int> primes = sieveOfEratosthenes(limit);

    cout << "Простые числа до " << limit << ": ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}

