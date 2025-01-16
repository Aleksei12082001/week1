#include "median.hpp"
#include <algorithm>

double findMedian(std::vector<int>& numbers) {
    std::sort(numbers.begin(), numbers.end()); 
    size_t size = numbers.size();
    if (size % 2 == 0) {
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        return numbers[size / 2];
    }
}

