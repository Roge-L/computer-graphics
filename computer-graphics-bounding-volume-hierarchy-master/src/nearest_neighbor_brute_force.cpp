#include "nearest_neighbor_brute_force.h"
#include <limits>// std::numeric_limits<double>::infinity();

void nearest_neighbor_brute_force(
  const Eigen::MatrixXd & points,
  const Eigen::RowVector3d & query,
  int & I,
  double & sqrD)
{
  ////////////////////////////////////////////////////////////////////////////
  sqrD = std::numeric_limits<double>::infinity();
  for (int i = 0; i < points.rows(); i++) {
    if ((pow(points(i, 0) - query(0), 2) 
            + pow(points(i, 1) - query(1), 2) 
            + pow(points(i, 2) - query(2), 2)
            * 1.0)
            < sqrD) {
      sqrD = (pow(points(i, 0) - query(0), 2) 
                  + pow(points(i, 1) - query(1), 2) 
                  + pow(points(i, 2) - query(2), 2)
                  * 1.0);
      I = i;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
