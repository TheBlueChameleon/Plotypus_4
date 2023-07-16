#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

namespace Plotypus
{
    struct TerminalInfoProvider : public Scriptable
    {
        protected:
            std::filesystem::path fileCreatedByScript;

        public:
            TerminalInfoProvider(const std::filesystem::path& fileCreatedByScript) : fileCreatedByScript(fileCreatedByScript) {}

            virtual std::string getDefaultExtension() = 0;
    };
}

#endif // TERMINALINFOPROVIDER_H
