#include <fstream>

#include "pdfcairo.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        PdfCairo::PdfCairo()
        {
            outputFile = std::make_shared<DefaultPersistable>();
        }

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
            ValidationResult result;
            result.absorbValidationResult(outputFile->validate(), getTypeName());
            return result;
        }

        void PdfCairo::writeScript(std::ostream& hFile) const
        {
            hFile << "set term pdfcairo ";
            EnhancedFragment::writeScriptFragment(hFile);
            ColorFragment::writeScriptFragment(hFile);
            FontFragment::writeScriptFragment(hFile);
            LineEndsFragment::writeScriptFragment(hFile);
            BackgroundFragment::writeScriptFragment(hFile);
            ContinuousSizeFragment::writeScriptFragment(hFile);
            UserCodeFragment::writeScriptFragment(hFile);
            hFile << std::endl;

            hFile << "set output " << outputFile->getPath() << std::endl;
            hFile << std::endl;
        }

        std::string PdfCairo::getDefaultExtension()
        {
            return "pdf";
        }

        std::string PdfCairo::getInstanceName() const
        {
            return getTypeName();
        }

        std::string PdfCairo::getTypeName()
        {
            return "pdfCairo";
        }

        const std::filesystem::path& PdfCairo::getPath() const
        {
            return outputFile->getPath();
        }

        void PdfCairo::setPath(const std::filesystem::path& newPath)
        {
            outputFile->setPath(newPath);
        }

        bool PdfCairo::getMakeDirectories() const
        {
            return outputFile->getMakeDirectories();
        }

        void PdfCairo::setMakeDirectories(bool newMakeDirectories)
        {
            outputFile->setMakeDirectories(newMakeDirectories);
        }

        bool PdfCairo::getOverwrite() const
        {
            return outputFile->getOverwrite();
        }

        void PdfCairo::setOverwrite(bool newOverwrite)
        {
            outputFile->setOverwrite(newOverwrite);
        }

        bool PdfCairo::getAllowNullPath() const
        {
            return outputFile->getAllowNullPath();
        }

        void PdfCairo::setAllowNullPath(bool newAllowNullPath)
        {
            outputFile->setAllowNullPath(newAllowNullPath);
        }

        std::ofstream PdfCairo::getFileStream() const
        {
            return outputFile->getFileStream();
        }

        std::ostringstream PdfCairo::getStringStream() const
        {
            return outputFile->getStringStream();
        }
    }
}
