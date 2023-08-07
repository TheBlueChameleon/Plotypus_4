#ifndef DEFAULTPROPAGATINGPERSISTABLE_H
#define DEFAULTPROPAGATINGPERSISTABLE_H

#include "defaultpersistablefragment.h"
#include "propagatingpersistable.h"

namespace Plotypus
{
    class DefaultPropagatingPersistable :
        public PropagatingPersistable,

        private DefaultPersistableFragment
    {
        private:
            bool propagateUpdateChildFileNames = true;
            FiFo<Persistable> subscribers;

        public:
            DefaultPropagatingPersistable() = default;

            // NamedType interface
            std::string getInstanceName() const;
            static std::string getTypeName();

            // Mutable interface
            void reset();

            // Validatable interface
            ValidationResult validate() const;

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

            // PropagatingPersistable interface
            bool getPropagateUpdateChildFileNames() const;
            void setPropagateUpdateChildFileNames(const bool newPropagateUpdateChildFileNames);

            std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix);
            void updateChildFileNames();
            void addSubscriber(std::shared_ptr<Persistable>& subscriber);
            void replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber);
            Collection<Persistable>& getSubscribers();
            const Collection<Persistable>& getSubscribers() const;
    };

    class DefaultPropagatingPersistable_SP :
        public PropagatingPersistable,
        public DefaultPersistable
    {
        private:
            std::shared_ptr<DefaultPropagatingPersistable> m;

        public:
            DefaultPropagatingPersistable_SP();

            std::shared_ptr<DefaultPropagatingPersistable>& getSharedPtr();

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

            // PropagatingPersistable interface
            bool getPropagateUpdateChildFileNames() const;
            void setPropagateUpdateChildFileNames(const bool newSetUpdateChildFileNames);
            std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix);
            void updateChildFileNames();
            void addSubscriber(std::shared_ptr<Persistable>& subscriber);
            void replaceSubscriber(std::shared_ptr<Persistable>& oldSubscriber, std::shared_ptr<Persistable>& newSubscriber);
            Collection<Persistable>& getSubscribers();
            const Collection<Persistable>& getSubscribers() const;
    };

    static_assert(PersistableSPType<DefaultPropagatingPersistable_SP>);
}

#endif // DEFAULTPROPAGATINGPERSISTABLE_H
