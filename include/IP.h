//
// Created by Michael Kotor on 10/13/20.
//

#ifndef LABA05_IP_H
#define LABA05_IP_H


#include "Man.h"
#include <iostream>

using namespace std;

struct Payment {
    char date[20];
    int value;
};

class IP : public Man {
    int numberOfLinsence;
    char address[20];
    Payment payments[20];
    int counter;
public:
    IP();
    IP(int numberOfLinsence, char* address);
    ~IP();

    char *getName() override;
    char *getSurname() override;
    int getDateOfBirth() override;

    void setName(char *name) override;
    void setSurname(char *surname) override;
    void setDateOfBirth(int dateOfBirth) override;

    void input(istream &in) override;
    void output(ostream &out) override;

    int getNumberOfLinsence();
    char *getAddress();
    Payment *getPayments();
    void setNumberOfLinsence(int numberOfLinsence);
    void setAddress(char *address);
};


#endif //LABA05_IP_H
