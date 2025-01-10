#include <iostream>
#include "Stack.hpp"
using namespace std; /

int main() {
    LinkedListStack<int> stack;

    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.top() << endl; 
    cout << "Stack size: " << stack.size() << endl; 

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; 

    return 0;
}








