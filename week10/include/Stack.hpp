#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>   // Для size_t
#include <stdexcept> // Для исключений

template <typename T>
class Stack {
public:
    virtual ~Stack() = default;
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
};

template <typename T>
class LinkedListStack : public Stack<T> {
public:
    LinkedListStack();
    ~LinkedListStack() override;

    void push(const T& value) override;
    T pop() override;
    T top() const override;
    bool isEmpty() const override;
    size_t size() const override;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    size_t count;
};

#endif // STACK_HPP





