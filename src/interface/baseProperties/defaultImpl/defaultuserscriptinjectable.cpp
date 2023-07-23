#include "defaultuserscriptinjectable.h"

namespace Plotypus
{
    void DefaultUserScriptInjectable::writeUserScript(std::ostream& hFile, const std::optional<std::string> script, const char* label)
    {
        if (script.has_value())
        {
            hFile << "# " << label << std::endl;
            hFile << script.value() << std::endl;
        }
    }

    std::optional<std::string> DefaultUserScriptInjectable::getUserScriptBeforeSetup() const
    {
        return userScriptBeforeSetup;
    }

    void DefaultUserScriptInjectable::setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup)
    {
        userScriptBeforeSetup = newUserScriptBeforeSetup;
    }

    std::optional<std::string> DefaultUserScriptInjectable::getUserScriptBeforeChildren() const
    {
        return userScriptBeforeChildren;
    }

    void DefaultUserScriptInjectable::setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren)
    {
        userScriptBeforeChildren = newUserScriptBeforeChildren;
    }

    std::optional<std::string> DefaultUserScriptInjectable::getUserScriptCleanUp() const
    {
        return userScriptCleanUp;
    }

    void DefaultUserScriptInjectable::setUserScriptCleanUp(const std::string& newUserScriptCleanUp)
    {
        userScriptCleanUp = newUserScriptCleanUp;
    }


    void DefaultUserScriptInjectable::writeUserScriptBeforeSetup(std::ostream& hFile)
    {
        writeUserScript(hFile, userScriptBeforeSetup, "User Setup Code");
    }

    void DefaultUserScriptInjectable::writeUserScriptBeforeChildren(std::ostream& hFile)
    {
        writeUserScript(hFile, userScriptBeforeChildren, "User Child-Preparation Code");
    }

    void DefaultUserScriptInjectable::writeUserScriptCleanUp(std::ostream& hFile)
    {
        writeUserScript(hFile, userScriptCleanUp, "User CleanUp Code");
    }
}
