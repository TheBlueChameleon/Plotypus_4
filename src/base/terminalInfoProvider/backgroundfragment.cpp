#include "backgroundfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        std::optional<std::string> BackgroundFragment::getBackground() const
        {
            return background;
        }

        void BackgroundFragment::setBackground(const std::string& newBackground)
        {
            background = newBackground;
        }

        void BackgroundFragment::clearBackground()
        {
            background.reset();
        }

        void BackgroundFragment::reset()
        {
            clearBackground();
        }

        std::string BackgroundFragment::generateScriptFragment() const
        {
            if (background.has_value())
            {
                return "background " + background.value() + " ";
            }
            else
            {
                return "";
            }
        }
    }
}
