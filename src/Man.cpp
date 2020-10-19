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

Man::Man(const char *name, const char *surname, int dateOfBirth) {
    strcpy(this->name, name);
    strcpy(this->name, surname);
    this->dateOfBirth = dateOfBirth;
}

Man::~Man() {

}

ostream &operator<<(ostream &out, const Man &man) {
    man.output(out);
    return out;
}

istream &operator>>(istream &in, Man &man) {
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }
    man.input(in);
    return in;
}
