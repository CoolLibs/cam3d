#pragma once

#include <variant>
#include "BackendFunctions.hpp"
#include "Projection_Orthographic.hpp"
#include "Projection_Perspective.hpp"

namespace cam3d {

using Projection = std::variant<Projection_Perspective,
                                Projection_Orthographic>;

inline auto projection_matrix(const Projection& proj, float aspect_ratio) -> Matrix4
{
    std::visit([](auto&& proj) { return matrix(proj, aspect_ratio); }, proj);
}

inline auto inverse_projection_matrix(const Projection& proj, float aspect_ratio) -> Matrix4
{
    return inverse(projection_matrix(proj, aspect_ratio));
}

} // namespace cam3d
