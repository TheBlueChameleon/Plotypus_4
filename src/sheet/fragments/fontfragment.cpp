#include "fontfragment.h"

namespace Plotypus
{
    namespace SheetFragments
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
            fontFragment.setFont(newFontFace, newFontSize);
        }

        void FontFragment::reset()
        {
            fontFragment.reset();
        }

        void FontFragment::writeScriptFragment(std::ostream& hFile) const
        {
            hFile << "set font ";
            fontFragment.writeScriptFragment(hFile);
            hFile << std::endl;
        }
    }
}
