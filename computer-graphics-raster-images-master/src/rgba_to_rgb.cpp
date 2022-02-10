#include "rgba_to_rgb.h"
#include <iostream>

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Append rgba values to rgb while skipping over alpha values
  int counter = 0;
  for (int i = 0; i < rgba.size(); i++) {
    if ((i + 1) % 4 != 0) {
      rgb.at(counter) = rgba[i];
      counter = counter + 1;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
