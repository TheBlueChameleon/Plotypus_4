#ifndef BACKGROUNDFRAGMENT_H
#define BACKGROUNDFRAGMENT_H

#include "../../interface/groupedProperties/fragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class BackgroundFragment : public Fragment
        {
            protected:
                std::optional<std::string> background = "";

            public:
                BackgroundFragment() = default;

                std::optional<std::string> getBackground() const;
                void setBackground(const std::string& newBackground);
                void clearBackground();

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}

#endif // BACKGROUNDFRAGMENT_H
