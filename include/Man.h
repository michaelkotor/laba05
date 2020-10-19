//
// Created by Michael Kotor on 10/13/20.
//

#ifndef LABA05_MAN_H
#define LABA05_MAN_H

#include <iostream>

using namespace std;

class Man {
protected:
    char name[20];
    char surname[20];
    int dateOfBirth;
public:
    Man();
    Man(const char* name, const char* surname, int dateOfBirth);
    virtual ~Man();

    virtual char* getName() = 0;
    virtual char* getSurname() = 0;
    virtual int getDateOfBirth() = 0;

    virtual void setName(const char* name) = 0;
    virtual void setSurname(const char* surname) = 0;
    virtual void setDateOfBirth(int dateOfBirth) = 0;

    friend ostream& operator<<(ostream &out, const Man& man);
    friend istream& operator>>(istream &in, Man& man);

    virtual void input(istream &in) = 0;
    virtual void output(ostream &out) const = 0;


};


#endif //LABA05_MAN_H
