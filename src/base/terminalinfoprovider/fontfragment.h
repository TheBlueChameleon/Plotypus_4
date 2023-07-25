#ifndef TERMINAL_FONTFRAGMENT_H
#define TERMINAL_FONTFRAGMENT_H

#include <string_view>

#include "../generic/genericfontfragment.h"
#include "../../interface/groupedProperties/scriptfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class FontFragment : public ScriptFragment
        {
            private:
                GenericFontFragment fontFragment;

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
#endif // TERMINAL_FONTFRAGMENT_H
