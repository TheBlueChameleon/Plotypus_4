#ifndef DEFAULTUSERSCRIPTINJECTABLE_H
#define DEFAULTUSERSCRIPTINJECTABLE_H

#include "../userscriptinjectable.h"

namespace Plotypus
{
    class DefaultUserScriptInjectable:
        public UserScriptInjectable
    {
        private:
            std::optional<std::string> userScriptBeforeSetup;
            std::optional<std::string> userScriptBeforeChildren;
            std::optional<std::string> userScriptCleanUp;

            void writeUserScript(std::ostream& hFile, const std::optional<std::string> script, const char* label);

        public:
            DefaultUserScriptInjectable() = default;

            std::optional<std::string> getUserScriptBeforeSetup() const;
            void setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup);

            std::optional<std::string> getUserScriptBeforeChildren() const;
            void setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren);

            std::optional<std::string> getUserScriptCleanUp() const;
            void setUserScriptCleanUp(const std::string& newUserScriptCleanUp);

            void writeUserScriptBeforeSetup(std::ostream& hFile);
            void writeUserScriptBeforeChildren(std::ostream& hFile);
            void writeUserScriptCleanUp(std::ostream& hFile);

            void reset();
    };
}

#endif // DEFAULTUSERSCRIPTINJECTABLE_H
