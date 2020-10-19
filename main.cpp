#include <iostream>
#include <Tourist.h>
#include <Bussines.h>
#include "include/Man.h"
#include "include/IP.h"


using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Man* people[3];

    for(auto & i : people) {
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
                //people[i] = new Business;
                //cin >> *people[i];
                break;
            case 0:
                exit(0);
        }
    }

    for(auto & i : people) {
        cout<< *i << endl;
    }

    return 0;
}
