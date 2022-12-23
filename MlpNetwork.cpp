//
// Created by naqni on 21/12/2022.
//

#include "MlpNetwork.h"
#include "Dense.h"
MlpNetwork::MlpNetwork (const Matrix *weights,const Matrix *biases) :
    dences{
        Dense(weights[0],biases[0],activation::relu),
        Dense(weights[1],biases[1],activation::relu),
        Dense(weights[2],biases[2],activation::relu),
        Dense(weights[3],biases[3],activation::softmax)
    }
{}

digit MlpNetwork::operator()(Matrix& mat)
{
  for (int i=0;i<MLP_SIZE;i++)
  {
    mat = dences[i](mat);
  }
  digit digit_1;
  digit_1.value = 0;
  digit_1.probability = mat[0];
  for (int i=1;i<mat.get_rows();i++){
    if(digit_1.probability<mat[i]){
      digit_1.value = i;
      digit_1.probability = mat[i];
    }
  }
  return digit_1;
}
