#include <iostream>
#include <Tourist.h>
#include <Bussines.h>
#include "include/Man.h"
#include "include/IP.h"


using namespace std;

int main() {
//    Man* people[3];
//
//    for(auto & i : people) {
//        cout << "Hello!" << endl;
//        cout << "\t1. Create new IP" << endl << "\t2. Create new Tourist" << endl << "\t3. Create new Business" << endl;
//        int choise;
//        cin >> choise;
//        switch (choise) {
//            case 1:
//                i = new IP;
//                cin >> *i;
//                break;
//            case 2:
//                i = new Tourist;
//                cin >> *i;
//                break;
//            case 3:
//                i = new Business;
//                cin >> *i;
//                break;
//            case 0:
//                exit(0);
//        }
//    }
//
//    for(auto & i : people) {
//        cout<< *i << endl;
//    }

    Business* man = new Business;
    cin >> *man;
    man->createNewAddress();
    man->createNewPayment();
    man->createNewCheckIn();

    cout << *man;


    return 0;
}
