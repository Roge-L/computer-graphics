#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"
#include <limits>

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////
  double curr_tval = std::numeric_limits<double>::infinity();  

  hit_f = -1;
  for (int i = 0; i < F.rows(); i++) {
    if (ray_intersect_triangle(ray, 
                               V.row(F.row(i)(0)), 
                               V.row(F.row(i)(1)), 
                               V.row(F.row(i)(2)),
                               min_t,
                               max_t,
                               hit_t)) {
      if (hit_t < curr_tval) {
        curr_tval = hit_t;
        hit_f = i;
      }
    }
  }
  
  if (hit_f == -1) {  
    return false;  
  }
  hit_t = curr_tval;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
