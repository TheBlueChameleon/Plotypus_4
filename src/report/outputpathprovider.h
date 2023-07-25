#ifndef FILENAMEPROVIDER_H
#define FILENAMEPROVIDER_H

#include <filesystem>

namespace Plotypus
{
    class OutputPathProvider
    {
        public:
            enum class GeneratedFileType
            {
                None,
                Txt,
                Data,
                Script,
                Report
            };

        private:
            std::filesystem::path   baseDirectory;
            std::string             baseFilename        = "report";
            std::string             extTxt              = "txt";
            std::string             extDat              = "dat";
            std::string             extGnu              = "gnuplot";
            std::string             extOut              = "pdf";

            std::pair<std::filesystem::path, std::string> getRawBasePathAndExt(const GeneratedFileType filetype) const;

        public:
            OutputPathProvider() = default;

            void reset();

            const std::filesystem::path& getBaseDirectory() const;
            void setBaseDirectory(const std::filesystem::path& newBaseDirectory);

            const std::string& getBaseFilename() const;
            void setBaseFilename(const std::string& newBaseFilename);

            const std::string& getExtension(const GeneratedFileType filetype) const;
            void setExtension(const GeneratedFileType filetype, const std::string& newExtension);

            std::filesystem::path getOutputPath(const GeneratedFileType filetype, const std::string& infix) const;
            std::filesystem::path getOutputPath(const GeneratedFileType filetype, const int page = -1, const int subplot = -1) const;

            std::string getOutputPathString(const GeneratedFileType filetype, const std::string& infix) const;
            std::string getOutputPathString(const GeneratedFileType filetype, const int page = -1, const int subplot = -1) const;
    };
}

#endif // FILENAMEPROVIDER_H
