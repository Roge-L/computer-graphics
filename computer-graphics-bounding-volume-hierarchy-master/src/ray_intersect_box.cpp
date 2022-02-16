#include "ray_intersect_box.h"
#include <iostream>
#include <limits>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////
  double t_xyzmin, t_xyzmax, xyz_min, xyz_max, xyz_d, xyz_e;
  double t_min = -std::numeric_limits<double>::infinity();
  double t_max = std::numeric_limits<double>::infinity();

  for (int i = 0; i < 3; i++) {
    
    xyz_min = box.min_corner(i);
    xyz_max = box.max_corner(i);
    xyz_d = ray.direction(0, i);
    xyz_e = ray.origin(0, i);

    // Preventing the case that xyz_d = -0 per textbook
    // by multiple by the reciprocal instead of dividing
    // Additionally, case of xyz_d = 0 is covered
    // by IEEE floating point conventions.
    double a = 1.0 / xyz_d;
    if (xyz_d >= 0) {
      t_xyzmin = (xyz_min - xyz_e) * a;
      t_xyzmax = (xyz_max - xyz_e) * a;

    } else {
      t_xyzmin = (xyz_max - xyz_e) * a;
      t_xyzmax = (xyz_min - xyz_e) * a;
    }


    if (t_xyzmin >= t_min) {
      t_min = t_xyzmin;
    }


    if (t_xyzmax <= t_max) {
      t_max = t_xyzmax;
    }
    
  }

  // For intution, think of t for time and which planes are hit
  // as a function of time
  if (t_max < t_min) {
    return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}
