#include <iostream>
#include "../include/trapezium.hpp"
#include <cmath>

using namespace std;

double myFunction(double x) {
    return x * x; 
}

int main() {
    double a, b;
    int n;

    cout << "Введите нижнее основание (a): ";
    cin >> a;
    cout << "Введите верхнее основание (b): ";
    cin >> b;

   
    if (a >= b) {
        cout << "Ошибка: Нижнее основание должно быть меньше верхнего!" << endl;
        return 1; 
    }

    cout << "Введите количество подынтервалов (n): ";
    cin >> n;

   
    if (n <= 0) {
        cout << "Ошибка: Количество подынтервалов должно быть больше 0!" << endl;
        return 1; 
    }

    Trapezoid trapezoid(a, b, n);
    
    double area = trapezoid.calculateArea(myFunction);

    cout << "Площадь криволинейной трапеции: " << area << endl;

    return 0;
}







