#pragma once

#include <imgui/imgui.h>
#include "Data/Projection.hpp"

namespace cam3d {

auto imgui(Projection_Perspective& proj) -> bool
{
    auto b = false;
    b |= ImGui::SliderAngle("Field of View", &proj.field_of_view_in_radians, 0.001f, 180.f);
    b |= ImGui::SliderFloat("Near Plane", &proj.near_plane, 0.001f, 1.f);
    b |= ImGui::SliderFloat("Far Plane", &proj.far_plane, proj.near_plane + 0.001f, 500.f);
    return b;
}

auto imgui(Projection_Orthographic& proj) -> bool
{
    auto b = false;
    b |= ImGui::SliderFloat("Zoom", &proj.zoom, 0.001f, 10.f);
    return b;
}

auto imgui(Projection& proj) -> bool
{
    auto b = false;
    // TODO combo to choose between perspective and orthographic
    b |= std::visit([](auto&& proj) { return imgui(proj) }, proj);
    return b;
}

} // namespace cam3d
