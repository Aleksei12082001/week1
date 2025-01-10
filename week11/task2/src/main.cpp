#include <iostream>
#include "../include/entropy.hpp"

using namespace std;

int main() {
    string input;

    cout << "Введите текст для расчета энтропии: ";
    getline(cin, input); 

    EntropyCalculator calculator(input);
    double entropy = calculator.calculateEntropy();

    if (entropy >= 0) {
        cout << "Энтропия введенного текста: " << entropy << endl;
    }

    return 0;
}







