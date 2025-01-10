#include <iostream>
#include "Stack.hpp"
using namespace std; // Применение пространства имен std

int main() {
    LinkedListStack<int> stack;

    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.top() << endl; // 20
    cout << "Stack size: " << stack.size() << endl; // 2

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // 10

    return 0;
}








