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

            const std::filesystem::path& getFile() const;
            PersistableImpl& setFile(const std::filesystem::path& newFile);

            bool getMakePaths() const;
            PersistableImpl& setMakePaths(bool newMakePaths);

            bool getOverwrite() const;
            PersistableImpl& setOverwrite(bool newOverwrite);

            // Persistable interface
            virtual std::ofstream getFileStream();
            virtual std::ostringstream getStringStream();

            ValidationResult validateFilename();
            void write(std::ostream& hFile) = 0;
    };
}

#endif // PERSISTABLEIMPL_H
