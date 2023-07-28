#ifndef ENHANCEDFRAGMENT_H
#define ENHANCEDFRAGMENT_H

#include "base/groupedproperties/scriptfragment.h"

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

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}

#endif // ENHANCEDFRAGMENT_H
