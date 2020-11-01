//
// Created by Michael Kotor on 10/13/20.
//

#ifndef LABA05_BUSSINES_H
#define LABA05_BUSSINES_H


#include "IP.h"
#include "Tourist.h"

class Business : public IP, public Tourist {
    char addresses[20][20];
    int counterAddress;
public:
    Business();
    Business(const char* oneAddress);
    ~Business();

    char *getName() override;
    char *getSurname() override;
    int getDateOfBirth() override;

    void setName(const char *name) override;
    void setSurname(const char *surname) override;
    void setDateOfBirth(int dateOfBirth) override;

    void input(istream &in) noexcept(false) override;
    void output(ostream &out) const override;

    char* getAddresses();

    int addAddress(const char* address);
    void createNewAddress();
};


#endif //LABA05_BUSSINES_H
