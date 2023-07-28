#ifndef LINEENDSFRAGMENT_H
#define LINEENDSFRAGMENT_H

#include "typesystem/enums.h"
#include "base/groupedproperties/scriptfragment.h"

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

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}

#endif // LINEENDSFRAGMENT_H
