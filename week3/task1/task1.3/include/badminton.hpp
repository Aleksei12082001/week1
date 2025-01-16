#ifndef BADMINTON_HPP
#define BADMINTON_HPP

#include <string>

class Badminton {
public:
    Badminton(const std::string& temperature, const std::string& precipitation,
              const std::string& wind, const std::string& humidity);
    
    bool canPlay() const; 
    std::string getWeatherCondition() const; 

private:
    std::string temperature;
    std::string precipitation;
    std::string wind;
    std::string humidity;
};

#endif 


