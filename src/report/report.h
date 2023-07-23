#ifndef REPORT_H
#define REPORT_H

#include "../interface/baseProperties/nonAssignable.h"
#include "../interface/baseProperties/persistable.h"

#include "../interface/baseProperties/defaultImpl/defaultpersistable.h"

#include "../interface/groupedProperties/userscriptinjectable.h"
#include "../interface/groupedProperties/scriptable.h"

#include "../interface/groupedProperties/defaultImpl/defaultuserscriptinjectable.h"

#include "../interface/terminalInfoProvider.h"

#include "outputPathProvider.h"

namespace Plotypus
{
    class Report :
        public NonAssignable,
        public Persistable,
        public Scriptable,
        public UserScriptInjectable,

        public OutputPathProvider
    {
        private:
            TerminalInfoProvider* tip = nullptr;
            DefaultPersistable scriptFile;
            DefaultUserScriptInjectable userScripts;

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

            // Persistable interface
            const std::filesystem::path& getPath() const;
            void setPath(const std::filesystem::path& newPath);

            bool getMakeDirectories() const;
            void setMakeDirectories(bool newMakeDirectories);

            bool getOverwrite() const;
            void setOverwrite(bool newOverwrite);

            // Scriptable interface
            void reset();
            ValidationResult validate() const;
            void writeScript(std::ostream& hFile);

            std::ofstream getFileStream() const;
            std::ostringstream getStringStream();

            // UserScriptInjectable interface
            std::optional<std::string> getUserScriptBeforeSetup() const;
            void setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup);

            std::optional<std::string> getUserScriptBeforeChildren() const;
            void setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren);

            std::optional<std::string> getUserScriptCleanUp() const;
            void setUserScriptCleanUp(const std::string& newUserScriptCleanUp);

            void writeUserScriptBeforeSetup(std::ostream& hFile);
            void writeUserScriptBeforeChildren(std::ostream& hFile);
            void writeUserScriptCleanUp(std::ostream& hFile);
    };
}

#include "report.txx"

#endif // REPORT_H
