#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <glm/glm.hpp>
#include <iostream>

using namespace std;
using namespace glm;


class IntersectionAux {
public:

    struct LineSegment {
        vec3 begin_;
        vec3 end_;

        LineSegment(const vec3 begin, const vec3 end) : begin_(begin), end_(end) {}

        enum IntersectResult { PARALLEL, COINCIDENT, NOT_INTERESECTING, INTERESECTING };

        IntersectResult Intersect(const LineSegment& other_line, vec3& intersection)
        {
            float denom = ((other_line.end_.z - other_line.begin_.z) * (end_.x - begin_.x)) -
                ((other_line.end_.x - other_line.begin_.x) * (end_.z - begin_.z));

            float nume_a = ((other_line.end_.x - other_line.begin_.x) * (begin_.z - other_line.begin_.z)) -
                ((other_line.end_.z - other_line.begin_.z) * (begin_.x - other_line.begin_.x));

            float nume_b = ((end_.x - begin_.x) * (begin_.z - other_line.begin_.z)) -
                ((end_.z - begin_.z) * (begin_.x - other_line.begin_.x));

            if (denom == 0.0f)
            {
                if (nume_a == 0.0f && nume_b == 0.0f)
                {
                    intersection.x = 0;
                    intersection.z = 0;
                    return COINCIDENT;
                }
                intersection.x = 0;
                intersection.z = 0;
                return PARALLEL;
            }

            float ua = nume_a / denom;
            float ub = nume_b / denom;

            if (ua >= 0.0f && ua <= 1.0f && ub >= 0.0f && ub <= 1.0f)
            {
                // Get the intersection point.
                intersection.x = begin_.x + ua * (end_.x - begin_.x);
                intersection.z = begin_.z + ua * (end_.z - begin_.z);


                return INTERESECTING;
            }
            intersection.x = 0;
            intersection.z = 0;
            return NOT_INTERESECTING;
        }
    };

   static void DoLineSegmentIntersection(const vec3 p0, const vec3 p1, const vec3 p2, const vec3 p3, vec3* intersectPoint);

};