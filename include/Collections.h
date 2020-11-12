//
// Created by Michael Kotor on 11/3/20.
//

#ifndef LABA05_COLLECTIONS_H
#define LABA05_COLLECTIONS_H

#include "Queue.h"
#include "Iterator.h"

template <typename T>
class Collections {
public:
    void findByName(Queue<T> queue, char *name) {
        Iterator<T> iterator(queue);
        while(iterator.hasNext()) {

        }
    }
};


#endif //LABA05_COLLECTIONS_H
