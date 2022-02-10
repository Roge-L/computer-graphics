#include "first_hit.h"
#include <limits>
#include <iostream>

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  double curr_tval = std::numeric_limits<double>::max();
  Eigen::Vector3d curr_normal;
  int index = -1;
  for (int i = 0; i < objects.size(); i++) {
    if (objects.at(i)->intersect(ray, min_t, t, n)) {
      if (t < curr_tval) {
        curr_tval = t;
        curr_normal << n(0), n(1), n(2);
        index = i;
      }
    }
  }

  if (index == -1) {
    return false;
  }

  t = curr_tval;
  n = curr_normal;
  hit_id = index;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

