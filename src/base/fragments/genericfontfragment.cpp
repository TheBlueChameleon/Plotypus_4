#include "genericfontfragment.h"

namespace Plotypus
{
    std::pair<std::string_view, std::string_view> Plotypus::GenericFontFragment::findHalves() const
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

    const std::string_view Plotypus::GenericFontFragment::getFont() const
    {
        return font;
    }

    const std::string_view Plotypus::GenericFontFragment::getFontFace() const
    {
        return getFontData().first;
    }

    const int Plotypus::GenericFontFragment::getFontSize() const
    {
        return getFontData().second;
    }

    const std::pair<std::string_view, int> Plotypus::GenericFontFragment::getFontData() const
    {
        const auto& [face, size] = findHalves();
        int size_i = std::atoi(size.data());

        return std::make_pair(face, size_i);
    }

    void Plotypus::GenericFontFragment::setFont(const std::string& newFontFace, const int newFontSize)
    {
        font = newFontFace + "," + std::to_string(newFontSize);
    }

    void GenericFontFragment::reset()
    {
        font = "Sans,12";
    }

    void GenericFontFragment::writeScriptFragment(std::ostream& hFile) const
    {
        hFile << std::quoted(font) << " ";
    }
}
