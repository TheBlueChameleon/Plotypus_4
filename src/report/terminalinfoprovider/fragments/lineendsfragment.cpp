#include "lineendsfragment.h"
#include "typesystem/errors.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        LineEnds LineEndsFragment::getLineEnds() const
        {
            return lineEnds;
        }

        void LineEndsFragment::setLineEnds(LineEnds newLineEnds)
        {
            lineEnds = newLineEnds;
        }

        void LineEndsFragment::reset()
        {
            lineEnds = LineEnds::Default;
        }

        void LineEndsFragment::writeScriptFragment(std::ostream& hFile) const
        {
            switch (lineEnds)
            {
                case LineEnds::Default:
                    hFile << "";
                    return;
                case LineEnds::Rounded:
                    hFile << "rounded ";
                    return;
                case LineEnds::Square:
                    hFile << "square ";
                    return;
                case LineEnds::Butt:
                    hFile << "butt ";
                    return;
            }

            throw InvalidArgumentError("Unknown LineEnds type: " + std::to_string(static_cast<int>(lineEnds)));
        }
    }
}
