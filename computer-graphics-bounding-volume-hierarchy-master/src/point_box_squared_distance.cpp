#include "point_box_squared_distance.h"

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////
  double sqrD = 0.0;
  for (int i = 0; i < 3; i++) {
    if (query(i) < box.min_corner(i)) {
      sqrD += pow(box.min_corner(i) - query(i), 2);
    } else if (query(i) > box.max_corner(i)) {
      sqrD += pow(box.max_corner(i) - query(i), 2);
    }
  }
  return sqrD;
  ////////////////////////////////////////////////////////////////////////////
}
