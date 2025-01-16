#include <iostream>
#include <vector>
#include "array.hpp"

using namespace std;

int main() {
    const int SIZE = 100; 
    vector<double> data_array(SIZE); 
    int count = 0; 
    double max_value;

    try {
        auto result = getNumbers(data_array, SIZE); 
        max_value = result.first; 
        count = result.second; 

        cout << "Количество чисел, равных максимальному (" << max_value << "): " << count << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; 
    }

    return 0;
}


