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

        std::string EnhancedFragment::generateScriptFragment() const
        {
            if (enhanced)
            {
                return "enhanced ";
            }
            else
            {
                return "noenhanced ";
            }
        }
    }
}
