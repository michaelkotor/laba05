//
// Created by Michael Kotor on 10/20/20.
//

#include "ValidateString.h"
#include "InputException.h"

void ValidateString::validateStringEnglish(const char* someChars, int length) noexcept(false) {
    for(int i = 0; i < length; i++) {
        if(!((someChars[i] >= 'a' && someChars[i] <= 'z') || (someChars[i] >= 'A' && someChars[i] <= 'Z'))) {
            if(someChars[i] == '\0') return;
            string msg = "Invalid first symbol ";
            msg += someChars[i];
            const char *toSend = msg.c_str();
            throw InputException(toSend);
        }
    }
}

void ValidateString::validateInteger(int number) noexcept(false) {
    if(number > INT32_MIN && number < INT32_MAX) {
        return;
    }
    string msg = "Number is invalid: ";
    msg += number;
    throw InputException(msg);
}
