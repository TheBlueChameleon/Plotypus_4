#ifndef LINEENDSFRAGMENT_H
#define LINEENDSFRAGMENT_H

#include "../../interface/fragment.h"
#include "../../typesystem/enums.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class LineEndsFragment : public Fragment
        {
            protected:
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
