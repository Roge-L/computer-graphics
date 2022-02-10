#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <iostream>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  double a = (ray.direction.transpose()) * (ray.direction);

  double b = ((2.0 * ray.direction).transpose()) * ((ray.origin - Sphere::center));

  double c = ((ray.origin - Sphere::center).transpose() * (ray.origin - Sphere::center)) - pow(Sphere::radius, 2);

  double discriminant = pow(b, 2) - (4.0 * a * c);

  if (discriminant < 0) {
    return false;
  } else {
    double root1 = (-b + sqrt(discriminant)) / (2.0*a);
    double root2 = (-b - sqrt(discriminant)) / (2.0*a);

    // Flag variables indicating which roots are >= min_t
    bool r1, r2 = false;
    if (root1 >= min_t) {
      r1 = true;
    }
    if (root2 >= min_t) {
      r2 = true;
    }

    // Both roots are <= min_t
    if ((!r1) && (!r2)) {
      return false;
    }

    // Both roots are >= min_t
    if (r1 && r2) {
      t = std::min(root1, root2);

      // Only root1 is >= min_t
    } else if (r1 && (!r2)) {
      t = root1;

      // Only root2 is >= min_t
    } else {
      t = root2;
    }

    n = (ray.origin + (t*ray.direction) - Sphere::center)/Sphere::radius;
    return true;
  }

  // if (discriminant == 0)
  // {
  //   double root = (-b)/(2.0*a);
  //   if (root >= min_t) {
  //     t = root;

  //     n = (ray.origin + (t*ray.direction) - Sphere::center)/Sphere::radius;

  //     return true;
  //   }
  // } else if (discriminant > 0) {
  //   double root1 = (-b + sqrt(discriminant)) / (2.0*a);
  //   double root2 = (-b - sqrt(discriminant)) / (2.0*a);
  //   if (root1 < root2 && root1 >= min_t) {
  //     t = root1;

  //     n = (ray.origin + (t*ray.direction) - Sphere::center)/Sphere::radius;

  //     return true;
  //   } else if (root2 < root1 && root2 >= min_t) {
  //     t = root2;

  //     n = (ray.origin + (t*ray.direction) - Sphere::center)/Sphere::radius;

  //     return true;
  //   }
  // }
  
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

