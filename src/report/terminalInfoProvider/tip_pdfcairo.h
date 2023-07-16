#ifndef TIP_PDFCAIRO_H
#define TIP_PDFCAIRO_H

#include "../../interface/terminalInfoProvider.h"

#include "../../base/terminalInfoProvider/enhancedfragment.h"
#include "../../base/terminalInfoProvider/colorfragment.h"
#include "../../base/terminalInfoProvider/fontfragment.h"
#include "../../base/terminalInfoProvider/lineendsfragment.h"
#include "../../base/terminalInfoProvider/backgroundfragment.h"

namespace Plotypus
{
    class TIP_PdfCairo :
        public TerminalInfoProvider,
        public EnhancedFragment,
        public ColorFragment,
        public FontFragment,
        public LineEndsFragment,
        public BackgroundFragment
    {
        protected:
            std::filesystem::path target;

        public:
            TIP_PdfCairo(const std::filesystem::path& target);

            // Scriptable interface
            void reset();
            bool validateScript();
            void writeScript(std::ostream& hFile);
    };
}

#endif // TIP_PDFCAIRO_H
