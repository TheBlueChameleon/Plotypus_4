#ifndef ABSTRACTTERMINALINFOPROVIDER_H
#define ABSTRACTTERMINALINFOPROVIDER_H

namespace Plotypus
{
    class AbstractTerminalInfoProvider : public TerminalInfoProvider
    {
        private:
            std::filesystem::path fileCreatedByScript;

        public:
            AbstractTerminalInfoProvider(const std::filesystem::path& fileCreatedByScript);

            const std::filesystem::path& getFileCreatedByScript() const;
            void setFileCreatedByScript(const std::filesystem::path& newFileCreatedByScript);

            // Scriptable interface
            void reset();
    };
}

#endif // ABSTRACTTERMINALINFOPROVIDER_H
