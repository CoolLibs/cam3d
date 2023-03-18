#pragma once

#include "BackendFunctions.hpp"
#include "BackendTypes.hpp"
#include "Projection.hpp"
#include "View.hpp"

namespace cam3d {

struct Camera {
    View       view{};
    Projection projection{Projection_Perspective{}};
};

inline auto view_projection_matrix(const Camera& camera, float aspect_ratio) -> Matrix4
{
    return projection_matrix(camera.projection, aspect_ratio)
           * view_matrix(camera.view);
}

inline auto inverse_view_projection_matrix(const Camera& camera, float aspect_ratio) -> Matrix4
{
    return inverse_view_matrix(camera.view)
           * inverse_projection_matrix(camera.projection, aspect_ratio);
}

} // namespace cam3d
