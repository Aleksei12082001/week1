#include "calculator.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

// Функция для проверки, является ли строка пустой или состоит только из пробелов
bool isEmptyOrWhitespace(const string& str) {
    return str.empty() || all_of(str.begin(), str.end(), ::isspace);
}

// Функция для расчета температур
void calculateTemperatures(const string& input, SensorData sensors[], int& sensorCount, bool& hasErrors) {
    hasErrors = false; // Сброс флага ошибок

    try {
        if (isEmptyOrWhitespace(input)) {
            throw EmptyInputException();
        }

        if (input.length() > 256) {
            throw LengthExceededException();
        }

        stringstream ss(input);
        string token;

        while (getline(ss, token, '@')) {
            if (token.length() < 4) {
                cerr << "Ошибка: Неверный формат данных." << endl;
                hasErrors = true;
                continue;
            }

            int id = stoi(token.substr(0, 2));
            double temperature = stod(token.substr(2)); // Используем stod для работы с числами с плавающей запятой

            if (temperature > 50 || temperature < -50) {
                cerr << "Ошибка: Значение температуры " << temperature << " вышло за пределы диапазона." << endl;
                hasErrors = true;
                continue;
            }

            // Ищем, есть ли уже датчик с таким id
            bool found = false;
            for (int i = 0; i < sensorCount; ++i) {
                if (sensors[i].id == id) {
                    sensors[i].temperature = temperature; // Сохраняем последнее значение температуры
                    found = true;
                    break;
                }
            }

            // Если датчик не найден, добавляем новый
            if (!found) {
                sensors[sensorCount].id = id;
                sensors[sensorCount].temperature = temperature;
                sensorCount++;
            }
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        hasErrors = true;
    }
}

// Функция для сортировки датчиков
void sortSensors(SensorData sensors[], int sensorCount, bool sortById) {
    if (sortById) {
        sort(sensors, sensors + sensorCount, [](const SensorData& a, const SensorData& b) {
            return a.id < b.id;
        });
    } else {
        sort(sensors, sensors + sensorCount, [](const SensorData& a, const SensorData& b) {
            return a.temperature < b.temperature;
        });
    }
}



