#include "../include/entropy.hpp"
#include <iostream>
#include <thread>
#include <map>
#include <cmath>

using namespace std;

EntropyCalculator::EntropyCalculator(const string& input) : input(input) {}

void EntropyCalculator::calculateFrequency(map<char, int>& frequency) {
    for (char ch : input) {
        frequency[ch]++;
    }
}

double EntropyCalculator::calculateEntropy() {
    map<char, int> frequency;

    
    if (input.empty()) {
        cerr << "Ввод не может быть пустым." << endl;
        return -1;
    }

    
    vector<thread> threads;
    threads.emplace_back(&EntropyCalculator::calculateFrequency, this, ref(frequency));

    for (auto& t : threads) {
        t.join(); 
    }

    double entropy = 0.0;
    double total = 0.0;

   
    for (const auto& pair : frequency) {
        total += pair.second;
    }

    
    for (const auto& pair : frequency) {
        double probability = pair.second / total;
        entropy -= probability * log2(probability);
    }

    return entropy;
}







