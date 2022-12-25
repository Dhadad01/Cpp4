//
// Created by naqni on 19/12/2022.
//
#include "Dense.h"
Dense::Dense(const Matrix& weights,const Matrix& bias,activation_f
ActivationFunction){
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
Matrix Dense::operator()(const Matrix &matrix)
{
  Matrix mat =  _ActivationFunction( _weights*matrix+_bias);
  return mat;
}