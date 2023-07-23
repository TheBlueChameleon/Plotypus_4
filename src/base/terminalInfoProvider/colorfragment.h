#ifndef COLORFRAGMENT_H
#define COLORFRAGMENT_H

#include "../../interface/groupedProperties/fragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class ColorFragment : public Fragment
        {
            protected:
                bool color = true;

            public:
                ColorFragment() = default;
                bool getColor() const;
                void setColor(bool newColor);

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}
#endif // COLORFRAGMENT_H
