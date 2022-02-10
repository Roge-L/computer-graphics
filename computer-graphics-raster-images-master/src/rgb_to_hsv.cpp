#include "rgb_to_hsv.h"
#include <cmath>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  int min_rgb = 0;
  int chroma = 0;

  if((r <= g) && (r <= b)) {
    min_rgb = r;
  }
  else if ((g <= r) && (g <= b)) {
    min_rgb = g;
  }
  else {
    min_rgb = b;
  }

  if((r >= g) && (r >= b)) {
    v = r;
  }
  else if ((g >= r) && (g >= b)) {
    v = g;
  }
  else {
    v = b;
  }

  chroma = v - min_rgb;

  if (chroma == 0) {
    h = 0;
  } else if (v == r) {
    h = 60 * (0 + ((g - b) / chroma));
  } else if (v == g) {
    h = 60 * (2 + ((b - r) / chroma));
  } else {
    h = 60 * (4 + ((r - g) / chroma));
  }

  if (v == 0) {
    s = 0;
  } else {
    s = chroma / v;
  }
  ////////////////////////////////////////////////////////////////////////////
}
