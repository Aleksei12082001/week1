#include <cassert>
#include "Stack.hpp"
using namespace std; // Применение пространства имен std

void testStack() {
    LinkedListStack<int> stack;

    assert(stack.isEmpty());
    stack.push(1);
    assert(!stack.isEmpty());
    assert(stack.top() == 1);
    stack.push(2);
    assert(stack.top() == 2);
    assert(stack.size() == 2);
    stack.pop();
    assert(stack.top() == 1);
    assert(stack.size() == 1);
    stack.pop();
    assert(stack.isEmpty());
}

int main() {
    testStack();
    return 0;
}






