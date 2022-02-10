#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>
#include <math.h>

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  ////////////////////////////////////////////////////////////////////////////
  // Ambient shading is when we add a constant component, where is the 
  // surface's ambient coefficient, or "ambient color," and is the ambient
  // light intensity, to the shading model.
  double ia = 0.1;
  Eigen::Vector3d rgb = objects.at(hit_id)->material->ka * ia;

  // The point where the ray hits the object
  Eigen::Vector3d q = ray.origin + (t * ray.direction);

  for (int i = 0; i < lights.size(); i++) {

    // Parametric distance from q along d to light
    double max_t;

    // 3D direction from point towards light as a vector
    Eigen::Vector3d d;

    // Set the direction toward the light
    lights.at(i)->direction(q, d, max_t);

    // Vector from the ray-object intersection point to the light
    Ray l;
    l.origin = q;
    l.direction = d;

    // Information about the ray-object intersection point to the 
    // light
    int l_hit_id;
    double l_t;
    Eigen::Vector3d l_n;

    // Check if the vector from the object hit point to the light is
    // blocked by some object
    if (!first_hit(l, 0.00001, objects, l_hit_id, l_t, l_n)) {
      
      // Clear path towards the light, now compute the half vector
      Eigen::Vector3d h = ((ray.origin + t * (ray.direction.normalized())).normalized() + l.direction.normalized()).normalized();

      // Light intensity
      Eigen::Vector3d I = lights.at(i)->I;

      // Add diffuse component
      double ndotl = n.dot(l.direction);
      rgb += (objects.at(hit_id)->material->kd.array() 
              * I.array()).matrix() 
              * std::max(0.0, ndotl);

      // Add specular component
      double ndoth = n.dot(h);
      rgb += (objects.at(hit_id)->material->ks.array() 
              * I.array()).matrix() 
              * pow(std::max(0.0, ndoth), objects.at(hit_id)->material->phong_exponent);
    }
  }
  
  return rgb;
  ////////////////////////////////////////////////////////////////////////////
}
