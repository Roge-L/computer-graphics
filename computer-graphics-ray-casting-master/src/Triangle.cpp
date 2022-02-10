#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>
#include <Eigen/Core>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d a = std::get<0>(Triangle::corners);
  Eigen::Vector3d b = std::get<1>(Triangle::corners);
  Eigen::Vector3d c = std::get<2>(Triangle::corners);

  Eigen::Vector3d e1 = b - a;
  Eigen::Vector3d e2 = c - a;
  Eigen::Vector3d s = ray.origin - a;
  Eigen::Vector3d s1 = ray.direction.cross(e2);
  Eigen::Vector3d s2 = s.cross(e1);

  Eigen::Vector3d temp;
  temp << s2.dot(e2), s1.dot(s), s2.dot(ray.direction);

  Eigen::Vector3d unknowns;
  unknowns << (1.0/(s1.dot(e1))) * (temp);

  if (unknowns(1) >= 0 && unknowns(2) >= 0 && (unknowns(1) + unknowns(2)) <= 1) {
    if (unknowns(0) >= min_t) {
      t = unknowns(0);


      Eigen::Vector3d vec1 = b - a;
      Eigen::Vector3d vec2 = c - a;
      n = (vec1).cross(vec2);
      n = n.normalized();
      return true;
    }
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}


