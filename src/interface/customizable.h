#ifndef CUSTOMIZABLE_H
#define CUSTOMIZABLE_H

#include "fragment.h"

namespace Plotypus
{
    struct Customizable : public Fragment
    {
        virtual std::optional<std::string> getOptions() const = 0;
        virtual std::string getOptionsOrDefault(const std::string& defaultValue) const = 0;
        virtual void setOptions(const std::string& newOptions) = 0;
        virtual void clearOptions() = 0;
    };
}

#endif // CUSTOMIZABLE_H
