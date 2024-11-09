#ifndef NODE_H
#define NODE_H

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

#endif