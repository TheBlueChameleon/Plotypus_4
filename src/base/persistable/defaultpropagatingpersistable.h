#ifndef DEFAULTPROPAGATINGPERSISTABLE_H
#define DEFAULTPROPAGATINGPERSISTABLE_H

#include "propagatingpersistable.h"

namespace Plotypus
{
    class DefaultPropagatingPersistable :
        public PropagatingPersistable,

        public virtual DefaultPersistable
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
}

#endif // DEFAULTPROPAGATINGPERSISTABLE_H
