#ifndef REPORT_H
#define REPORT_H

#include "../interface/scriptable.h"

#include "outputPathProvider.h"

namespace Plotypus
{
    class TerminalInfoProvider;

    class Report :
        public Scriptable,
        public OutputPathProvider
    {
        private:
            bool autoSetChildFileNames = true;
            PersistableImpl outputPersistable;
            PersistableImpl scriptPersistable;

            TerminalInfoProvider* tip = nullptr;

        public:
            Report() = default;

            bool getSetUpdateChildFileNames() const;
            void setSetUpdateChildFileNames(const bool newSetUpdateChildFileNames);
            void setChildFileNames();

            Persistable& getScriptFile();
            Persistable& getOutputFile();

            void compile();
            void runScript();

            // Scriptable interface
            void reset();

            ValidationResult validateScript();
            void writeScript(std::ostream& hFile);
    };
}

#endif // REPORT_H
