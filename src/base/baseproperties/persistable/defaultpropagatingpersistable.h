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

        public:
            DefaultPropagatingPersistable() = default;

            // PropagatingPersistable interface
            bool getPropagateUpdateChildFileNames() const;
            void setPropagateUpdateChildFileNames(const bool newPropagateUpdateChildFileNames);

            // void propagate(Collection<Persistable> children);

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
}

#endif // DEFAULTPROPAGATINGPERSISTABLE_H