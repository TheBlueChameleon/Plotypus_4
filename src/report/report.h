#ifndef REPORT_H
#define REPORT_H

#include "../interface/scriptable.h"

namespace Plotypus
{
    class Report :
        public Scriptable
    {
        public:
            Report();

            // Scriptable interface
            //void writeScript(std::ostream& hFile) const;
    };
}

#endif // REPORT_H
