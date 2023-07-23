#ifndef TIP_PDFCAIRO_H
#define TIP_PDFCAIRO_H

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
            private:
                std::filesystem::path path;

                bool makeDirectories = true;
                bool overwrite = false;

            public:
                PdfCairo(const std::filesystem::path& fileCreatedByScript);

                // Scriptable interface
                void reset();
                ValidationResult validate() const;
                void writeScript(std::ostream& hFile);

                // TerminalInfoProvider interface
                static std::string getDefaultExtension();

                // Persistable interface
                const std::filesystem::path& getPath() const;
                void setPath(const std::filesystem::path& newPath);

                bool getMakeDirectories() const;
                void setMakeDirectories(bool newMakeDirectories);

                bool getOverwrite() const;
                void setOverwrite(bool newOverwrite);

                std::ofstream getFileStream() const;
                std::ostringstream getStringStream();
        };
    }
}

#endif // TIP_PDFCAIRO_H
