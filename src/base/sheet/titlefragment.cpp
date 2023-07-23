#include "titlefragment.h"

namespace Plotypus
{
    namespace SheetFragments
    {
        std::pair<std::string_view, std::string_view> TitleFragment::findHalves() const
        {
            const size_t splitPoint = font.find(',');
            std::string_view first, second;

            if (splitPoint == std::string::npos)
            {
                first  = font;
                second = "";
            }
            else
            {
                first  = std::string_view(font.begin(), font.begin() + splitPoint);
                second = std::string_view(font.begin() + splitPoint + 1, font.end());
            }

            return std::make_pair(first, second);
        }

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

        std::string TitleFragment::generateScriptFragment() const
        {
            if (title.has_value())
            {
                const std::string& title_v = title.value();
                std::ostringstream result;

                result << "set title " << '"';
                result << "{/" << fontFragment.getFont() << " " << title_v << "}";
                result << '"' << std::endl;

                return result.str();
            }
            else
            {
                return "";
            }
        }
    }
}
