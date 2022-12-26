//
// Created by naqni on 19/12/2022.
//
#include "Dense.h"
#include "Matrix.h"
Dense::Dense(const Matrix& weights,const Matrix& bias,activation_f
ActivationFunction){
  if(bias.get_cols() != 1||bias.get_rows()!=weights.get_rows()){
    throw std::domain_error("dimension error");
  }
  _weights = weights;
  _bias = bias;
  _ActivationFunction = ActivationFunction;
}

 Matrix Dense::get_weights () const
{
  return _weights;
}
Matrix Dense::get_bias () const
{
  return _bias;
}
activation_f Dense::get_activation () const
{
  return _ActivationFunction;
}
Matrix Dense::operator()(const Matrix &matrix) const
{
  Matrix mat =  _ActivationFunction( _weights*matrix+_bias);
  return mat;
}