#include <iostream>

template <typename T>
class Stack {
size_t size;
int top = -1;
T* data;

public:

    Stack(size_t size) {
        this->size = size;
        data = new T[this->size];
    }

    Stack() : Stack(20) {}

    Stack(const Stack& s) {
        size = s.size;
        top = s.top;
        data = new T[size];
        for (size_t i = 0; i <= s.top; i++) {
            data[i] = s.data[i];
        }
    }

    ~Stack() {
        delete data;
    }

    void push(T value) {
        if (Stack.size > Stack.top) {
            ++top;
            data[top] = value;
        } else {}
    }

    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == size;
    }
    
    void peek() {
        if (!isEmpty)
            std::cout << data[top];
    }

    void pop() {
        if (top > 0) {
            delete data[top];
            --top;
        }
    }

};