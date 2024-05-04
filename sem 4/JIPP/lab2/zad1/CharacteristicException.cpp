#include "CharacteristicException.h"

// Constructor without message
CharacteristicException::CharacteristicException() noexcept {}

// Constructor with message
CharacteristicException::CharacteristicException(const std::string& msg) noexcept : message(msg) {}

// Override what() method to provide exception message
const char* CharacteristicException::what() const noexcept
{
    if (!message.empty())
        return message.c_str();
    else
        return "CharacteristicException";
}
