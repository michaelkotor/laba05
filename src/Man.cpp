//
// Created by Michael Kotor on 10/13/20.
//

#include <cstring>
#include "../include/Man.h"

Man::Man() {
    strcpy(this->name, "Michael");
    strcpy(this->name, "Kotor");
    this->dateOfBirth = 2001;
}

Man::Man(char *name, char *surname, int dateOfBirth) {
    strcpy(this->name, name);
    strcpy(this->name, surname);
    this->dateOfBirth = dateOfBirth;
}

Man::~Man() {

}

ostream &operator<<(ostream &out, const Man &man) {

    return out;
}

istream &operator>>(istream &in, const Man &man) {
    return in;
}
