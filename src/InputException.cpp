//
// Created by Michael Kotor on 10/20/20.
//

#include "InputException.h"

InputException::InputException(const string &msg, int errNum) noexcept : CustomException(msg, errNum) {

}

InputException::InputException(const string &msg) noexcept : CustomException(msg) {

}
