#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  int counter = 0;
  for (int i = 0; i < rgb.size(); i += 3) {
    int row;
    int col;
    // Case 1: Top-right corners
    // Case 2: Top-left corner
    // Case 3: Bottom-left corner
    // Case 4: Bottom-right corner
    // Case 5: Top row
    // Case 6: Left column
    // Case 7: Right column
    // Case 8: Bottom row
  }
  ////////////////////////////////////////////////////////////////////////////
}
