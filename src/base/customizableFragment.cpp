#include "customizableFragment.h"

namespace Plotypus
{
    void CustomizableFragment::reset()
    {
        options.reset();
    }

    std::optional<std::string> CustomizableFragment::getOptions() const
    {
        return options;
    }

    std::string CustomizableFragment::getOptionsOrDefault(const std::string& defaultValue) const
    {
        return options.value_or(defaultValue);
    }

    void CustomizableFragment::setOptions(const std::string& newOptions)
    {
        options = newOptions;
    }

    void CustomizableFragment::clearOptions()
    {
        options.reset();
    }

    std::string CustomizableFragment::generateScriptFragment() const
    {
        if (options.has_value())
        {
            return options.value() + " ";
        }
        else
        {
            return "";
        }
    }
}
