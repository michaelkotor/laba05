//
// Created by Michael Kotor on 10/13/20.
//

#include "../include/Tourist.h"
#include "cstring"
#include <iostream>
#include <iomanip>
#include <ValidateString.h>
#include <InputException.h>

using namespace std;

Tourist::Tourist() : Man("Michael", "Kotor", 2001) {
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

void Tourist::input(istream &in) noexcept(false) {
    ValidateString validateString;

    bool isBroken = true;
    while(isBroken) {
        try {
            cout << "Enter name: " << endl;
            in.getline(this->name, 20);
            validateString.validateStringEnglish(this->name, 20);
            isBroken = false;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }

    isBroken = true;
    while(isBroken) {
        try {
            cout << "Enter surname: " << endl;
            in.getline(this->surname, 20);
            validateString.validateStringEnglish(this->surname, 20);
            isBroken = false;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }

    isBroken = true;
    while(isBroken) {
        try {
            cout << "Enter numberOfPassport: " << endl;
            in.getline(this->numberOfPassport, 20);
            if(in.fail()) {
                in.clear();
                in.ignore(256,'\n');
                throw InputException("Invalid char!");
            }
            validateString.validateStringEnglish(this->numberOfPassport, 20);
            isBroken = false;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }

    isBroken = true;
    while(isBroken) {
        try {
            cout << "Enter dateOfBirth(YEAR): " << endl;
            in >> this->dateOfBirth;
            if(in.fail()) {
                in.clear();
                in.ignore(256,'\n');
                throw InputException("Invalid char!");
            }
            validateString.validateInteger(this->dateOfBirth);
            isBroken = false;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }
}

void Tourist::output(ostream &out) const {
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "Name" << "|" << setw(20) << right << this->name << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "Surname" << "|" << setw(20) << right << this->surname << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "NumberOfPassport" << "|"  << setw(20) << right << this->numberOfPassport << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "DateOfBirth" << "|" << setw(20) << right << this->dateOfBirth << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    if(this->counterCheckIns > 0) {
        cout << left << "|" << setw(21) << right << "CheckIns"  << setw(21) << right << setfill(' ') << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    for(int i = 0; i < this->counterCheckIns; i++) {
        cout << left << "|" << setw(20) << "Date" << "|" << setw(20) << right << this->checkIns[i].date << "|" << endl;
        cout << left << "|" << setw(20) << "Country" << "|" << setw(20) << right << this->checkIns[i].country << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
}

int Tourist::addCheckIn(CheckIn &checkIn) {
    this->checkIns[this->counterCheckIns++] = checkIn;
    return this->counterCheckIns;
}

void Tourist::createNewCheckIn() {
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }
    CheckIn checkIn;
    cout << "Enter date" << endl;
    cin.getline(checkIn.date, 20);
    cout << "Enter country" << endl;
    cin.getline(checkIn.country, 20);
    addCheckIn(checkIn);
}
