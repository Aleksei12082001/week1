#include "Stack.hpp"
#include <stdexcept> // Для исключений
using namespace std; // Применение пространства имен std

template <typename T>
LinkedListStack<T>::LinkedListStack() : head(nullptr), count(0) {}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void LinkedListStack<T>::push(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    count++;
}

template <typename T>
T LinkedListStack<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    Node* temp = head;
    T value = head->data;
    head = head->next;
    delete temp;
    count--;
    return value;
}

template <typename T>
T LinkedListStack<T>::top() const {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    return head->data;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
size_t LinkedListStack<T>::size() const {
    return count;
}

// Явная инстанциация для типа int
template class LinkedListStack<int>;










