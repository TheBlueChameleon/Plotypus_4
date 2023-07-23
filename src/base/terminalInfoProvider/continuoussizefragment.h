#ifndef REALSIZEFRAGMENT_H
#define REALSIZEFRAGMENT_H

#include "../../interface/groupedProperties/fragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class ContinuousSizeFragment : public Fragment
        {
            protected:
                std::optional<ContinuousCoordinate_t> size;
                std::optional<LengthUnit>             unit;

            public:
                ContinuousSizeFragment() = default;

                std::optional<ContinuousCoordinate_t> getSize() const;
                void setSize(const double width, const double height);
                void setSize(ContinuousCoordinate_t newSize);
                void clearSize();

                std::optional<LengthUnit> getSizeUnit() const;
                void setSizeUnit(LengthUnit newUnit);
                void clearSizeUnit();

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}


#endif // REALSIZEFRAGMENT_H
