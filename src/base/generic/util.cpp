#include <fstream>
#include <string>
using namespace std::string_literals;

#include "util.h"

namespace Plotypus
{
    namespace Util
    {
        std::ofstream getFileStream(const std::filesystem::path& file)
        {
            const std::string filename = file.string();
            auto hFile = std::ofstream(filename, std::ios_base::out);

            if (!hFile.is_open())
            {
                throw FileIOError("Could not create file: "s + filename);
            }

            return hFile;
        }

        std::ostringstream getStringStream()
        {
            return std::ostringstream();
        }

        const auto failure = ValidationResult::makeValidationResult<FileIOError>;
        ValidationResult validatePersistable(const Persistable& persistable)
        {
            const bool overwrite = persistable.getOverwrite();
            const bool makeDirectories = persistable.getMakeDirectories();
            const auto file = persistable.getPath();

            if (!overwrite)
            {
                if (std::filesystem::exists(file))
                {
                    return failure("File '"s + file.string() + "' already exists.");
                }
            }

            const auto& parentDir = file.parent_path();
            if (parentDir.empty()) // implicitly in CWD -- always valid
            {
                return ValidationResult::SUCCESS;
            }

            if (!makeDirectories)
            {
                if (!std::filesystem::exists(parentDir))
                {
                    return failure("Directory '"s + parentDir.string() + "' does not exist.");
                }
            }
            else
            {
                if (std::filesystem::exists(parentDir) && !std::filesystem::is_directory(parentDir))
                {
                    return failure("'"s + parentDir.string() + "' is not a directory.");
                }
            }

            return ValidationResult::SUCCESS;
        }

        void resetPersistable(Persistable& persistable)
        {
            persistable.setPath("");
            persistable.setMakeDirectories(false);
            persistable.setOverwrite(false);
        }

    }
}
