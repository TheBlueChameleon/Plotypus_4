#include <fstream>

#include "pdfcairo.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        void PdfCairo::reset()
        {
            EnhancedFragment::reset();
            ColorFragment::reset();
            FontFragment::reset();
            LineEndsFragment::reset();
            BackgroundFragment::reset();
            ContinuousSizeFragment::reset();
            UserCodeFragment::reset();

            outputFile.reset();
        }

        ValidationResult PdfCairo::validate() const
        {
            const ValidationResult outputFileValidation = outputFile.validate();
            if (!outputFileValidation)
            {
                return outputFileValidation;
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

        const std::filesystem::path& PdfCairo::getPath() const
        {
            return outputFile.getPath();
        }

        void PdfCairo::setPath(const std::filesystem::path& newPath)
        {
            outputFile.setPath(newPath);
        }

        bool PdfCairo::getMakeDirectories() const
        {
            return outputFile.getMakeDirectories();
        }

        void PdfCairo::setMakeDirectories(bool newMakeDirectories)
        {
            outputFile.setMakeDirectories(newMakeDirectories);
        }

        bool PdfCairo::getOverwrite() const
        {
            return outputFile.getOverwrite();
        }

        void PdfCairo::setOverwrite(bool newOverwrite)
        {
            outputFile.setOverwrite(newOverwrite);
        }

        std::ofstream PdfCairo::getFileStream() const
        {
            return outputFile.getFileStream();
        }

        std::ostringstream PdfCairo::getStringStream()
        {
            return outputFile.getStringStream();
        }
    }
}
