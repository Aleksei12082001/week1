#include <iostream>
#include <chrono>
#include <iomanip>
#include "fibonacci.hpp"

using namespace std;
using namespace std::chrono;

void compareFibonacciTime(int n) {
    auto start = high_resolution_clock::now();
    long long classicResult = classicFibonacci(n);
    auto end = high_resolution_clock::now();
    double classicTime = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    long long optimizedResult = fibonacci(n);
    end = high_resolution_clock::now();
    double optimizedTime = duration<double>(end - start).count(); 

    cout << "Число Фибоначчи " << n << " равно " << classicResult << " (классическая) и " << optimizedResult << " (оптимизированная)" << endl;
    cout << "Время вычисления: " << endl;
    
    
    cout << fixed << setprecision(6); 
    cout << "Классическая реализация: " << classicTime << " секунд" << endl;
    cout << "Оптимизированная реализация: " << optimizedTime << " секунд" << endl;
}

int main() {
    int n;
    cout << "Введите число Фибоначчи: ";
    cin >> n;
    compareFibonacciTime(n);
    return 0;
}








