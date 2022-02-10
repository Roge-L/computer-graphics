#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  int alpha_o, alpha_a, alpha_b = 0;
  int counter = 0;
  for (int i = 0; i < C.size(); i += 4) {
    alpha_a = A[i + 3];
    alpha_b = B[i + 3];
    alpha_o = alpha_a + (alpha_b * (1 - alpha_a));

    C.at(counter) = ((A[i]*alpha_a) + (B[i]*alpha_b*(1 - alpha_a))) / alpha_o;
    C.at(counter + 1) = ((A[i + 1]*alpha_a) + (B[i + 1]*alpha_b*(1 - alpha_a))) / alpha_o;
    C.at(counter + 2) = ((A[i + 2]*alpha_a) + (B[i + 2]*alpha_b*(1 - alpha_a))) / alpha_o;
    C.at(counter + 3) = alpha_o;
    counter += 4;
  }
  ////////////////////////////////////////////////////////////////////////////
}
