#ifndef REPORT_H
#define REPORT_H

#include <memory>

#include "base/nonassignable.h"

#include "base/persistable/propagatingpersistable.h"
#include "base/persistable/defaultpropagatingpersistable.h"

#include "base/scriptable.h"
#include "base/userscriptinjectable/userscriptinjectable.h"
#include "base/userscriptinjectable/defaultuserscriptinjectable.h"

#include "terminalinfoprovider/terminalinfoprovider.h"

namespace Plotypus
{
    class Report :
        public NamedType,
        public NonAssignable,
        public PropagatingPersistable,
        public Scriptable,
        public UserScriptInjectable
    {
        private:
            std::shared_ptr<TerminalInfoProvider> tip;
            DefaultPropagatingPersistable_SP scriptFile;
            DefaultUserScriptInjectable userScripts;

            Array<Sheet> sheets;

            std::string runCommand = "gnuplot $f";

        public:
            Report();

            const std::string& getRunCommand() const;
            void setRunCommand(const std::string& newRunCommand);
            std::string getParsedRunCommand() const;

            template<TerminalInfoProviderType T>
            T& installTerminal();
            template<TerminalInfoProviderType T>
            T& getTerminal();

            void compile() const;
            void writeScript() const;
            void runScript() const;

            std::string getScriptString() const;

            // PropagatingPersistable interface
            const std::filesystem::path& getPath() const;
            void setPath(const std::filesystem::path& newPath);

            bool getMakeDirectories() const;
            void setMakeDirectories(bool newMakeDirectories);

            bool getOverwrite() const;
            void setOverwrite(bool newOverwrite);

            bool getPropagateUpdateChildFileNames() const;
            void setPropagateUpdateChildFileNames(const bool newPropagateUpdateChildFileNames);

            bool getAllowNullPath() const;
            void setAllowNullPath(bool newAllowNullPath);

            std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix = std::optional<std::string>());
            void updateChildFileNames();
            void addSubscriber(std::shared_ptr<Persistable>& subscriber);
            template<PersistableSPType T>
            void addSubscriber(T& subscriber);
            void replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber);
            Collection<Persistable>& getSubscribers();
            const Collection<Persistable>& getSubscribers() const;

            // NamedType interface
            std::string getInstanceName() const;
            static std::string getTypeName();

            // Mutable interface
            void reset();

            // Scriptable interface
            ValidationResult validate() const;
            void writeScript(std::ostream& hFile) const;

            std::ofstream getFileStream() const;
            std::ostringstream getStringStream() const;

            // UserScriptInjectable interface
            std::optional<std::string> getUserScriptBeforeSetup() const;
            void setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup);

            std::optional<std::string> getUserScriptBeforeChildren() const;
            void setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren);

            std::optional<std::string> getUserScriptCleanUp() const;
            void setUserScriptCleanUp(const std::string& newUserScriptCleanUp);

            void writeUserScriptBeforeSetup(std::ostream& hFile) const;
            void writeUserScriptBeforeChildren(std::ostream& hFile) const;
            void writeUserScriptCleanUp(std::ostream& hFile) const;
    };
}

#include "report.txx"

#endif // REPORT_H
