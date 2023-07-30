#ifndef TITLEFRAGMENT_H
#define TITLEFRAGMENT_H

#include "base/groupedproperties/scriptfragment.h"

namespace Plotypus
{
    namespace SheetFragments
    {
        class TitleFragment : public ScriptFragment
        {
            private:
                std::optional<std::string> title;
                GenericFontFragment fontFragment;

            public:
                TitleFragment() = default;

                std::optional<std::string> getTitle() const;
                void setTitle(const std::string& newTitle);
                void clearTitle();

                const std::string_view                 getTitleFont() const;
                const std::string_view                 getTitleFontFace() const;
                const int                              getTitleFontSize() const;
                const std::pair<std::string_view, int> getTitleFontData() const;

                void setFont(const std::string& newFontFace, const int newFontSize);

                // Mutable interface
                void reset();

                // ScriptFragment interface
                void writeScriptFragment(std::ostream& hFile) const;
        };
    }
}

#endif // TITLEFRAGMENT_H
