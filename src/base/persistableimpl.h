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

            bool makePaths = false;
            bool overwrite = false;

        public:
            PersistableImpl() = default;

            // Persistable interface
            const std::filesystem::path& getFile() const;
            void setFile(const std::filesystem::path& newFile);

            bool getMakePaths() const;
            void setMakePaths(bool newMakePaths);

            bool getOverwrite() const;
            void setOverwrite(bool newOverwrite);

            virtual std::ofstream getFileStream();
            virtual std::ostringstream getStringStream();

            ValidationResult validateFilename();
    };
}

#endif // PERSISTABLEIMPL_H
