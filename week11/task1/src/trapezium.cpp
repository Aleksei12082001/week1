#include "../include/trapezium.hpp"
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

Trapezoid::Trapezoid(double a, double b, int n)
    : a(a), b(b), n(n) {}

double Trapezoid::calculateArea(function<double(double)> f) {
    double area = 0.0;
    double deltaX = (b - a) / n; 

    vector<thread> threads;
    vector<double> results(n);

    auto computeArea = [&](int start, int end, int index) {
        double localArea = 0.0;
        for (int i = start; i < end; ++i) {
            double x1 = a + i * deltaX; 
            double x2 = a + (i + 1) * deltaX; 
            localArea += (f(x1) + f(x2)) * deltaX / 2; 
        }
        results[index] = localArea; 
    };

    int numThreads = thread::hardware_concurrency(); 
    int chunkSize = n / numThreads; 
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? n : start + chunkSize; 
        threads.emplace_back(computeArea, start, end, i); 
    }

    for (auto& thread : threads) {
        thread.join(); 
    }

    for (const auto& result : results) {
        area += result; 
    }

    return area;
}








