#include "customizableImpl.h"

namespace Plotypus
{
    void CustomizableImpl::reset()
    {
        options.reset();
    }

    std::optional<std::string> CustomizableImpl::getOptions() const
    {
        return options;
    }

    std::string CustomizableImpl::getOptionsOrDefault(const std::string& defaultValue) const
    {
        return options.value_or(defaultValue);
    }

    void CustomizableImpl::setOptions(const std::string& newOptions)
    {
        options = newOptions;
    }

    void CustomizableImpl::clearOptions()
    {
        options.reset();
    }

    std::string CustomizableImpl::generateScriptFragment() const
    {
        return options.value_or("");
    }
}
