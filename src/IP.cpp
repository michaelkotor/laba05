//
// Created by Michael Kotor on 10/13/20.
//

#include "../include/IP.h"
#include "cstring"
#include <iostream>

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

void IP::input(istream &in) {

    cout << "Enter name: " << endl;
    cin.clear();

    in.getline(this->name, 20);

    cout << "Enter surname: " << endl;
    in.getline(this->surname, 20);

    cout << "Enter address: " << endl;
    in.getline(this->address, 20);

    cout << "Enter numberOfLinsence: " << endl;
    in >> this->numberOfLinsence;

    cout << "Enter dateOfBirth(YEAR): " << endl;
    in >> this->dateOfBirth;
}

void IP::output(ostream &out) const {
    cout << "------------------------------------" << endl;
    cout << "name: "<< this->name << endl;
    cout << "surname: "<< this->surname << endl;
    cout << "address: "<< this->address << endl;
    cout << "numberOfLinsence: "<< this->numberOfLinsence << endl;
    cout << "dateOfBirth: "<< this->dateOfBirth << endl;
    for(int i = 0; i < this->counterPayments; i++) {
        cout << "\tpayments[" << i << "].date = " << this->payments[i].date << endl;
        cout << "\tpayments[" << i << "].value = " << this->payments[i].value << endl;
    }
    cout << "------------------------------------" << endl;
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
