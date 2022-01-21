#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    Hit intersection;
    intersection.object = NULL;

    vec3 sphereRay = ray.endpoint - center;

    /*
    a = u.u
    b = 2 * (e-c).u
    c - f(x) = (x-c).(x-c) - r^2 = 0
    */
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(sphereRay, ray.direction);
    double c = dot(sphereRay, sphereRay) - (radius * radius);

    double discriminant = (b * b) - ( 4 * a* c);

    /*
    When the discriminant is 0, that means there is no real solution.
    Graphically, the ray never intersects.
    When the discriminant is equal to 0, that means there is one real solution.
    Graphically, the ray touches the sphere as a tangent, but we treat this
    as no solution in a raytracer.
    When the discriminant is greater than 0, there are two solutions.
    Graphically, the ray intersects the sphere, thus two intersection points.
    */
    if(discriminant <= 0){
        return intersection;
    }
    else{
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);

        if(t2 >= small_t && t1 >= small_t){
            intersection.object = this;
            if(t1 > t2){
                intersection.dist = t2;
            }
            else{
                intersection.dist = t1;
            }
        }

        else if(t1 < small_t && t2 >= small_t){
            intersection.object = this;
            intersection.dist = t2;
        }
        
        else if(t2 <small_t && t1 >= small_t){
            intersection.object = this;
            intersection.dist = t1;
        }
    }

    return intersection;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
