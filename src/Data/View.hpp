#pragma once

#include "BackendTypes.hpp"

namespace cam3d {

struct View {
    Matrix4 transform_matrix{look_at_matrix({}, {}, world_up_axis())};
};

inline auto view_matrix(const View& view) -> Matrix4
{
    return inverse(view.transform_matrix);
}

inline auto inverse_view_matrix(const View& view) -> Matrix4
{
    return transform_matrix(view);
}

inline auto transform_matrix(const View& view) -> Matrix4
{
    return view.transform_matrix;
}

} // namespace cam3d
