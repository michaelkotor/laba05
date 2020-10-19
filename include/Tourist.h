
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
protected:
    char numberOfPassport[20];
    int counterCheckIns;
    CheckIn checkIns[20];
public:
    Tourist();
    Tourist(const char* numberOfPassport);
    ~Tourist();

    char *getName() override;
    char *getSurname() override;
    int getDateOfBirth() override;

    void setName(const char *name) override;
    void setSurname(const char *surname) override;
    void setDateOfBirth(int dateOfBirth) override;

    void input(istream &in) override;
    void output(ostream &out) const override;

    char* getNumberOfPassport();
    CheckIn* getCheckIns();

    void setNumberOfPassport(const char* numberOfPassport);

    int addCheckIn(CheckIn& checkIn);
    void createNewCheckIn();
};


#endif //LABA05_TOURIST_H
