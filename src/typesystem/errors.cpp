#include <cstring>

#include "errors.h"

namespace Plotypus
{
    PlotypusError::PlotypusError(const std::string& m): std::runtime_error(m) {}

    bool PlotypusError::operator==(const PlotypusError& other) const
    {
        if (typeid(*this) == typeid(other))
        {
            return std::strcmp(this->what(), other.what()) == 0;
        }
        else
        {
            return false;
        }
    };
}
