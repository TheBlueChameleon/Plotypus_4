#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

#include "../typesystem/concepts.h"

namespace Plotypus
{
    struct TerminalInfoProvider : public Scriptable
    {
        virtual std::string getDefaultExtension() = 0;

        virtual const std::filesystem::path& getFileCreatedByScript() const = 0;
        virtual void setFileCreatedByScript(const std::filesystem::path& newFileCreatedByScript) = 0;

        template<TerminalInfoProviderType T>
        T& as()
        {
            return dynamic_cast<T>(*this);
        }
    };
}

#endif // TERMINALINFOPROVIDER_H
