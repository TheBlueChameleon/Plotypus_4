#include "fontfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        const std::string_view FontFragment::getFont() const
        {
            return fontFragment.getFont();
        }

        const std::string_view FontFragment::getFontFace() const
        {
            return fontFragment.getFontFace();
        }

        const int FontFragment::getFontSize() const
        {
            return fontFragment.getFontSize();
        }

        const std::pair<std::string_view, int> FontFragment::getFontData() const
        {
            return fontFragment.getFontData();
        }

        void FontFragment::setFont(const std::string& newFontFace, const int newFontSize)
        {
            return fontFragment.setFont(newFontFace, newFontSize);
        }

        void FontFragment::reset()
        {
            return fontFragment.reset();
        }

        std::string FontFragment::generateScriptFragment() const
        {
            return "font " + std::string(getFont()) + " ";
        }
    }
}
