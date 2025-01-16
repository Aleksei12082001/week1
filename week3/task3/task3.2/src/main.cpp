#include <iostream>
#include <vector>
#include "sort.hpp"
#include "mergesort.hpp"

using namespace std;

int main() {
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    vector<double> data_array(size);

    cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) {
        cin >> data_array[i];
    }

    cout << "Исходный массив: ";
    printArray(data_array);

    vector<double> sorted_array = mergeSort(data_array); 

    cout << "Отсортированный массив: ";
    printArray(sorted_array);

    return 0;
}

