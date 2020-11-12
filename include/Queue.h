//
// Created by Michael Kotor on 11/1/20.
//

#ifndef LABA05_QUEUE_H
#define LABA05_QUEUE_H

#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
class Queue {
public:
    Queue() {
        this->top = nullptr;
        this->last = nullptr;
    }

    ~Queue() {
        Node<T>* iterator = this->top;
        while (iterator != nullptr) {
            delete iterator->data;
            iterator = iterator->next;
        }
    }

    void add(T* data) {
        Node<T>* node = new Node<T>;
        node->data = data;
        if(this->top == nullptr) {
            this->top = node;
            this->last = node;
            node->previos = nullptr;
            node->next = nullptr;
        } else {
            node->previos = this->last;
            node->next = nullptr;
            this->last->next = node;
            this->last = node;
        }
    }
    
    void print() {
        Node<T>* iterator = this->top;
        while (iterator != nullptr) {
            cout << *iterator->data << endl;
            iterator = iterator->next;
        }
    };

    T* pop() {
        if(this->top != nullptr) {
            Node<T>* toDelete = this->top;
            this->top = this->top->next;
            return toDelete->data;
        }
    }
    T* getTop() {
        return this->top;
    }
    T* getLast() {
        return this->last;
    }
private:
    Node<T>* top;
    Node<T>* last;
};

#endif //LABA05_QUEUE_H
