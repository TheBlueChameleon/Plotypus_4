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

        std::string LineEndsFragment::generateScriptFragment() const
        {
            switch (lineEnds)
            {
                case LineEnds::Default:
                    return "";
                case LineEnds::Rounded:
                    return "rounded ";
                case LineEnds::Square:
                    return "square ";
                case LineEnds::Butt:
                    return "butt ";
            }

            throw InvalidArgumentError("Unknown LineEnds type.");
        }
    }
}
