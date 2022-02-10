#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  double r, g, b, h, s, v = 0;
  int counter = 0;
  for (int i = 0; i < shifted.size(); i += 3) {
    rgb_to_hsv(rgb[i], rgb[i + 1], rgb[i + 2], h, s, v);
    h += shift;
    if (h >= 360) {
      h -= 360;
    } else if (h <= 0) {
      h = 360 + h;
    }
    hsv_to_rgb(h, s, v, r, g, b);
    shifted.at(counter) = r;
    shifted.at(counter + 1) = g;
    shifted.at(counter + 2) = b;
    counter += 3;
    r, g, b, h, s, v = 0;
  }
  ////////////////////////////////////////////////////////////////////////////
}
