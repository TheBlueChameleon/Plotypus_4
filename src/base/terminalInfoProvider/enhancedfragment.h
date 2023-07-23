#ifndef ENHANCEDFRAGMENT_H
#define ENHANCEDFRAGMENT_H

#include "../../interface/groupedProperties/fragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class EnhancedFragment : public Fragment
        {
            protected:
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
