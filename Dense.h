#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"
#include "Matrix.h"

// Insert Dense class here...
class Dense{
 private:
  Matrix _weights;
  Matrix _bias;
  activation_f _ActivationFunction;
 public:
  Dense(const Matrix& weights,const Matrix& bias,
        activation_f ActivationFunction);
  Matrix get_weights () const;
  Matrix get_bias () const;
  activation_f get_activation_function () const;
  Matrix operator()(const Matrix &matrix);
};

#endif //DENSE_H
