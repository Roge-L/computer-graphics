#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
    
  std::ofstream ppm_file;
  ppm_file.open(filename);
  if (!ppm_file) {
    return false;
  }
  if (num_channels == 3) {
    ppm_file << "P3\n";
  } else {
    ppm_file << "P2\n";
  }
  ppm_file << width << " " << height << "\n";
  ppm_file << "255\n";

  for (int i = 0; i < data.size(); i++) {
    int val = data[i];
    ppm_file << val << " ";
  }

  ppm_file.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
