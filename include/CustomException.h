//
// Created by Michael Kotor on 10/20/20.
//

#ifndef LABA05_CUSTOMEXCEPTION_H
#define LABA05_CUSTOMEXCEPTION_H


#include <stdexcept>
#include <string>
#include <utility>

using namespace std;

class CustomException : public std::exception {
protected:
    int errorNumber{};               ///< Error number
    string errorMessage;      ///< Error message
public:
    /** Constructor (C++ STL string, int, int).
     *  @param msg The error message
     *  @param err_num Error number
     *  @param err_off Error offset
     */
    explicit
    CustomException(std::string  msg, int errNum):
            errorNumber(errNum),
            errorMessage(std::move(msg))
    {}

    explicit CustomException(string errorMessage) : errorMessage(std::move(errorMessage)) {}

    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    ~CustomException() noexcept override = default;

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *  is in possession of the Except object. Callers must
     *  not attempt to free the memory.
     */
    virtual const char* what() const noexcept override {
        return errorMessage.c_str();
    }

    /** Returns error number.
     *  @return #error_number
     */
    virtual int getErrorNumber() const noexcept {
        return errorNumber;
    }
};


#endif //LABA05_CUSTOMEXCEPTION_H
