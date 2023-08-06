#include <cstring>

#include "errors.h"

namespace Plotypus
{
    PlotypusError::PlotypusError(const std::string& m): std::runtime_error(m) {}

    void PlotypusError::trigger() const
    {
        throw* this;
    }

    PlotypusError* PlotypusError::getDuplicate() const
    {
        return new PlotypusError(this->what());
    };
}
