#include "viewing_ray.h"
#include <iostream>

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Matrix3d transition_matrix;
  transition_matrix << camera.u(0), camera.v(0), camera.w(0),
                       camera.u(1), camera.v(1), camera.w(1),
                       camera.u(2), camera.v(2), camera.w(2);
  
  ray.origin << transition_matrix * camera.e;

  double coefficient_u = (camera.width * ((j + 0.5)/width) - (camera.width/2.0));
  double coefficient_v = (camera.height * ((i + 0.5)/height) - (camera.height/2.0));
  double coefficient_w = camera.d;
  
  ray.direction << (transition_matrix * camera.u) * coefficient_u +
                  (transition_matrix * (-camera.v)) * coefficient_v +
                  (transition_matrix * (-camera.w)) * coefficient_w;
  ////////////////////////////////////////////////////////////////////////////
}