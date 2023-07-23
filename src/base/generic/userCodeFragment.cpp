#include "userCodeFragment.h"

namespace Plotypus
{
    void UserCodeFragment::reset()
    {
        userCode.reset();
    }

    std::optional<std::string> UserCodeFragment::getUserCode() const
    {
        return userCode;
    }

    std::string UserCodeFragment::getUserCodeOrDefault(const std::string& defaultValue) const
    {
        return userCode.value_or(defaultValue);
    }

    void UserCodeFragment::setUserCode(const std::string& newOptions)
    {
        userCode = newOptions;
    }

    void UserCodeFragment::clearUserCode()
    {
        userCode.reset();
    }

    std::string UserCodeFragment::generateScriptFragment() const
    {
        if (userCode.has_value())
        {
            return userCode.value() + " ";
        }
        else
        {
            return "";
        }
    }
}
