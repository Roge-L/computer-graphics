#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  ////Hint:  
  V.resize(8,3);  
  F.resize(6,4);  
  UV.resize(14,2);  
  UF.resize(6,4);  
  NV.resize(6,3);  
  NF.resize(6,4);  
  
  V << 0, 0, 0,  
       0, 0, 1,  
       0, 1, 0,  
       0, 1, 1,  
       1, 0, 0,  
       1, 0, 1,  
       1, 1, 0,  
       1, 1, 1;  
    
  // 1-based indexing  
  F << 1, 5, 6, 2, // xz-plane,   
       1, 3, 4, 2, // yz-plane,   
       3, 7, 8, 4, // xz-plane shifted by y,  
       5, 7, 8, 6, // yz_plane shifted by x,  
       2, 6, 8, 4, // top,  
       1, 5, 7, 3; // bottom  
  
  NV << -1, 0, 0, // xz-plane,   
       0, -1, 0, // yz-plane,   
       1, 0, 0, // xz-plane shifted by y,  
       0, 1, 0, // yz_plane shifted by x,  
       0, 0, 1, // top,  
       0, 0, -1; // bottom  
  
  // For every face's corners, which normal do we assign it?  
  NF << 1, 1, 1, 1, // xz-plane,   
       2, 2, 2, 2, // yz-plane,   
       3, 3, 3, 3, // xz-plane shifted by y,  
       4, 4, 4, 4, // yz_plane shifted by x,  
       5, 5, 5, 5, // top,  
       6, 6, 6, 6; // bottom  
  
  // These are the coords of the vertices of the texture map  
  // Note: going left-right bottom-up  
  UV << 0.25, 0,  
        0.5 , 0,  
        0   , 0.25,  
        0.25, 0.25,  
        0.5 , 0.25,  
        0.75, 0.25,  
        1   , 0.25,  
        0   , 0.5,  
        0.25, 0.5,  
        0.5 , 0.5,  
        0.75, 0.5,  
        1   , 0.5,  
        0.25, 0.75,  
        0.5 , 0.75;  
  
  UF << 1, 2, 4, 5,   // xz-plane,   
       3, 4, 8, 9,    // yz-plane,   
       9, 10, 13, 14, // xz-plane shifted by y,  
       5, 6, 10, 11,  // yz_plane shifted by x,  
       6, 7, 11, 12,  // top,  
       4, 5, 9, 10;   // bottom  

  ////////////////////////////////////////////////////////////////////////////
}
