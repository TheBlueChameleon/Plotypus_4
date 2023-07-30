#ifndef COLORFRAGMENT_H
#define COLORFRAGMENT_H

#include "base/groupedproperties/scriptfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class ColorFragment : public ScriptFragment
        {
            private:
                bool color = true;

            public:
                ColorFragment() = default;
                bool getColor() const;
                void setColor(bool newColor);

                // ScriptFragment interface
                void reset();
                void writeScriptFragment(std::ostream& hFile) const;
        };
    }
}
#endif // COLORFRAGMENT_H
