#include "ray_intersect_triangle.h"
#include <Eigen/Geometry>

bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////
  // Moller Trumbore Algorithm

  // Calculations of required terms
  Eigen::Vector3d e1 = B.transpose() - A.transpose();
  Eigen::Vector3d e2 = C.transpose() - A.transpose();
  Eigen::Vector3d s = ray.origin - A.transpose();
  Eigen::Vector3d s1 = ray.direction.cross(e2);
  Eigen::Vector3d s2 = s.cross(e1);

  // Vector of coresponding dot products
  Eigen::Vector3d dot_prods;
  dot_prods << s2.dot(e2), s1.dot(s), s2.dot(ray.direction);

  // The final barycentric coordinates
  Eigen::Vector3d coordinates;
  coordinates << (1.0/(s1.dot(e1))) * (dot_prods);

  // Checking if ray hit triangle
  if (coordinates(1) >= 0 && coordinates(2) >= 0 && (coordinates(1) + coordinates(2)) <= 1) {
    if (coordinates(0) >= min_t) {
      t = coordinates(0);


      Eigen::Vector3d vec1 = B.transpose() - A.transpose();
      Eigen::Vector3d vec2 = C.transpose() - A.transpose();
      Eigen::Vector3d n = (vec1).cross(vec2);
      n = n.normalized();
      return true;
    }
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}

