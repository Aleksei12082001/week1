#include <iostream>
#include <list>
#include "perms.hpp"

using namespace std;

int main() {
    int size;
    cout << "Введите количество элементов: ";
    cin >> size;

    list<int> input;
    cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        input.push_back(value);
    }

    list<list<int>> output = perms(input);

    cout << "Уникальные перестановки:\n";
    for (const auto& perm : output) {
        cout << "[";
        for (auto it = perm.begin(); it != perm.end(); ++it) {
            cout << *it;
            if (next(it) != perm.end()) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}



