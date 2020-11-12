//
// Created by Michael Kotor on 11/2/20.
//

#ifndef LABA05_ITERATOR_H
#define LABA05_ITERATOR_H

#include "Node.h"
#include "Queue.h"

template <typename T>
class Iterator {
private:
    Node<T>* value;
public:
    Iterator(Queue<T> queue) {
        this->value = queue.getTop();
    }
    void operator++() {
        if(hasNext()) {
            this->value->next;
        }
    }
    void operator--() {
        if(hasPrevios()) {
            this->value->previos;
        }
    }
    void next() {
        if(hasNext()) {
            this->value->next;
        }
    }
    void previos() {
        if(hasPrevios()) {
            this->value->previos;
        }
    }

    bool hasNext() {
        return this->value->next != nullptr;
    }

    bool hasPrevios() {
        return this->value->previos != nullptr;
    }

    T* get() {
        return this->value;
    }
};

#endif //LABA05_ITERATOR_H