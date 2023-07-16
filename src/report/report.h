#ifndef REPORT_H
#define REPORT_H

#include "../interface/scriptable.h"

#include "outputPathProvider.h"

namespace Plotypus
{
    class Report :
        public Scriptable,
        public PersistableImpl,
        public OutputPathProvider
    {
        private:
        public:
            Report();

            // Scriptable interface
            bool validateScript();
            void writeScript(std::ostream& hFile);
    };
}

#endif // REPORT_H
