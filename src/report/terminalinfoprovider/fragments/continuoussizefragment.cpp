#include "continuoussizefragment.h"
#include <iostream>

namespace Plotypus
{
    namespace TerminalInfo
    {
        std::optional<ContinuousCoordinate_t> ContinuousSizeFragment::getSize() const
        {
            return size;
        }

        void ContinuousSizeFragment::setSize(const double width, const double height)
        {
            setSize(std::make_pair(width, height));
        }

        void ContinuousSizeFragment::setSize(ContinuousCoordinate_t newSize)
        {
            if (newSize.first <= 0)
            {
                throw InvalidArgumentError("Attempted to set non-positive width");
            }

            if (newSize.second <= 0)
            {
                throw InvalidArgumentError("Attempted to set non-positive height");
            }

            size = newSize;
        }

        void ContinuousSizeFragment::clearSize()
        {
            size.reset();
        }


        std::optional<LengthUnit> ContinuousSizeFragment::getSizeUnit() const
        {
            return unit;
        }

        void ContinuousSizeFragment::setSizeUnit(LengthUnit newUnit)
        {
            unit = newUnit;
        }

        void ContinuousSizeFragment::clearSizeUnit()
        {
            unit.reset();
        }

        void ContinuousSizeFragment::reset()
        {
            size.reset();
            unit = LengthUnit::Default;
        }

        void ContinuousSizeFragment::writeScriptFragment(std::ostream& hFile) const
        {
            if(size.has_value())
            {
                ContinuousCoordinate_t sizeValue = size.value();

                std::string unitString;
                switch (unit.value_or(Plotypus::LengthUnit::Default))
                {
                    case Plotypus::LengthUnit::Default:
                        unitString = "";
                        break;
                    case Plotypus::LengthUnit::Centimeter:
                        unitString = "cm";
                        break;
                    case Plotypus::LengthUnit::Inch:
                        unitString = "in";
                        break;
                }

                hFile << "size "
                      << std::to_string(sizeValue.first) << unitString << ","
                      << std::to_string(sizeValue.second) << unitString << " ";
            }
        }
    }
}
