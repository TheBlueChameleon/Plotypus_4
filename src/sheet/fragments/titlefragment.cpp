#include "titlefragment.h"

namespace Plotypus
{
    namespace SheetFragments
    {
        std::optional<std::string> TitleFragment::getTitle() const
        {
            return title;
        }

        void TitleFragment::setTitle(const std::string& newTitle)
        {
            title = newTitle;
        }

        void TitleFragment::clearTitle()
        {
            title.reset();
        }

        const std::string_view TitleFragment::getTitleFont() const
        {
            return fontFragment.getFont();
        }

        const std::string_view TitleFragment::getTitleFontFace() const
        {
            return fontFragment.getFontFace();
        }

        const int TitleFragment::getTitleFontSize() const
        {
            return fontFragment.getFontSize();
        }

        const std::pair<std::string_view, int> TitleFragment::getTitleFontData() const
        {
            return fontFragment.getFontData();
        }

        void TitleFragment::setFont(const std::string& newFontFace, const int newFontSize)
        {
            fontFragment.setFont(newFontFace, newFontSize);
        }

        void TitleFragment::reset()
        {
            fontFragment.reset();
            title.reset();
        }

        void TitleFragment::writeScriptFragment(std::ostream& hFile) const
        {
            if (title.has_value())
            {
                const std::string& title_v = title.value();

                hFile << "set title " << '"';
                hFile << "{/" << fontFragment.getFont() << " " << title_v << "}";
                hFile << '"' << std::endl;
            }
        }
    }
}
