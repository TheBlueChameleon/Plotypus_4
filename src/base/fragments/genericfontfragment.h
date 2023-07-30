#ifndef ABSTRACTFONTFRAGMENT_H
#define ABSTRACTFONTFRAGMENT_H

namespace Plotypus
{
    class GenericFontFragment : public ScriptFragment
    {
        private:
            std::string font = "Sans,12";

            std::pair<std::string_view, std::string_view> findHalves() const;
        public:
            GenericFontFragment() = default;

            const std::string_view                 getFont() const;
            const std::string_view                 getFontFace() const;
            const int                              getFontSize() const;
            const std::pair<std::string_view, int> getFontData() const;

            void setFont(const std::string& newFontFace, const int newFontSize);

            // Mutable interface
            void reset();

            // ScriptFragment interface
            void writeScriptFragment(std::ostream& hFile) const;
    };
}

#endif // ABSTRACTFONTFRAGMENT_H
