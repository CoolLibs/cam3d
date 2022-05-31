## Backend-independent

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

}
```

## Decouple data and controller.

## Add optional ImGui support

## The projection matrix is not part of the Camera

Only the intrinsic parameters are: the near and far plane, and the field of view (or focal length).

This is because the projection matrix also contains an extrinsic property: the aspect ratio of the output image. It is important that we don't incorparate that extrinsic part in our definition of a Camera. For example this would mess up our comparision operator: you can have the same camera render a 16/9 image and a 3/2 image and it would still be *the same camera*.
Same for the history: if the output iamge is resized, the projection matrix changes, but the camera doesn't, so we don't want to store a change of camera in the history. Because when we woyuld undo it, the output image wouldn't change back to its original size, and so our camera would have a projection matrix with the wrong aspect ratio.
Same if we want to use the same camera to render two images with different aspect ratios: projection matrix should be computed on the fly from the the camera data and the aspect ratio, we don't want to trigger a chagne of camera that would be stored in the history each frame just because we render to two different images.