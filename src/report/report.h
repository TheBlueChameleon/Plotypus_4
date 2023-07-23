#ifndef REPORT_H
#define REPORT_H

#include "../interface/baseProperties/nonAssignable.h"
#include "../interface/baseProperties/persistable.h"
#include "../interface/groupedProperties/scriptable.h"
#include "../interface/terminalInfoProvider.h"

#include "outputPathProvider.h"

namespace Plotypus
{
    class Report :
        public NonAssignable,
        public Scriptable,
        public Persistable,
        public OutputPathProvider
    {
        private:
            TerminalInfoProvider* tip = nullptr;
            DefaultPersistable scriptFile;

            std::string runCommand = "gnuplot $f";

            bool autoUpdateChildFileNames = true;

        public:
            Report();

            bool getAutoUpdateChildFileNames() const;
            void setAutoUpdateChildFileNames(const bool newSetUpdateChildFileNames);
            void setChildFileNames();

            const std::string& getRunCommand() const;
            void setRunCommand(const std::string& newRunCommand);
            std::string getParsedRunCommand() const;

            template<TerminalInfoProviderType T>
            T& installTerminal();
            template<TerminalInfoProviderType T>
            T getTerminal();

            void compile();
            void writeScript();
            void runScript();

            std::string getScriptString();

            // Scriptable interface
            void reset();
            ValidationResult validate() const;
            void writeScript(std::ostream& hFile);

            // Persistable interface
            const std::filesystem::path& getPath() const;
            void setPath(const std::filesystem::path& newPath);

            bool getMakeDirectories() const;
            void setMakeDirectories(bool newMakeDirectories);

            bool getOverwrite() const;
            void setOverwrite(bool newOverwrite);

            std::ofstream getFileStream() const;
            std::ostringstream getStringStream();
    };
}

#include "report.txx"

#endif // REPORT_H
