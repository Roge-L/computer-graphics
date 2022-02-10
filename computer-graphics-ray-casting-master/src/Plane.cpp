#include "Plane.h"
#include "Ray.h"
#include <iostream>

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // double tval = ((Plane::point - ray.origin).dot(Plane::normal)) / (ray.direction.dot(Plane::normal));
  double q = Plane::normal.transpose().dot(Plane::point);
  double tval = (q - (Plane::normal.transpose().dot(ray.origin))) 
                / (Plane::normal.transpose().dot(ray.direction));

  if (tval < min_t) {
    return false;
  }

  t = tval;
  n = Plane::normal.normalized();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

