#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack() = default;
    ~Stack() = default;
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

private:
    std::vector<T> data_;

};


template <typename T>
bool Stack<T>::empty() const {
    return data_.empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return data_.size();
}

template <typename T>
void Stack<T>::push(const T& item) {
    data_.push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    if (data_.empty()) {
        throw std::underflow_error("can't pop an empty stack");
    }
    data_.pop_back();
}

template <typename T>
const T& Stack<T>::top() const {
    if (data_.empty()) {
        throw std::underflow_error("can't call top on an empty stack");
    }
    return data_.back();
}


#endif