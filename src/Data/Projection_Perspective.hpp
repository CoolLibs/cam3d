#pragma once

namespace cam3d {

struct Projection_Perspective {
    float field_of_view_in_radians = 1.570796327f; // == TAU / 4
    float near_plane               = 0.1f;
    float far_plane                = 200.f;
};

} // namespace cam3d
