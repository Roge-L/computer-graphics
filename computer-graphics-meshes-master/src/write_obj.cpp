#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  std::ofstream myfile(filename);  
  if (myfile.is_open()) {  
      
    for (int i = 0; i < V.rows(); i++) {  
      myfile << "v " << V.row(i) << std::endl;  
    }  
  
    for (int i = 0; i < UV.rows(); i++) {  
      myfile << "vt " << UV.row(i) << std::endl;  
    }  
  
    for (int i = 0; i < NV.rows(); i++) {  
      myfile << "vn " << NV.row(i) << std::endl;  
    }  
  
    for (int i = 0; i < F.rows(); i++) {  
      myfile << "f";  
      for (int j = 0; j < F.cols(); j++) {  
        myfile << " " << F(i, j) << "/" << UF(i, j) << "/" << NF(i, j);  
      }  
      myfile << std::endl;  
    }  
  
    myfile.close();  
  }  
  ////////////////////////////////////////////////////////////////////////////  
  return false;  

}
