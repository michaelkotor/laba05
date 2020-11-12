//
// Created by Michael Kotor on 11/2/20.
//

#ifndef LABA05_NODE_H
#define LABA05_NODE_H

template <typename T>
struct Node {
    Node *next;
    Node *previos;
    T* data;
};

#endif //LABA05_NODE_H
