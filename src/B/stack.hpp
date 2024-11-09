#ifndef STACK_H
#define STACK_H

template<class T>
class node {
private:
    T data;
    node<T> *next;

public:
    explicit node(const T &_data, node<T> *_next = nullptr): data(_data), next(_next) {}

    node<T> *get_next() const {
        return next;
    }

    T get_data() const {
        return data;
    }
};

template<class T>
class stack {
private:
    size_t curr_size_ = 0;
    node<T> *head = nullptr;

public:
    stack() {};

    ~stack() = default;

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
        if (curr_size_ == 0) {
            throw std::out_of_range("The stack is empty");
        }
        return head->get_data();
    }

    void push(const T &x) {
        node<T> *new_node = new node<T>(x, head);
        head = new_node;
        curr_size_++;
    }

    void pop() {
        if (curr_size_ == 0) {
            throw std::out_of_range("The stack is empty");
        }
        const node<T> *temp = head;
        head = head->get_next();
        delete temp;
        curr_size_--;
    }
};

#endif
