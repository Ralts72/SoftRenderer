#pragma once

#include "MyMath.h"

struct Frustum {
    Frustum(const float near, const float aspect, const float fov): near(near), aspect(aspect), fov(fov) {
        const float a = 1.0f / (near * std::tan(fov));
        mat = Mat4{
            a, 0.0f, 0.0f, 0.0f,
            0.0f, a * aspect, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, -1.0f / near, 0.0f
        };
    }

    float near;
    float aspect;
    float fov;
    Mat4 mat;
};

class Camera {
public:
    Camera(const float near, const float aspect, const float fov): m_frustum(near, aspect, fov) {}
    Frustum& getFrustum() { return m_frustum; }

private:
    Frustum m_frustum;
};
