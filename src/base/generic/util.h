#ifndef UTIL_H
#define UTIL_H

namespace Plotypus
{
    namespace Util
    {
        std::ofstream getFileStream(const std::filesystem::path& file);
        std::ostringstream getStringStream();

        ValidationResult validatePersistable(const Persistable& persistable);
        void resetPersistable(Persistable& persistable);
    }
}
#endif // UTIL_H
