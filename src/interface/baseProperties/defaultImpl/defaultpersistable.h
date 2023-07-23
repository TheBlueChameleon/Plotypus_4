#ifndef DEFAULTPERSISTABLE_H
#define DEFAULTPERSISTABLE_H

#include "../persistable.h"
#include "../../../base/validationresult.h"

namespace Plotypus
{
    class DefaultPersistable:
        public Persistable
    {
        private:
            std::filesystem::path path;
            bool makeDirectories = true;
            bool overwrite = false;
            bool allowNullPath = false;

        public:
            DefaultPersistable() = default;

            ValidationResult validate() const;
            void reset();

            bool getAllowNullPath() const;
            void setAllowNullPath(bool newAllowNullPath);

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

#endif // DEFAULTPERSISTABLE_H
