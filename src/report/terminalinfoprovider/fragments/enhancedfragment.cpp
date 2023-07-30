#include "enhancedfragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        bool EnhancedFragment::getEnhanced() const
        {
            return enhanced;
        }

        void EnhancedFragment::setEnhanced(bool newEnhanced)
        {
            enhanced = newEnhanced;
        }

        void EnhancedFragment::reset()
        {
            enhanced = true;
        }

        void EnhancedFragment::writeScriptFragment(std::ostream& hFile) const
        {
            if (enhanced)
            {
                hFile << "enhanced ";
            }
            else
            {
                hFile << "noenhanced ";
            }
        }
    }
}
