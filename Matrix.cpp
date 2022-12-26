//
// Created by naqni on 16/12/2022.
//
#include <iostream>
#include "Matrix.h"
#include <cmath>
Matrix::Matrix (int rows, int cols)
{
  if (rows<1||cols<1){
    throw std::domain_error("dimension error");
  }
  this->dim = {rows,cols};
  _mat = new float *[dim.rows];
  for (int i = 0; i < dim.rows; ++i)
  {
    _mat[i] = new float[dim.cols];
    for (int j = 0; j < dim.cols; j++)
    {
      _mat[i][j] = 0;
    }
  }
};


Matrix::Matrix () : Matrix (1, 1)
{}

//copy constructor
Matrix::Matrix (const Matrix &matrix)
{
  dim.rows = matrix.dim.rows;
  dim.cols = matrix.dim.cols;
  _mat = new float *[dim.rows];
  for (int i = 0; i < dim.rows; ++i)
  {
    _mat[i] = new float[dim.cols];
    for (int j = 0; j < dim.cols; j++)
    {
      _mat[i][j] = matrix._mat[i][j];
    }
  }
}
//destructor
Matrix::~Matrix ()
{
  for (int i = 0; i < dim.rows; ++i)
  {
    delete _mat[i];
    _mat[i] = nullptr;
  }
  delete _mat;
  _mat = nullptr;
}
//allocation
Matrix& Matrix::operator= (const Matrix &other)
{
  if (this != &other)
  {
    for (int i = 0; i < dim.rows; i++)
    {
      delete _mat[i];
      _mat[i] = nullptr;
    }
    delete _mat;
    _mat = nullptr;
    this->dim.rows = other.dim.rows;
    this->dim.cols = other.dim.cols;
    _mat = new float *[dim.rows];
    for (int i = 0; i < dim.rows; i++)
    {
      _mat[i] = new float[dim.cols];
      for (int j = 0; j < dim.cols; j++)
      {
        _mat[i][j] = other._mat[i][j];
      }
    }
  }
  return *this;
}

Matrix& Matrix::transpose ()
{
  Matrix new_mat (dim.cols, dim.rows);
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      new_mat._mat[j][i] = _mat[i][j];
    }
  }
  *this = Matrix (new_mat);
  return *this;
}
Matrix& Matrix::vectorize ()
{
//{{
  Matrix new_mat (dim.rows * dim.cols, 1);
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      new_mat._mat[i * this->dim.cols + j][0] = _mat[i][j];
    }
  }
  *this = Matrix (new_mat);
  return *this;
}
void Matrix::plain_print () const
{
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      std::cout << _mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
Matrix Matrix::dot (const Matrix &matrix) const
{
  if (dim.rows != matrix.dim.rows || dim.cols != matrix.dim.cols)
  {
    throw std::domain_error("dimension error");
  }
  Matrix new_mat (dim.rows, dim.cols);
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      new_mat._mat[i][j] = _mat[i][j] * matrix._mat[i][j];
    }
  }
  return new_mat;
}
float Matrix::sum () const
{
  float sum = 0;
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      sum += _mat[i][j];
    }
  }
  return sum;
}
float Matrix::norm () const
{
  float norm = 0;
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      norm += _mat[i][j] * _mat[i][j];
    }
  }
  return sqrt (norm);
}
Matrix& Matrix::operator+= (const Matrix &other)
{
  if(dim.rows != other.dim.rows||dim.cols != other.dim.cols){
    throw std::domain_error("dimension error");
  }
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      _mat[i][j] += other._mat[i][j];
    }
  }
  return *this;
}
Matrix Matrix::operator+ (const Matrix &other) const
{
  if(dim.rows != other.dim.rows||dim.cols != other.dim.cols){
    throw std::domain_error("dimension error");
  }
  Matrix new_mat (dim.rows, dim.cols);
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      new_mat._mat[i][j] = _mat[i][j] + other._mat[i][j];
    }
  }
  return new_mat;
}
Matrix Matrix::operator* (const Matrix &other) const
{
  if (dim.cols != other.dim.rows)
  {
    throw std::domain_error("dimension error");
  }
  Matrix new_mat (dim.rows, other.dim.cols);
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < other.dim.cols; j++)
    {
      float sum = 0;
      for (int k = 0; k < dim.cols; k++)
      {
        sum += _mat[i][k] * other._mat[k][j];
      }
      new_mat._mat[i][j] = sum;
    }
  }
  return new_mat;
}
Matrix Matrix::operator* (const float c) const
{
  Matrix new_mat(dim.rows,dim.cols);
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j = 0; j < dim.cols; j++)
    {
      new_mat._mat[i][j] = _mat[i][j] * c;
    }
  }
  return new_mat;
}
float& Matrix::operator() (int i,int j) const
{
  if(i>=dim.rows||j>=dim.cols||i<0||j<0){
      throw std::out_of_range("out of range error");
  }
  return _mat[i][j];
}
float& Matrix::operator[] (int i) const
{
  if(i>=dim.cols*dim.rows||i<0){
    throw std::out_of_range("out of range error");
  }
  return _mat[i/dim.cols][i% dim.cols];
}
int Matrix::argmax () const
{
  int ind = 0;
  for (int i = 0; i < dim.rows; i++)
  {
    for (int j=0;j<dim.cols;j++)
    {
      if(_mat[i][j]>_mat[ind/dim.cols][ind% dim.cols]){
        ind = i*dim.rows+j;
      }
    }
  }
  return ind;
}
Matrix operator* (float c, Matrix &other)
{
  return other*(c);
}
std::ostream& operator<< (std::ostream &os, Matrix &other)
{
  for (int i = 0; i < other.dim.rows; i++)
  {
    for (int j = 0; j < other.dim.cols; j++)
    {
      if(other(i,j)>0.1){
        os<<"**";
      }
      else{
        os<<"  ";
      }
    }
    os<<std::endl;
  }
  return os;
}
std::istream& operator>>( std::istream& is ,Matrix &matrix)
{
  for (int i = 0; i < matrix.dim.rows; i++)
  {
    for (int j = 0; j < matrix.dim.cols; j++)
    {
      is.read ((char*) &matrix._mat[i][j], sizeof (float ));
    }
  }
  std::streamoff k = is.tellg();
  if (k == -1)
  {
    throw std::runtime_error("stream error");
  }
  return is;
}
