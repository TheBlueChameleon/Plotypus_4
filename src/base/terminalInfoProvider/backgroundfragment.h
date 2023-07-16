#ifndef BACKGROUNDFRAGMENT_H
#define BACKGROUNDFRAGMENT_H

#include "../../interface/fragment.h"

namespace Plotypus
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

#endif // BACKGROUNDFRAGMENT_H
