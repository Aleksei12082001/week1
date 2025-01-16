#include "fibonacci.hpp"

std::unordered_map<int, long long> cache;

long long classicFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return classicFibonacci(n - 1) + classicFibonacci(n - 2);
}

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (cache.count(n)) {
        return cache[n];
    }

    cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return cache[n];
}






