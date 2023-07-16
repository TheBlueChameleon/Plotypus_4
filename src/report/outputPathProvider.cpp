#include "outputPathProvider.h"

namespace Plotypus
{

    void OutputPathProvider::reset()
    {
        baseDirectory.clear();
        baseFilename    = "report";
        extTxt          = "txt";
        extDat          = "dat";
        extGnu          = "gnuplot";
        extOut          = "pdf";
    }

    const std::filesystem::path& OutputPathProvider::getBaseDirectory() const
    {
        return baseDirectory;
    }

    OutputPathProvider& OutputPathProvider::setBaseDirectory(const std::filesystem::path& newBaseDirectory)
    {
        baseDirectory = newBaseDirectory;
        return *this;
    }

    const std::string& OutputPathProvider::getBaseFilename() const
    {
        return baseFilename;
    }

    OutputPathProvider& OutputPathProvider::setBaseFilename(const std::string& newBaseFilename)
    {
        baseFilename = newBaseFilename;
        return *this;
    }

    const std::string& OutputPathProvider::getExtension(const GeneratedFileType filetype) const
    {
        switch (filetype)
        {
            case GeneratedFileType::None:
                throw InvalidArgumentError("Filetype 'None' has no extension.");
            case GeneratedFileType::Data:
                return extDat;
            case GeneratedFileType::Txt:
                return extTxt;
            case GeneratedFileType::Script:
                return extGnu;
            case GeneratedFileType::Report:
                return extOut;
        };
        throw InvalidArgumentError("Unknown File Type");
    }

    OutputPathProvider& OutputPathProvider::setExtension(const GeneratedFileType filetype, const std::string& newExtension)
    {
        switch (filetype)
        {
            case GeneratedFileType::None:
                throw InvalidArgumentError("Filetype 'None' has no extension.");
            case GeneratedFileType::Data:
                extDat = newExtension;
            case GeneratedFileType::Txt:
                extTxt = newExtension;
            case GeneratedFileType::Script:
                extGnu = newExtension;
            case GeneratedFileType::Report:
                extOut = newExtension;
        };

        return *this;
    }

    std::pair<std::filesystem::path, std::string> OutputPathProvider::getRawBasePathAndExt(const GeneratedFileType filetype) const
    {
        std::filesystem::path path= baseDirectory / baseFilename;
        std::string ext;

        switch (filetype)
        {
            case GeneratedFileType::None:
                break;
            case GeneratedFileType::Data:
                ext = extDat;
                break;
            case GeneratedFileType::Txt:
                ext = extTxt;
                break;
            case GeneratedFileType::Script:
                ext = extGnu;
                break;
            case GeneratedFileType::Report:
                ext = extOut;
                break;
        };

        return std::make_pair(path, ext);
    }

    std::filesystem::path OutputPathProvider::getOutputPath(const GeneratedFileType filetype, const std::string& infix) const
    {
        auto [path, ext] = getRawBasePathAndExt(filetype);

        path += (infix.size() ? "_" + infix : "");
        path += "." + ext;
        return path;
    }

    std::filesystem::path OutputPathProvider::getOutputPath(const GeneratedFileType filetype, const int page, const int subplot) const
    {
        std::string infix;
        if (page >= 0)
        {
            infix = std::to_string(page);
            if (subplot >= 0)
            {
                infix += "_" + std::to_string(subplot);
            }
        }

        return getOutputPath(filetype, infix);
    }

    std::string OutputPathProvider::getOutputPathString(const GeneratedFileType filetype, const std::string& infix) const
    {
        return getOutputPath(filetype, infix).string();
    }

    std::string OutputPathProvider::getOutputPathString(const GeneratedFileType filetype, const int page, const int subplot) const
    {
        return getOutputPath(filetype, page, subplot).string();
    }
}
