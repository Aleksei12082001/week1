#include "badminton.hpp"

using namespace std;

Badminton::Badminton(const string& temp, const string& precip,
                     const string& wind, const string& humidity)
    : temperature(temp), precipitation(precip), wind(wind), humidity(humidity) {}

bool Badminton::canPlay() const {
    return (temperature == "жарко" || temperature == "тепло") &&
           (precipitation == "ясно" || precipitation == "облачно") &&
           (wind == "нет") &&
           (humidity == "низкая");
}

string Badminton::getWeatherCondition() const {
    return "Температура: " + temperature + ", Осадки: " + precipitation +
           ", Ветер: " + wind + ", Влажность: " + humidity;
}

