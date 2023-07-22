#include "pdfcairo.h"


namespace Plotypus
{
    namespace TerminalInfo
    {
        PdfCairo::PdfCairo(const std::filesystem::path& fileCreatedByScript) :
            TerminalInfoProvider(fileCreatedByScript)
        {}

        void PdfCairo::reset()
        {
            EnhancedFragment::reset();
            ColorFragment::reset();
            FontFragment::reset();
            LineEndsFragment::reset();
            BackgroundFragment::reset();
            ContinuousSizeFragment::reset();
            UserCodeFragment::reset();
        }

        ValidationResult PdfCairo::validateScript()
        {
            if (fileCreatedByScript.empty())
            {
                return ValidationResult::makeValidationResult<InvalidFilenameError>("No filename for the output PDF was set");
            }

            return ValidationResult::SUCCESS;
        }

        void PdfCairo::writeScript(std::ostream& hFile)
        {
            hFile << "set term pdfcairo ";
            hFile << EnhancedFragment::generateScriptFragment();
            hFile << ColorFragment::generateScriptFragment();
            hFile << FontFragment::generateScriptFragment();
            hFile << LineEndsFragment::generateScriptFragment();
            hFile << BackgroundFragment::generateScriptFragment();
            hFile << ContinuousSizeFragment::generateScriptFragment();
            hFile << UserCodeFragment::generateScriptFragment();

            hFile << std::endl;
        }

        std::string PdfCairo::getDefaultExtension()
        {
            return "pdf";
        }
    }
}
