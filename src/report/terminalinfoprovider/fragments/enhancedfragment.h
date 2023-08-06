#ifndef ENHANCEDFRAGMENT_H
#define ENHANCEDFRAGMENT_H

#include "base/scriptfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class EnhancedFragment : public ScriptFragment
        {
            private:
                bool enhanced = true;

            public:
                EnhancedFragment() = default;
                bool getEnhanced() const;
                void setEnhanced(bool newEnhanced);

                // ScriptFragment interface
                void reset();
                void writeScriptFragment(std::ostream& hFile) const;
        };
    }
}

#endif // ENHANCEDFRAGMENT_H
