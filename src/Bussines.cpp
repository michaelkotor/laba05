//
// Created by Michael Kotor on 10/13/20.
//

#include "../include/Bussines.h"
#include "cstring"

Business::Business() :  IP(), Tourist() {
    this->counterAddress = 0;
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

void Business::input(istream &in) {

    cout << "Enter name: " << endl;
    in.getline(this->name, 20);

    cout << "Enter surname: " << endl;
    in.getline(this->surname, 20);

    cout << "Enter address: " << endl;
    in.getline(this->address, 20);

    cout << "Enter numberOfLinsence: " << endl;
    in >> this->numberOfLinsence;

    cin.clear();
    while (cin.get() != '\n')
    {
        continue;
    }

    cout << "Enter numberOfPassport: " << endl;
    in.getline(this->numberOfPassport, 20);

    cout << "Enter dateOfBirth(YEAR): " << endl;
    in >> this->dateOfBirth;
}

void Business::output(ostream &out) const {
    cout << "------------------------------------" << endl;
    cout << "name: "<< this->name << endl;
    cout << "surname: "<< this->surname << endl;
    cout << "numberOfPassport: "<< this->numberOfPassport << endl;
    cout << "address: "<< this->address << endl;
    cout << "numberOfLinsence: "<< this->numberOfLinsence << endl;
    cout << "dateOfBirth: "<< this->dateOfBirth << endl;
    for(int i = 0; i < this->counterCheckIns; i++) {
        cout << "\tcheckIns[" << i << "].date = " << this->checkIns[i].date << endl;
        cout << "\tcheckIns[" << i << "].country = " << this->checkIns[i].country << endl;
    }
    for(int i = 0; i < this->counterPayments; i++) {
        cout << "\t\tpayments[" << i << "].date = " << this->payments[i].date << endl;
        cout << "\t\tpayments[" << i << "].value = " << this->payments[i].value << endl;
    }
    for(int i = 0; i < this->counterAddress; i++) {
        cout << "\t\t\taddresses[" << i << "] = " << this->addresses[i] << endl;
    }
    cout << "------------------------------------" << endl;
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
