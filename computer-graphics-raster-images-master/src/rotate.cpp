#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  int counter = 0;
  for (int i = width - 1; i >= 0; i--) {
    for (int j = 0; j < height; j++) {
      for (int k = 0; k < num_channels; k++) {
        rotated.at(counter) = input[(i*num_channels) + (j*width*num_channels) + k];
        counter = counter + 1;
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}