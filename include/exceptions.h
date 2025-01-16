#pragma once
#include <stdexcept>
#include <string>

class AppException : public std::runtime_error
{
public:
    explicit AppException(const std::string &message)
        : std::runtime_error(message) {}
};

inline void throwAppInvalidTimerParams(const std::string &message)
{
    throw AppException(message);
}