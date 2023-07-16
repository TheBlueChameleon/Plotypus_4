#include "continuoussizefragment.h"

namespace Plotypus
{
    namespace TerminalInfo
    {
        std::optional<ContinuousCoordinate_t> ContinuousSizeFragment::getSize() const
        {
            return size;
        }

        void ContinuousSizeFragment::setSize(ContinuousCoordinate_t newSize)
        {
            size = newSize;
        }

        void ContinuousSizeFragment::clearSize()
        {
            size.reset();
        }


        LengthUnit ContinuousSizeFragment::getUnit() const
        {
            return unit;
        }

        void ContinuousSizeFragment::setUnit(LengthUnit newUnit)
        {
            unit = newUnit;
        }

        void ContinuousSizeFragment::reset()
        {
            size.reset();
            unit = LengthUnit::Default;
        }

        std::string ContinuousSizeFragment::generateScriptFragment() const
        {
            if(size.has_value())
            {
                ContinuousCoordinate_t sizeValue = size.value();

                std::string unitString;
                switch (unit)
                {
                    case Plotypus::LengthUnit::Default:
                        unitString = "";
                    case Plotypus::LengthUnit::Centimeter:
                        unitString = "cm";
                    case Plotypus::LengthUnit::Inch:
                        unitString = "in";
                }

                return "size " +
                       std::to_string(sizeValue.first) + unitString + "," +
                       std::to_string(sizeValue.second) + unitString + " ";
            }
            else
            {
                return "";
            }
        }
    }
}
