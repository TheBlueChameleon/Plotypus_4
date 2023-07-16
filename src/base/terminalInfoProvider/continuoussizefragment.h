#ifndef REALSIZEFRAGMENT_H
#define REALSIZEFRAGMENT_H

#include "../../interface/fragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        class ContinuousSizeFragment : public Fragment
        {
            protected:
                std::optional<ContinuousCoordinate_t> size;
                LengthUnit                            unit;

            public:
                ContinuousSizeFragment() = default;

                std::optional<ContinuousCoordinate_t> getSize() const;
                void setSize(ContinuousCoordinate_t newSize);
                void clearSize();

                LengthUnit getUnit() const;
                void setUnit(LengthUnit newUnit);

                // Fragment interface
                void reset();
                std::string generateScriptFragment() const;
        };
    }
}


#endif // REALSIZEFRAGMENT_H
