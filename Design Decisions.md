##

Implement Camera library independently of glm : you have to write bindings to implement functions like transpose of a matrix.

And `using vec3 = glm::vec3`

```cpp
namespace c3d /*CamBackend*/ {

using Scalar = float;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;
using Mat3 = glm::mat3;
using Mat4 = glm::mat4;

Mat4 transpose(const Mat4& m)
{
    return glm::transpose(m);
}

Vec3 x_axis(const Mat4& m)
{
    return glm::column(0, m); // NB: for the backends that use row-major matrices instead of column-major, you will want to return the first row, not the first column !
}

Vec3 world_up_axis() {

}

struct Ray { // You can choose how your ray is represented

};

Ray make_ray(Vec3 pos, Vec3 dir)
{

}

Decouple data and controller.

Add optional ImGui support

}
```