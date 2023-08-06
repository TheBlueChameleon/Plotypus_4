#ifndef DEFAULTPROPAGATINGPERSISTABLE_H
#define DEFAULTPROPAGATINGPERSISTABLE_H

#include "../propagatingpersistable.h"

#include "defaultpersistable.h"

namespace Plotypus
{
    class DefaultPropagatingPersistable :
        public PropagatingPersistable,
        public DefaultPersistable
    {
        private:
            bool propagateUpdateChildFileNames = true;
            FiFo<Persistable> subscribers;

        public:
            DefaultPropagatingPersistable() = default;

            // PropagatingPersistable interface
            bool getPropagateUpdateChildFileNames() const;
            void setPropagateUpdateChildFileNames(const bool newPropagateUpdateChildFileNames);

            std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix);
            void propagate();
            void addSubscriber(std::shared_ptr<Persistable>& subscriber);
            Collection<Persistable>& getSubscribers();

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
    };

    class DefaultPropagatingPersistable_SP :
        public PropagatingPersistable,
        public DefaultPersistable
    {
        private:
            std::shared_ptr<DefaultPropagatingPersistable> m;

        public:
            DefaultPropagatingPersistable_SP();

            std::shared_ptr<DefaultPropagatingPersistable>& get();

            // NamedType interface
            std::string getInstanceName() const;
            static std::string getTypeName();

            // Mutable interface
            void reset();

            // PropagatingPersistable interface
            bool getPropagateUpdateChildFileNames() const;
            void setPropagateUpdateChildFileNames(const bool newSetUpdateChildFileNames);
            std::filesystem::path getDerivedPath(const std::string& extension, std::optional<std::string> infix);
            void propagate();
            void addSubscriber(std::shared_ptr<Persistable>& subscriber);
            Collection<Persistable>& getSubscribers();

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

#endif // DEFAULTPROPAGATINGPERSISTABLE_H
