#include "colorfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        bool ColorFragment::getColor() const
        {
            return color;
        }

        void ColorFragment::setColor(bool newColor)
        {
            color = newColor;
        }

        void ColorFragment::reset()
        {
            color = true;
        }

        std::string ColorFragment::generateScriptFragment() const
        {
            if (color)
            {
                return "color ";
            }
            else
            {
                return "mono ";
            }
        }
    }
}
