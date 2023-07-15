#ifndef SCRIPTABLE_TXX
#define SCRIPTABLE_TXX

#include "scriptable.h"

namespace Plotypus
{
    std::string Scriptable::getOptions() const
    {
        return options.value_or("");
    }

    Scriptable& Scriptable::setOptions(const std::string& newOptions)
    {
        options = newOptions;
        return *this;
    }

    Scriptable& Scriptable::clearOptions()
    {
        options.reset();
        return *this;
    }
}
#endif // SCRIPTABLE_TXX
