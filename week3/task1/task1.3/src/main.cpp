#include <iostream>
#include "badminton.hpp"

using namespace std;

int main() {
    string temperature, precipitation, wind, humidity;

    cout << "Введите температуру (жарко/тепло/холодно): ";
    cin >> temperature;
    cout << "Введите осадки (ясно/облачно/дождь/снег/град): ";
    cin >> precipitation;
    cout << "Есть ли ветер (да/нет): ";
    cin >> wind;
    cout << "Введите влажность (высокая/низкая): ";
    cin >> humidity;

    Badminton game(temperature, precipitation, wind, humidity);

    cout << game.getWeatherCondition() << endl; 

    if (game.canPlay()) {
        cout << "Да, хотите играть в бадминтон!" << endl;
    } else {
        cout << "Нет, не хотите играть в бадминтон." << endl;
    }

    return 0;
}

