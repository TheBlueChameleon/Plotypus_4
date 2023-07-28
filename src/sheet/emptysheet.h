#ifndef EMPTYSHEET_H
#define EMPTYSHEET_H

#include "sheet.h"

#include "base/baseproperties/persistable/defaultpersistable.h"

#include "base/groupedproperties/defaultImpl/defaultnumbereditem.h"
#include "base/groupedproperties/defaultImpl/defaultuserscriptinjectable.h"

#include "fragments/cleansheetfragment.h"
#include "fragments/fontfragment.h"
#include "fragments/titlefragment.h"

namespace Plotypus
{
    class EmptySheet :
        public Sheet,

        public SheetFragments::TitleFragment,
        public SheetFragments::FontFragment,
        public SheetFragments::CleanSheetFragment
    {
        private:
            DefaultNumberedItem number;
            DefaultPersistable file;
            DefaultUserScriptInjectable userCode;

        public:
            EmptySheet() = default;

            // Validatable interface
            ValidationResult validate() const;

            // Mutable interface
            void reset();

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

            // Sheet interface
            void writeScriptHead(std::ostream& hFile) const;
            void writeScriptData(std::ostream& hFile) const;
            void writeScriptOverlays(std::ostream& hFile) const;
            void writeScriptFooter(std::ostream& hFile) const;

            // NumberedItem interface
            size_t getNumber() const;
            void setNumber(size_t number);

            // UserScriptInjectable interface
            std::optional<std::string> getUserScriptBeforeSetup() const;
            void setUserScriptBeforeSetup(const std::string& newUserScriptBeforeSetup);
            std::optional<std::string> getUserScriptBeforeChildren() const;
            void setUserScriptBeforeChildren(const std::string& newUserScriptBeforeChildren);
            std::optional<std::string> getUserScriptCleanUp() const;
            void setUserScriptCleanUp(const std::string& newUserScriptCleanUp);
            void writeUserScriptBeforeSetup(std::ostream& hFile) const;
            void writeUserScriptBeforeChildren(std::ostream& hFile) const;
            void writeUserScriptCleanUp(std::ostream& hFile) const;
    };
}

#endif // EMPTYSHEET_H
