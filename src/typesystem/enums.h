#ifndef ENUMS_H
#define ENUMS_H

namespace Plotypus
{
    enum class FileType
    {
        Ascii,
        Gif,
        Jpeg,
        LaTeX,
        Pdf,
        Png,
        PostScript,
        Screen,

        Custom
    };

    // ---------------------------------------------------------------------- //

    enum class LengthUnit
    {
        Inch,
        Centimeter,
    };

    enum class LineEnds
    {
        Default,
        Rounded,
        Butt,
        Square
    };

    //! @todo add more formats
    enum class PaperFormats
    {
        A4_Portrait,
        A4_Landscape,
    };

    // ---------------------------------------------------------------------- //

    enum class HorizontalAlignment
    {
        Default,
        Left,
        Center,
        Right,
    };

    enum class VerticalAlignment
    {
        Default,
        Bottom,
        Center,
        Top
    };
}

#endif // ENUMS_H
