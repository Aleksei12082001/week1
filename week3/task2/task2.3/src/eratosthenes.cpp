#include "eratosthenes.hpp"
#include <vector>

std::vector<int> sieveOfEratosthenes(int limit) {
    std::vector<bool> isPrime(limit + 1, true);
    std::vector<int> primes;

    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false; 
            }
        }
    }

    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i); 
        }
    }

    return primes;
}

