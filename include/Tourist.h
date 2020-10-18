
//
// Created by Michael Kotor on 10/13/20.
//

#ifndef LABA05_TOURIST_H
#define LABA05_TOURIST_H


#include "Man.h"

struct CheckIn {
    char date[20];
    char country[20];
};

class Tourist : public Man {
    char numberOfPassport[20];
    CheckIn checkIns[20];
public:
    Tourist();
    Tourist(char* numberOfPassport);
    ~Tourist();

    char *getName() override;
    char *getSurname() override;
    int getDateOfBirth() override;

    void setName(char *name) override;
    void setSurname(char *surname) override;
    void setDateOfBirth(int dateOfBirth) override;

    char* getNumberOfPassport();
    CheckIn* getCheckIns();

    void setNumberOfPassport(char* numberOfPassport);
    void setCheckIns(CheckIn* checkIns);
};


#endif //LABA05_TOURIST_H
