#include "tip_pdfcairo.h"

namespace Plotypus
{
    TIP_PdfCairo::TIP_PdfCairo(const std::filesystem::path& target) :
        TerminalInfoProvider(target)
    {}

    void TIP_PdfCairo::reset()
    {
        EnhancedFragment::reset();
        ColorFragment::reset();
        FontFragment::reset();
        LineEndsFragment::reset();
        BackgroundFragment::reset();
    }

    bool TIP_PdfCairo::validateScript()
    {
        return false;
    }

    void TIP_PdfCairo::writeScript(std::ostream& hFile)
    {

    }
}
