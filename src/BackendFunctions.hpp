#pragma once

#include <glm/glm.hpp>
#include "Projection.hpp"

namespace cam3d {

using Matrix4 = glm::mat4;
using Vec3    = glm::vec3;

auto matrix(const Projection_Perspective& proj, float aspect_ratio) -> Matrix4
{
    return glm::perspective(proj.field_of_view_in_radians,
                            aspect_ratio,
                            proj.near_plane,
                            proj.far_plane);
}

auto matrix(const Projection_Orthographic& proj, float aspect_ratio) -> Matrix4
{
    return glm::mat4{1.f}; // TODO glm::orthographic();
}

auto inverse(const Matrix4& matrix) -> Matrix4
{
    return glm::inverse(matrix);
}

auto world_up_axis() -> Vec3
{
    return Vec3{0.f, 0.f, 1.f};
}

} // namespace cam3d
