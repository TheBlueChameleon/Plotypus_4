#ifndef TIP_PDFCAIRO_H
#define TIP_PDFCAIRO_H

#include "../../base/terminalinfoprovider/enhancedfragment.h"
#include "../../base/terminalinfoprovider/colorfragment.h"
#include "../../base/terminalinfoprovider/fontfragment.h"
#include "../../base/terminalinfoprovider/lineendsfragment.h"
#include "../../base/terminalinfoprovider/backgroundfragment.h"
#include "../../base/terminalinfoprovider/continuoussizefragment.h"
#include "../../base/generic/usercodefragment.h"

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
                DefaultPersistable outputFile;

            public:
                PdfCairo() = default;

                // Scriptable interface
                void reset();
                ValidationResult validate() const;
                void writeScript(std::ostream& hFile);

                // Persistable interface
                const std::filesystem::path& getPath() const;
                void setPath(const std::filesystem::path& newPath);

                bool getMakeDirectories() const;
                void setMakeDirectories(bool newMakeDirectories);

                bool getOverwrite() const;
                void setOverwrite(bool newOverwrite);

                bool getAllowNullPath() const;
                void setAllowNullPath(bool newAllowNullPath);

                std::ofstream getFileStream() const;
                std::ostringstream getStringStream();

                // TerminalInfoProvider interface
                static std::string getDefaultExtension();
                static const std::string getTypeName();
        };
    }
}

#endif // TIP_PDFCAIRO_H
