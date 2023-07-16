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

    // ====================================================================== //
    // positions

    using ContinuousPosition_t = std::tuple<double, double, std::optional<double>>;
    constexpr ContinuousPosition_t POSITION_ORIGIN_CONTINUOUS = {0, 0, std::optional<double>()};

    using GridDimension_t = std::pair<size_t, size_t>;
    constexpr GridDimension_t POSITION_ORIGIN_GRID= {0, 0};

}
#endif // TYPES_H
