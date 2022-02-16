#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue
#include <limits>

class comparator {
  bool operator(std::pair<double, std::shared_ptr<Object>> a
                , std::pair<double, std::shared_ptr<Object>> b) {
                  return a.first > b.first;
                }
}

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////

  sqrd = 0;
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
