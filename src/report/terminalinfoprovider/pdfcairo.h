#ifndef TIP_PDFCAIRO_H
#define TIP_PDFCAIRO_H

#include <memory>

#include "fragments/enhancedfragment.h"
#include "fragments/colorfragment.h"
#include "fragments/fontfragment.h"
#include "fragments/lineendsfragment.h"
#include "fragments/backgroundfragment.h"
#include "fragments/continuoussizefragment.h"
#include "base/fragments/usercodefragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class PdfCairo :
            public TerminalInfoProvider,

            private EnhancedFragment,
            private ColorFragment,
            private FontFragment,
            private LineEndsFragment,
            private BackgroundFragment,
            private ContinuousSizeFragment,
            private UserCodeFragment
        {
            private:
                DefaultPersistable_SP outputFile;

            public:
                PdfCairo() = default;

                // Scriptable interface
                void reset();
                ValidationResult validate() const;
                void writeScript(std::ostream& hFile) const;

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
                std::ostringstream getStringStream() const;

                // TerminalInfoProvider interface
                static std::string getDefaultExtension();
                std::string getInstanceName() const;
                static std::string getTypeName();
        };
    }
}

#endif // TIP_PDFCAIRO_H
