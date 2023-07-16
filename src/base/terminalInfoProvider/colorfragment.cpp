#include "colorfragment.h"

namespace Plotypus
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
            return "color";
        }
        else
        {
            return "mono";
        }
    }
}
