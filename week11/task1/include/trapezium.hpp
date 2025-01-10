#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include <functional>

class Trapezoid {
public:
    Trapezoid(double a, double b, int n);
    double calculateArea(std::function<double(double)> f);

private:
    double a; 
    double b; 
    int n;    
};

#endif 





