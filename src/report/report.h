#ifndef REPORT_H
#define REPORT_H

#include <memory>

#include "base/nonassignable.h"

#include "base/persistable/propagatingpersistable.h"
#include "base/persistable/defaultpropagatingpersistable.h"

#include "base/scriptable.h"
#include "base/userscriptinjectable/defaultuserscriptinjectable.h"

#include "terminalinfoprovider/terminalinfoprovider.h"

namespace Plotypus
{
    class Report :
        public virtual NamedType,
        public virtual NonAssignable,
        public virtual PropagatingPersistable,
        public virtual Scriptable,

        public virtual DefaultUserScriptInjectable
    {
        private:
            std::shared_ptr<TerminalInfoProvider> tip;
            std::shared_ptr<DefaultPropagatingPersistable> scriptFile;

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

            // NamedType interface
            std::string getInstanceName() const;
            static std::string getTypeName();

            // Scriptable interface
            void reset();

            ValidationResult validate() const;
            void writeScript(std::ostream& hFile) const;

            std::ofstream getFileStream() const;
            std::ostringstream getStringStream() const;

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
            void replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber);
            Collection<Persistable>& getSubscribers();
            const Collection<Persistable>& getSubscribers() const;
    };
}

#include "report.txx"

#endif // REPORT_H
