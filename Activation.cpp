//
// Created by naqni on 19/12/2022.
//
#include "Matrix.h"
#include "Activation.h"
#include "cmath"
Matrix activation::relu (const Matrix &matrix)
{
  Matrix new_mat = matrix;
  for(int i=0;i<matrix.get_rows();i++){
    for(int j=0;j<matrix.get_cols();j++){
      if(new_mat(i,j)<0){
        new_mat(i,j) = 0;
      }
    }
  }
  return new_mat;
}
Matrix activation::softmax (const Matrix &matrix)
{
  Matrix new_mat = matrix;
  for(int i=0;i<matrix.get_rows();i++){
    for(int j=0;j<matrix.get_cols();j++){
      new_mat(i,j) = std::exp(new_mat(i,j));
    }
  }
  return new_mat*(1/new_mat.sum());
}
