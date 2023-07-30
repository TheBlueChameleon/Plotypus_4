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

        void ColorFragment::writeScriptFragment(std::ostream& hFile) const
        {
            if (color)
            {
                hFile << "color ";
            }
            else
            {
                hFile << "mono ";
            }
        }
    }
}
