#include "IntersectionAux.h"


////////////////////////////////////////////////////////////////////////////////
// 
// 2D Line Segment Intersection example
// Implementation of the theory provided by Paul Bourke
// 
// Written by Damian Coventry (Altered by Joao Cabo to fit implementation)
// Tuesday, 9 January 2007
// 
////////////////////////////////////////////////////////////////////////////////




void IntersectionAux::DoLineSegmentIntersection(const vec3 p0, const vec3 p1, const vec3 p2, const vec3 p3, vec3 *intersectPoint){
    LineSegment linesegment0(p0, p1);
    LineSegment linesegment1(p2, p3);

    vec3 intersection = vec3(0);
    // REMOVE comment
    
    
    std::cout << "Line Segment 0: (" << p0.x << ", " << p0.z << ") to (" << p1.x << ", " << p1.z << ")\n"
        << "Line Segment 1: (" << p2.x << ", " << p2.z << ") to (" << p3.x << ", " << p3.z << ")\n";
    
    

    switch (linesegment0.Intersect(linesegment1, intersection))
    {
    case LineSegment::PARALLEL:
        intersectPoint->x = intersection.x;
        intersectPoint->y = 0.0;
        intersectPoint->z = intersection.z;
       // std::cout << "The lines are parallel\n\n";
        break;
    case LineSegment::COINCIDENT:
        intersectPoint->x = intersection.x;
        intersectPoint->y = 0.0;
        intersectPoint->z = intersection.z;
        //std::cout << "The lines are coincident\n\n";
        break;
    case LineSegment::NOT_INTERESECTING:
        intersectPoint->x = intersection.x;
        intersectPoint->y = 0.0;
        intersectPoint->z = intersection.z;
        //std::cout << "The lines do not intersect\n\n";
        break;
    case LineSegment::INTERESECTING:
        intersectPoint->x = intersection.x;
        intersectPoint->y = 0.0;
        intersectPoint->z = intersection.z;
        // REMOVE comment
        std::cout << "The lines intersect at (" << intersection.x << ", " << intersection.z << ")\n\n";
        break;
    }
}
