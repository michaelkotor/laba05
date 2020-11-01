//
// Created by Michael Kotor on 10/20/20.
//

#ifndef LABA05_INPUTEXCEPTION_H
#define LABA05_INPUTEXCEPTION_H


#include "CustomException.h"

class InputException : public CustomException {
public:
    InputException(const string &msg, int errNum) noexcept;
    explicit InputException(const string &msg) noexcept;
};


#endif //LABA05_INPUTEXCEPTION_H
