#ifndef LINEENDSFRAGMENT_H
#define LINEENDSFRAGMENT_H

#include "typesystem/enums.h"
#include "base/scriptfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class LineEndsFragment : public ScriptFragment
        {
            private:
                LineEnds lineEnds = LineEnds::Default;

            public:
                LineEndsFragment() = default;

                LineEnds getLineEnds() const;
                void setLineEnds(LineEnds newLineEnds);

                // ScriptFragment interface
                void reset();
                void writeScriptFragment(std::ostream& hFile) const;
        };
    }
}

#endif // LINEENDSFRAGMENT_H
