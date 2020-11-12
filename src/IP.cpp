//
// Created by Michael Kotor on 10/13/20.
//

#include "../include/IP.h"
#include "cstring"
#include <iostream>
#include <iomanip>
#include <InputException.h>
#include <ValidateString.h>

using namespace std;

IP::IP() : Man("Michael", "Kotor", 2001) {
    this->numberOfLinsence = 100;
    strcpy(this->address, "Some address");
    this->counterPayments = 0;
}

IP::IP(int numberOfLinsence, char *address) : Man("Michael", "Kotor", 2001) {
    this->numberOfLinsence = numberOfLinsence;
    strcpy(this->address, address);
    this->counterPayments = 0;
}

int IP::getNumberOfLinsence() {
    return this->numberOfLinsence;
}

char *IP::getAddress() {
    return this->address;
}

Payment *IP::getPayments() {
    return this->payments;
}

void IP::setNumberOfLinsence(int numberOfLinsence1) {
    this->numberOfLinsence = numberOfLinsence1;
}

void IP::setAddress(const char *address1) {
    strcpy(this->address, address1);
}

IP::~IP() {

}

char * IP::getName() {
    return this->name;
}

char * IP::getSurname() {
    return this->surname;
}

int IP::getDateOfBirth() {
    return this->dateOfBirth;
}

void IP::setName(const char *name) {
    strcpy(this->name, name);
}

void IP::setSurname(const char *surname) {
    strcpy(this->surname, surname);
}

void IP::setDateOfBirth(int dadateOfBirthte) {
    this->dateOfBirth = dateOfBirth;
}

void IP::input(istream &in) noexcept(false) {
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
            cout << "Enter city: " << endl;
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
            throw;
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
                throw InputException("The number seems not to be an INT");
            }
            if(in.get() != '\n') {
                throw InputException("Number goes out of range!");
            }
            validateString.validateInteger(this->dateOfBirth);
            isBroken = false;
        } catch (InputException &e) {
            cout << e.what() << endl;
        }
    }
}

void IP::output(ostream &out) const {
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "Name" << "|" << setw(20) << right << this->name << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "Surname" << "|" << setw(20) << right << this->surname << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "NumberOfLinsence" << "|"  << setw(20) << right << this->numberOfLinsence << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    cout << left << "|" << setw(20) << "DateOfBirth" << "|" << setw(20) << right << this->dateOfBirth << "|" << endl;
    cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');

    if(this->counterPayments > 0) {
        cout << left << "|" << setw(21) << right << "Payments"  << setw(21) << right << setfill(' ') << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }
    for(int i = 0; i < this->counterPayments; i++) {
        cout << left << "|" << setw(20) << "Date" << "|" << setw(20) << right << this->payments[i].date << "|" << endl;
        cout << left << "|" << setw(20) << "Value" << "|" << setw(20) << right << this->payments[i].value << "|" << endl;
        cout << setw(43) << setfill('-') << '-' << endl << setfill(' ');
    }

}

int IP::addPayment(Payment& payment) {
    this->payments[this->counterPayments++] = payment;
    return this->counterPayments;
}

void IP::createNewPayment() {
    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }
    Payment payment;
    cout << "Enter date" << endl;
    cin.getline(payment.date, 20);
    cout << "Enter value" << endl;
    cin >> payment.value;
    addPayment(payment);
}
