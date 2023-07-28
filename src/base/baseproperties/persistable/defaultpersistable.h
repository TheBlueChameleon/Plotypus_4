#ifndef DEFAULTPERSISTABLE_H
#define DEFAULTPERSISTABLE_H

#include "../mutable.h"
#include "../persistable.h"
#include "../validatable.h"

#include "base/validationresult/validationresult.h"

namespace Plotypus
{
    class DefaultPersistable:
        public Mutable,
        public Persistable,
        public Validatable
    {
        private:
            std::filesystem::path path;

            bool makeDirectories = true;
            bool overwrite = false;
            bool allowNullPath = false;

        public:
            DefaultPersistable() = default;

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

            // Validatable interface
            ValidationResult validate() const;
    };
}

#endif // DEFAULTPERSISTABLE_H
