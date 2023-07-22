#ifndef REPORT_H
#define REPORT_H

#include "../interface/scriptable.h"
#include "../interface/nonAssignable.h"
#include "../interface/terminalInfoProvider.h"

#include "outputPathProvider.h"

namespace Plotypus
{
    class Report :
        public NonAssignable,
        public Scriptable,
        public OutputPathProvider
    {
        private:
            bool autoSetChildFileNames = true;
            PersistableImpl scriptPersistable;

            TerminalInfoProvider* tip = nullptr;

            std::string runCommand = "gnuplot $f";


        public:
            Report();

            bool getSetUpdateChildFileNames() const;
            void setSetUpdateChildFileNames(const bool newSetUpdateChildFileNames);
            void setChildFileNames();

            Persistable& getScriptFile();
            Persistable& getOutputFile();

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
    };
}

#include "report.txx"

#endif // REPORT_H
