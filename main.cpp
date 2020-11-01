#include <iostream>
#include <Tourist.h>
#include <Bussines.h>
#include "include/Man.h"
#include "include/IP.h"

using namespace std;

void customTerminate() {
    cout << "Something went wrong!" << endl;
    cout << "We can't handle this :(" << endl;
    abort();
}

int main() {
    set_terminate(customTerminate);
    const int SIZE = 3;
    Man* people[SIZE];

    for(auto & i : people) {
        cout << "Hello!" << endl;
        cout << "\t1. Create new IP" << endl << "\t2. Create new Tourist" << endl << "\t3. Create new Business" << endl;
        int choise;
        cin >> choise;
        switch (choise) {
            case 1:
                i = new IP;
                cin >> *i;
                break;
            case 2:
                i = new Tourist;
                cin >> *i;
                break;
            case 3:
                i = new Business;
                cin >> *i;
                break;
            case 0:
                exit(0);
        }
    }

    for(int i = 0; i < SIZE; i++) {
        cout << *people[i] << endl;
    }

    return 0;
}
