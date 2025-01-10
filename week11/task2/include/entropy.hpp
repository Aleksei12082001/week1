#ifndef ENTROPY_HPP
#define ENTROPY_HPP

#include <string>
#include <map>
#include <functional>

class EntropyCalculator {
public:
    EntropyCalculator(const std::string& input);
    double calculateEntropy();

private:
    std::string input;
    void calculateFrequency(std::map<char, int>& frequency);
};

#endif // ENTROPY_HPP



