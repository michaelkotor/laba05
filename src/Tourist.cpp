//
// Created by Michael Kotor on 10/13/20.
//

#include "../include/Tourist.h"
#include "cstring"

using namespace std;

Tourist::Tourist() : Man("Michael", "Kotor", 2001) {
    (void) this->checkIns;
    strcpy(this->numberOfPassport, "Some number");
}

Tourist::~Tourist() {

}

Tourist::Tourist(const char *numberOfPassport) : Man("Michael", "Kotor", 2001) {
    strcpy(this->numberOfPassport, numberOfPassport);
}

char *Tourist::getName() {
    return this->name;
}

char *Tourist::getSurname() {
    return this->surname;
}

int Tourist::getDateOfBirth() {
    return this->dateOfBirth;
}

void Tourist::setName(const char *name) {
    strcpy(this->name, name);
}

void Tourist::setSurname(const char *surname) {
    strcpy(this->surname, surname);
}

void Tourist::setDateOfBirth(int dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

char *Tourist::getNumberOfPassport() {
    return nullptr;
}

CheckIn *Tourist::getCheckIns() {
    return nullptr;
}

void Tourist::setNumberOfPassport(const char *numberOfPassport1) {
    strcpy(this->numberOfPassport, numberOfPassport1);
}

void Tourist::input(istream &in) {
    cout << "Enter name: " << endl;
    in.getline(this->name, 20);

    cout << "Enter surname: " << endl;
    in.getline(this->surname, 20);

    cout << "Enter numberOfPassport: " << endl;
    in.getline(this->numberOfPassport, 20);

    cout << "Enter dateOfBirth(YEAR): " << endl;
    in >> this->dateOfBirth;
}

void Tourist::output(ostream &out) const {
    cout << "------------------------------------" << endl;
    cout << "name: "<< this->name << endl;
    cout << "surname: "<< this->surname << endl;
    cout << "numberOfPassport: "<< this->numberOfPassport << endl;
    cout << "dateOfBirth: "<< this->dateOfBirth << endl;
    for(int i = 0; i < this->counterCheckIns; i++) {
        cout << "\tpayments[" << i << "].date = " << this->checkIns[i].date << endl;
        cout << "\tpayments[" << i << "].country = " << this->checkIns[i].country << endl;
    }
    cout << "------------------------------------" << endl;
}
