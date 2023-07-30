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
                case LineEnds::Rounded:
                    hFile << "rounded ";
                case LineEnds::Square:
                    hFile << "square ";
                case LineEnds::Butt:
                    hFile << "butt ";
            }

            throw InvalidArgumentError("Unknown LineEnds type.");
        }
    }
}
