#include <fstream>

#include "pdfcairo.h"

#include "../../base/util.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        PdfCairo::PdfCairo(const std::filesystem::path& fileCreatedByScript) :
            path(fileCreatedByScript)
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

            Util::resetPersistable(*this);
        }

        ValidationResult PdfCairo::validate() const
        {
            if (path.empty())
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

        const std::filesystem::path& PdfCairo::getPath() const
        {
            return path;
        }

        void PdfCairo::setPath(const std::filesystem::path& newPath)
        {
            path = newPath;
        }

        bool PdfCairo::getMakeDirectories() const
        {
            return makeDirectories;
        }

        void PdfCairo::setMakeDirectories(bool newMakeDirectories)
        {
            makeDirectories = newMakeDirectories;
        }

        bool PdfCairo::getOverwrite() const
        {
            return overwrite;
        }

        void PdfCairo::setOverwrite(bool newOverwrite)
        {
            overwrite = newOverwrite;
        }

        std::ofstream PdfCairo::getFileStream() const
        {
            return Util::getFileStream(path);
        }

        std::ostringstream PdfCairo::getStringStream()
        {
            return Util::getStringStream();
        }
    }
}
