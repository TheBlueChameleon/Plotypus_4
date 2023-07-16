#ifndef TERMINALINFOPROVIDER_H
#define TERMINALINFOPROVIDER_H

#include <filesystem>
#include <variant>

#include "../interface/scriptable.h"

namespace Plotypus
{
    class TerminalInfoProvider
        : public Scriptable
    {
        public:
            using dimensions_pixels_t           = GridDimension_t;
            using dimensions_length_t           = ContinuousPosition_t;
            using dimensions_length_with_unit_t = std::pair<dimensions_length_t, std::string>;
            using dimensions_t                  = std::variant<dimensions_pixels_t, dimensions_length_with_unit_t>;

            enum DimensionsTypeIndex {Pixels, Length};

        private:
            std::filesystem::path               target;

            FileType                            fileType            = FileType::Pdf;
            std::string                         terminal            = "pdfcairo";
            bool                                outputToFile        = true;

            std::optional<dimensions_t>         dimensions;
            std::optional<dimensions_pixels_t>  position;

        public:
            TerminalInfoProvider(const FileType filetype);

            TerminalInfoProvider& reset();

            // Scriptable interface
            bool validateScript();
            void writeScript(std::ostream& hFile);
    };
}

#endif // TERMINALINFOPROVIDER_H
