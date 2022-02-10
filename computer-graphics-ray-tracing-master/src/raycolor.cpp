#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  ////////////////////////////////////////////////////////////////////////////
  // Information about the vector from the origin to the object
  int hit_id;
  double t;
  Eigen::Vector3d n;

  if (first_hit(ray, min_t, objects, hit_id, t, n)) {

    // Implement Lambertian and Blinn-Phong shading models
    // to compute pixel color if we hit an object
    rgb = blinn_phong_shading(ray, hit_id, t, n, objects, lights);

    // Recurse
    if (num_recursive_calls < 5) {
      // The point where the ray hits the object
      Eigen::Vector3d q = ray.origin + (t * (ray.direction));

      // Given an "incoming" vector and a normal vector, compute 
      // the mirror reflected "outgoing" vector.
      Ray reflected_ray;
      reflected_ray.origin = q;
      reflected_ray.direction = reflect(ray.direction, n);

      // rgb vector that takes into account the reflections
      Eigen::Vector3d reflection_rgb;

      // Call raycolor
      raycolor(reflected_ray, 0.00001, objects, lights, num_recursive_calls + 1, reflection_rgb);
      
      // Incorporate the reflections
      rgb += (objects.at(hit_id)->material->km.array()
              * reflection_rgb.array()).matrix();
      return true;
    } else {
      return true;
    }
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}
