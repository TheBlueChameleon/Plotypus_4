#ifndef TYPES_H
#define TYPES_H

#include <tuple>
#include <optional>

namespace Plotypus
{
    // ====================================================================== //
    // selectors

    template <typename T>
    using DataSelector_t = std::function<double (const T&)>;


    template <typename T>
    using TextSelector_t = std::function<const std::string& (const T&)>;

    // ====================================================================== //
    // positions

    using ContinuousCoordinate_t = std::pair<double, double>;
    constexpr ContinuousCoordinate_t POSITION_ORIGIN_CONTINUOUS = {0.0, 0.0};

    using GridCoordinate_t = std::pair<size_t, size_t>;
    constexpr GridCoordinate_t POSITION_ORIGIN_GRID= {0, 0};

    using PlotElementCoordinate_t = std::tuple<double, double, std::optional<double>>;
}
#endif // TYPES_H
