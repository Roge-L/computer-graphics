#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  int counter = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0) {
          bayer.at(counter) = rgb[(i*width*3) + (j*3) + 1];
        } else {
          bayer.at(counter) = rgb[(i*width*3) + (j*3) + 2];
        }
      } else {
        if (j % 2 == 0) {
          bayer.at(counter) = rgb[(i*width*3) + (j*3)];
        } else {
          bayer.at(counter) = rgb[(i*width*3) + (j*3) + 1];
        }
      }
      counter += 1;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
