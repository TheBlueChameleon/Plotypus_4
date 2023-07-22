#ifndef PERSISTABLEIMPL_H
#define PERSISTABLEIMPL_H

#include <filesystem>

#include "../interface/persistable.h"

namespace Plotypus
{
    class PersistableImpl : public Persistable
    {
        private:
            std::filesystem::path file;

            bool makeDirectories = true;
            bool overwrite = false;

        public:
            PersistableImpl() = default;

            // Persistable interface
            void reset();

            const std::filesystem::path& getPath() const;
            void setPath(const std::filesystem::path& newFile);

            bool getMakeDirectories() const;
            void setMakeDirectories(bool newMakePaths);

            bool getOverwrite() const;
            void setOverwrite(bool newOverwrite);

            virtual std::ofstream getFileStream();
            virtual std::ostringstream getStringStream();

            ValidationResult validate();
    };
}

#endif // PERSISTABLEIMPL_H
