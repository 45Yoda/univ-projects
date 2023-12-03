/*

#include "Vec.h"


Vec::Vec(const float a, const float b, const float c)
{
    x = a;
    y = b;
    z = c;
}

float Vec::dst(const vec3 b, const vec3 e)
{
    float dx = e.x - b.x;
    float dy = e.y - b.y;
    float dz = e.z - b.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

float Vec::length(const vec3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

vec3 Vec::lerp(const vec3 b, const vec3 e, const float s)
{
    return b + (e - b) * s;
}

vec3 Vec::cross(const vec3 u, const vec3 v)
{
    return vec3(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
}

float Vec::angleDiff(float b, float e)
{
    while (b < 0) b += 360;
    while (e < 0) e += 360;
    while (b >= 360) b -= 360;
    while (e >= 360) e -= 360;

    float d = e - b;
    if (d > 180) d = 180 - d;
    if (d < -180) d = -180 - d;

    return d;
}

float Vec::angleXZ() const
{
    float t = atan2(z, x) * 57.2958;
    if (t >= 360) t -= 360;
    return -t;
}

void Vec::normalize()
{
    float dst = sqrt(x * x + y * y + z * z);
    x /= dst;
    y /= dst;
    z /= dst;
}
*/