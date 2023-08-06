#ifndef BACKGROUNDFRAGMENT_H
#define BACKGROUNDFRAGMENT_H

#include "base/scriptfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class BackgroundFragment : public ScriptFragment
        {
            private:
                std::optional<std::string> background = "";

            public:
                BackgroundFragment() = default;

                std::optional<std::string> getBackground() const;
                void setBackground(const std::string& newBackground);
                void clearBackground();

                // ScriptFragment interface
                void reset();
                void writeScriptFragment(std::ostream& hFile) const;
        };
    }
}

#endif // BACKGROUNDFRAGMENT_H
