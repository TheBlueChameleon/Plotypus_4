#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

namespace Plotypus
{
    struct TerminalInfoProvider : public Scriptable
    {
        protected:
            std::filesystem::path target;

        public:
            TerminalInfoProvider(const std::filesystem::path& target) : target(target) {}

            // Scriptable interface
            virtual void reset() = 0;
            virtual bool validateScript() = 0;
            virtual void writeScript(std::ostream& hFile) = 0;
    };
}

#endif // TERMINALINFOPROVIDER_H
