//
// Created by naqni on 19/12/2022.
//
#include "Matrix.h"
#include "Activation.h"
#include "cmath"
Matrix activation::relu (const Matrix &matrix)
{
  Matrix new_mat = matrix;
  for(int i=0;i<matrix.dim.rows;i++){
    for(int j=0;j<matrix.dim.cols;j++){
      if(new_mat._mat[i][j]<0){
        new_mat._mat[i][j] = 0;
      }
    }
  }
  return new_mat;
}
Matrix activation::softmax (const Matrix &matrix)
{
  Matrix new_mat = matrix;
  for(int i=0;i<matrix.dim.rows;i++){
    for(int j=0;j<matrix.dim.cols;j++){
      //TODO - figure out what wrong with new_mat(i,j) =
      // std::exp(new_mat._mat[i][j])
      new_mat._mat[i][j] = std::exp(new_mat._mat[i][j]);
    }
  }
  (1/new_mat.sum())*new_mat;
  return new_mat;
}
