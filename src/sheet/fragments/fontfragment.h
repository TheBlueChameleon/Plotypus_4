#ifndef SHEET_FONTFRAGMENT_H
#define SHEET_FONTFRAGMENT_H

#include "base/groupedproperties/scriptfragment.h"

#include "base/fragments/genericfontfragment.h"

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

                // ScriptFragment interface
                void reset();
                void writeScriptFragment(std::ostream& hFile) const;
        };
    }
}

#endif // SHEET_FONTFRAGMENT_H
