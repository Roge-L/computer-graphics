#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <iostream>

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  double r, g, b, h, s, v;
  int index;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      index = 3 * ((width * i) + j);
      r = rgb[index];
      g = rgb[index + 1];
      b = rgb[index + 2];
      h, s, v = 0;

      rgb_to_hsv(r, g, b, h, s, v);
      
      double to_minus = factor*s;
      s = s - to_minus;

      hsv_to_rgb(h, s, v, r, g, b);

      desaturated.at(index) = r;
      desaturated.at(index + 1) = g;
      desaturated.at(index + 2) = b;
    }
  }
  // int counter = 0;
  // for (int i = 0; i < desaturated.size(); i += 3) {
  //   r = rgb[i];
  //   g = rgb[i + 1];
  //   b = rgb[i + 2];
  //   h, s, v = 0;
  //   rgb_to_hsv(r, g, b, h, s, v);

  //   double to_minus = factor*s;
  //   s = s - to_minus;
  //   hsv_to_rgb(h, s, v, r, g, b);
  //   desaturated.at(i) = r;
  //   desaturated.at(i + 1) = g;
  //   desaturated.at(i + 2) = b;
  //   counter += 3;
  // }
  ////////////////////////////////////////////////////////////////////////////
}
