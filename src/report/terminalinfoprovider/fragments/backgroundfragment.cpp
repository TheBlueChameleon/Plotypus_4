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

        void BackgroundFragment::writeScriptFragment(std::ostream& hFile) const
        {
            if (background.has_value())
            {
                hFile << "background " << background.value() << " ";
            }
        }
    }
}
