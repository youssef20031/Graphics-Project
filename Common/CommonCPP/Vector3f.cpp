#include "../CommonH/Vector3f.h"


// Vector3f class constructor and methods
Vector3f::Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

// Vector addition
Vector3f Vector3f::operator+(Vector3f& v) {
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

// Vector subtraction
Vector3f Vector3f::operator-(Vector3f& v) {
	return Vector3f(x - v.x, y - v.y, z - v.z);
}

// Scalar multiplication
Vector3f Vector3f::operator*(float n) {
	return Vector3f(x * n, y * n, z * n);
}

// Scalar division
Vector3f Vector3f::operator/(float n) {
	return Vector3f(x / n, y / n, z / n);
}

// Unit vector
Vector3f Vector3f::unit() {
	return *this / sqrt(x * x + y * y + z * z);
}

// Cross product
Vector3f Vector3f::cross(Vector3f v) {
	return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
