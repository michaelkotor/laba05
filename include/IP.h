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

class IP : public virtual Man {
protected:
    int numberOfLinsence;
    char address[20];
    Payment payments[20];
    int counterPayments;
public:
    IP();
    IP(int numberOfLinsence, char* address);
    ~IP();

    char *getName() override;
    char *getSurname() override;
    int getDateOfBirth() override;

    void setName(const char *name) override;
    void setSurname(const char *surname) override;
    void setDateOfBirth(int dateOfBirth) override;

    void input(istream &in) override;
    void output(ostream &out) const override;

    int getNumberOfLinsence();
    char *getAddress();
    Payment *getPayments();
    void setNumberOfLinsence(int numberOfLinsence);
    void setAddress(const char *address);

    virtual int addPayment(Payment& payment);
    virtual void createNewPayment();
};


#endif //LABA05_IP_H
