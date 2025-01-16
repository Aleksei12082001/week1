#include <iostream>
#include <vector>
#include "mergesort.hpp"

using namespace std;

void merge(vector<double>& data_array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> leftArray(n1);
    vector<double> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = data_array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = data_array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            data_array[k] = leftArray[i];
            i++;
        } else {
            data_array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data_array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        data_array[k] = rightArray[j];
        j++;
        k++;
    }
}

std::vector<double> mergeSort(const std::vector<double>& input_array) {
    vector<double> data_array = input_array; 
    int size = data_array.size();

    if (size <= 1) {
        return data_array; 
    }

    int left = 0;
    int right = size - 1;

    if (left < right) {
        int mid = left + (right - left) / 2;

        vector<double> left_half(data_array.begin() + left, data_array.begin() + mid + 1);
        vector<double> right_half(data_array.begin() + mid + 1, data_array.begin() + right + 1);

        left_half = mergeSort(left_half);
        right_half = mergeSort(right_half);

       
        merge(data_array, left, mid, right);
    }

    return data_array; 
}

