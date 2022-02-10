#include "rgb_to_gray.h"
#include <iostream>

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < gray.size(); i++) {
    gray.at(i) = 0.299*rgb[3*i] + 0.587*rgb[3*i + 1] + 0.114*rgb[3*i + 2];
  }
  ////////////////////////////////////////////////////////////////////////////
}