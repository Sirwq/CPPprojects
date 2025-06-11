#include <iostream>

template <typename T>
class Stack {
size_t size;
size_t top = -1;
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
        delete[] data; // delete data; WILL NOT DELETE EVERYTHING!!!
    }

    void push(T value) {
        if (size > top) {
            ++top;
            data[top] = value;
        } else {}
    }

    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == static_cast<int>(size) - 1;
    }
    
    void peek() {
        if (!isEmpty())
            std::cout << data[top];
    }

    void pop() {
        if (!isEmpty()) {
            data[top] = nullptr;
            --top;
        }
    }

    T& topElement() {
        return data[top];
    }

};