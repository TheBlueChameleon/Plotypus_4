#include "usercodefragment.h"

namespace Plotypus
{
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

    void UserCodeFragment::reset()
    {
        userCode.reset();
    }

    void UserCodeFragment::writeScriptFragment(std::ostream& hFile) const
    {
        if (userCode.has_value())
        {
            hFile << userCode.value() << " ";
        }
    }
}
