#ifndef DEFAULTPERSISTABLE_H
#define DEFAULTPERSISTABLE_H

#include "persistable.h"
#include "defaultpersistablefragment.h"

#include "base/validationresult/validationresult.h"

#include "../mutable.h"
#include "../validatable.h"

namespace Plotypus
{
    class DefaultPersistable:
        public NamedType,
        public Mutable,
        public Persistable,
        public Validatable,

        private DefaultPersistableFragment
    {
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

    class DefaultPersistable_SP:
        public NamedType,
        public Mutable,
        public Persistable,
        public Validatable
    {
        private:
            std::shared_ptr<DefaultPersistable> m;

        public:
            DefaultPersistable_SP();

            std::shared_ptr<DefaultPersistable>& get();

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

    static_assert(PersistableSPType<DefaultPersistable_SP>);
}

#endif // DEFAULTPERSISTABLE_H