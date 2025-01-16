#include <iostream>
#include "age.hpp"

using namespace std;

string getAgeString(int age) {  
    if (age % 10 == 1 && age % 100 != 11) {
        return to_string(age) + " год";
    } else if ((age % 10 >= 2 && age % 10 <= 4) && (age % 100 < 10 || age % 100 >= 20)) {
        return to_string(age) + " года";
    } else {
        return to_string(age) + " лет";
    }
}

