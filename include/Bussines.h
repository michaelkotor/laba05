//
// Created by Michael Kotor on 10/13/20.
//

#ifndef LABA05_BUSSINES_H
#define LABA05_BUSSINES_H


#include "IP.h"
#include "Tourist.h"

class Business : public IP, public Tourist {
    char addresses[20][50];
public:
    Business();
    ~Business();

    char* getAddresses();
};


#endif //LABA05_BUSSINES_H
