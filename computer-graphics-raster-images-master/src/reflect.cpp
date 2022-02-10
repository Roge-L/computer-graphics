#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  int counter = 0;
  for (int i = 0; i < height; i++) {
    for (int j = width - 1; j >= 0; j--) {
      for (int k = 0; k < num_channels; k++) {
        reflected.at(counter) = input[(i*width*num_channels) + (j*num_channels) + k];
        counter = counter + 1;
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
