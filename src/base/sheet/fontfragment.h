#ifndef SHEET_FONTFRAGMENT_H
#define SHEET_FONTFRAGMENT_H

#include "../../interface/groupedProperties/scriptfragment.h"

namespace Plotypus
{
    namespace SheetFragments
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

#endif // SHEET_FONTFRAGMENT_H
