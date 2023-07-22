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
            PersistableImpl(const std::filesystem::path& file);

            // Persistable interface
            void reset();

            const std::filesystem::path& getPath() const;
            void setPath(const std::filesystem::path& newFile);

            bool getMakeDirectories() const;
            void setMakeDirectories(bool newMakePaths);

            bool getOverwrite() const;
            void setOverwrite(bool newOverwrite);

            virtual std::ofstream getFileStream() const;
            virtual std::ostringstream getStringStream();

            ValidationResult validate() const;
    };
}

#endif // PERSISTABLEIMPL_H
