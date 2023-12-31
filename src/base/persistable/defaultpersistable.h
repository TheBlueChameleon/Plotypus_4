#ifndef DEFAULTPERSISTABLE_H
#define DEFAULTPERSISTABLE_H

#include "persistable.h"

#include "base/validationresult/validationresult.h"


namespace Plotypus
{
    class DefaultPersistable:
        public virtual Persistable
    {
        private:
            std::filesystem::path path;

            bool makeDirectories = true;
            bool overwrite = false;
            bool allowNullPath = false;

        public:
            DefaultPersistable() = default;

            // NamedType interface
            std::string getInstanceName() const;
            static std::string getTypeName();

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

            bool operator ==(const Persistable& other) const;

            // Validatable interface
            ValidationResult validate() const;
    };
}

#endif // DEFAULTPERSISTABLE_H
