#pragma once
#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <cmath> // For sqrt

class Vector3f {
public:
    float x, y, z;

    // Constructor
    Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);

    // Vector addition
    Vector3f operator+(Vector3f& v);

    // Vector subtraction
    Vector3f operator-(Vector3f& v);

    // Scalar multiplication
    Vector3f operator*(float n);

    // Scalar division
    Vector3f operator/(float n);

    // Unit vector
    Vector3f unit();

    // Cross product
    Vector3f cross(Vector3f v);
};

#endif // VECTOR3F_H
