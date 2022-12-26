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

digit MlpNetwork::operator()(const Matrix& mat )
{
  Matrix new_mat = mat;
  new_mat.vectorize();
  for (int i=0;i<MLP_SIZE;i++)
  {
    new_mat = dences[i](new_mat);
  }
  digit digit_1;
  digit_1.value = 0;
  digit_1.probability = new_mat[0];
  for (int i=1;i<new_mat.get_rows();i++){
    if(digit_1.probability<new_mat[i]){
      digit_1.value = i;
      digit_1.probability = new_mat[i];
    }
  }
  return digit_1;
}
