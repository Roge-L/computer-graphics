#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  int chroma = v * s;
  double h_prime = h / 60;
  double x = chroma * (1 - (fabs(fmod(h_prime, 2) - 1)));
  
  if (h_prime >= 0 && h_prime < 1) {
    r = chroma;
    g = x;
    b = 0;
  } else if (h_prime >= 1 && h_prime < 2) {
    r = x;
    g = chroma;
    b = 0; 
  } else if (h_prime >= 2 && h_prime < 3) {
    r = 0;
    g = chroma;
    b = x; 
  } else if (h_prime >= 3 && h_prime < 4) {
    r = 0;
    g = x;
    b = chroma; 
  } else if (h_prime >= 4 && h_prime < 5) {
    r = x;
    g = 0;
    b = chroma; 
  } else if (h_prime >= 5 && h_prime < 6) {
    r = chroma;
    g = 0;
    b = x; 
  }

  r = r + (v - chroma);
  g = g + (v - chroma);
  b = b + (v - chroma);
  ////////////////////////////////////////////////////////////////////////////
}
