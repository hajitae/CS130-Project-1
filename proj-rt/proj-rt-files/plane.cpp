#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
    Hit intersection;
    intersection.object = NULL;

    /*
    t = ((p-e).n) / (u.n)
    If t is greater than 0, then there is an intersection.
    If t is equal to 0, then the ray never touches plane.
    If t is equal to infinity, then the ray never leaves.
    */
    vec3 x = x1 - ray.endpoint;
    double num = dot(x, normal);
    double denom = dot(ray.direction, normal);

    if(denom != 0){
        double t = num / denom;
        
        if(t > 0){
            intersection.object = this;
            intersection.dist = t;
            intersection.part = part;
        }
    }

    return intersection;
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}
