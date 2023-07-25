#ifndef USERSCRIPTINJECTABLE_H
#define USERSCRIPTINJECTABLE_H

#include "../baseProperties/mutable.h"

namespace Plotypus
{
    struct UserScriptInjectable : public Mutable
    {
        //! @todo introduce clear options

        virtual std::optional<std::string> getUserScriptBeforeSetup() const = 0;
        virtual void setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup) = 0;

        virtual std::optional<std::string> getUserScriptBeforeChildren() const = 0;
        virtual void setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren) = 0;

        virtual std::optional<std::string> getUserScriptCleanUp() const = 0;
        virtual void setUserScriptCleanUp(const std::string& newUserScriptCleanUp) = 0;

        virtual void writeUserScriptBeforeSetup(std::ostream& hFile) const = 0;
        virtual void writeUserScriptBeforeChildren(std::ostream& hFile) const = 0;
        virtual void writeUserScriptCleanUp(std::ostream& hFile) const = 0;
    };
}
#endif // USERSCRIPTINJECTABLE_H
