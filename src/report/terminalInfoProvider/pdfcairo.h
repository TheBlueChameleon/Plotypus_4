#ifndef TIP_PDFCAIRO_H
#define TIP_PDFCAIRO_H

#include "../../interface/terminalInfoProvider.h"

#include "../../base/terminalInfoProvider/enhancedfragment.h"
#include "../../base/terminalInfoProvider/colorfragment.h"
#include "../../base/terminalInfoProvider/fontfragment.h"
#include "../../base/terminalInfoProvider/lineendsfragment.h"
#include "../../base/terminalInfoProvider/backgroundfragment.h"
#include "../../base/terminalInfoProvider/continuoussizefragment.h"
#include "../../base/userCodeFragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class PdfCairo :
            public TerminalInfoProvider,

            public EnhancedFragment,
            public ColorFragment,
            public FontFragment,
            public LineEndsFragment,
            public BackgroundFragment,
            public ContinuousSizeFragment,
            public UserCodeFragment
        {
            public:
                PdfCairo(const std::filesystem::path& fileCreatedByScript);

                // Scriptable interface
                void reset();
                ValidationResult validateScript();
                void writeScript(std::ostream& hFile);

                // TerminalInfoProvider interface
                std::string getDefaultExtension();
        };
    }
}

#endif // TIP_PDFCAIRO_H
