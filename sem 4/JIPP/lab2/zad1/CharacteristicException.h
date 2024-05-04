#ifndef CHARACTERISTIC_EXCEPTION_H
#define CHARACTERISTIC_EXCEPTION_H

#include <exception>
#include <string>

class CharacteristicException : public std::exception
{
private:
    std::string message;

public:
    // Constructor without message
    CharacteristicException() noexcept;

    // Constructor with message
    explicit CharacteristicException(const std::string& msg) noexcept;

    // Override what() method to provide exception message
    const char* what() const noexcept override;
};

#endif /* CHARACTERISTIC_EXCEPTION_H */
