//
// Created by Michael Kotor on 10/13/20.
//

#include "../include/Bussines.h"
#include "cstring"
#include <iomanip>
#include <ValidateString.h>
#include <InputException.h>


Business::Business() :  IP(), Tourist() {
    this->counterAddress = 0;
}

Business::Business(const char *oneAddress) : Tourist(oneAddress) {
    this->counterAddress = 0;
    addAddress(oneAddress);
}

Business::~Business() {

}

char *Business::getAddresses() {
    return this->addresses[0];
}

char *Business::getName() {
    return this->name;
}

char *Business::getSurname() {
    return this->surname;
}

int Business::getDateOfBirth() {
    return this->dateOfBirth;
}

void Business::setName(const char *name) {
    IP::setName(name);
}

void Business::setSurname(const char *surname) {
    Tourist::setSurname(surname);
}

void Business::setDateOfBirth(int dateOfBirth) {
    Tourist::setDateOfBirth(dateOfBirth);
}

void Business::input(istream &in) noexcept(false) {
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
            cout << "Enter address: " << endl;
            in.getline(this->address, 20);
            validateString.validateStringEnglish(this->address, 20);
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
            cout << "Enter numberOfLinsence: " << endl;
            in >> this->numberOfLinsence;
            if(in.fail()) {
                in.clear();
                in.ignore(256,'\n');
                throw InputException("Invalid char!");
            }
            if(in.get() != '\n') {
                throw InputException("Invalid char!");
            }
            validateString.validateInteger(this->numberOfLinsence);
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
            if(in.get() != '\n') {
                throw InputException("Invalid char!");
            }
            validateString.validateInteger(this->dateOfBirth);
            isBroken = false;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }
}

void Business::output(ostream &out) const {
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "Name" << "|" << setw(20) << right << this->name << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "Surname" << "|" << setw(20) << right << this->surname << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "NumberOfLinsence" << "|"  << setw(20) << right << this->numberOfLinsence << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    out << left << "|" << setw(20) << "NumberOfPassport" << "|"  << setw(20) << right << this->numberOfPassport << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    out << left << "|" << setw(20) << "Address" << "|"  << setw(20) << right << this->address << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "DateOfBirth" << "|" << setw(20) << right << this->dateOfBirth << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    if(this->numberOfLinsence > 0) {
        cout << left << "|" << setw(21) << right << "Payments"  << setw(21) << right << setfill(' ') << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    for(int i = 0; i < this->counterPayments; i++) {
        cout << left << "|" << setw(20) << "Date" << "|" << setw(20) << right << this->payments[i].date << "|" << endl;
        cout << left << "|" << setw(20) << "Value" << "|" << setw(20) << right << this->payments[i].value << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    if(this->counterPayments > 0) {
        cout << left << "|" << setw(21) << right << "Payments"  << setw(21) << right << setfill(' ') << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    for(int i = 0; i < this->counterPayments; i++) {
        cout << left << "|" << setw(20) << "Date" << "|" << setw(20) << right << this->payments[i].date << "|" << endl;
        cout << left << "|" << setw(20) << "Value" << "|" << setw(20) << right << this->payments[i].value << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    if(this->counterAddress > 0) {
        cout << left << "|" << setw(21) << right << "Addresses"  << setw(21) << right << setfill(' ') << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    for(int i = 0; i < this->counterAddress; i++) {
        cout << left << "|" << setw(20) << "Address" << "|" << setw(20) << right << this->addresses[i] << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
}

int Business::addAddress(const char *address) {
    strcpy(this->addresses[this->counterAddress++], address);
    return this->counterAddress;
}

void Business::createNewAddress() {
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }
    char temp[20];
    cout << "Create new Address" << endl;
    cin.getline(temp, 20);
    addAddress(temp);
}
