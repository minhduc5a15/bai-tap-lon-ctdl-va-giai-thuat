#ifndef STACK_H
#define STACK_H

#include "node.hpp"

template<class T>
class stack {
private:
    size_t curr_size_ = 0;
    node<T> *head = nullptr;

public:
    stack() {};

    ~stack() {
        clear();
    };

    void clear() {
        head = nullptr;
        curr_size_ = 0;
    }

    bool empty() const {
        return curr_size_ == 0;
    }

    size_t size() const {
        return curr_size_;
    }

    T top() const {
        if (this->empty()) {
            throw std::out_of_range("The stack is empty");
        }
        return head->get_data();
    }

    void push(const T &x) {
        node<T> *new_node = new node<T>(std::move(x), head);
        head = new_node;
        curr_size_++;
    }

    void pop() {
        if (this->empty()) {
            throw std::out_of_range("The stack is empty");
        }
        const node<T> *temp = head;
        head = head->get_next();
        delete temp;
        --curr_size_;
    }
};

#endif
