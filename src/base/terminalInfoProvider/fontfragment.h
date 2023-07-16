#ifndef FONTFRAGMENT_H
#define FONTFRAGMENT_H

#include <string_view>

#include "../../interface/fragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class FontFragment : public Fragment
        {
            protected:
                std::string font = "Sans,12";

            private:
                std::pair<std::string_view, std::string_view> findHalves() const;

            public:
                FontFragment() = default;

                const std::string_view                 getFont() const;
                const std::string_view                 getFontFace() const;
                const int                              getFontSize() const;
                const std::pair<std::string_view, int> getFontData() const;

                void setFont(const std::string& newFontFace, const int newFontSize);

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}
#endif // FONTFRAGMENT_H
