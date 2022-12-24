
#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
class Matrix
{

 public:
  /**
   * @struct Dims
   * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
   */
  //constructor
  Matrix (int rows, int cols);
  Matrix();
  Matrix& operator=(const Matrix &other);
  Matrix& operator+=(const Matrix &other);
  Matrix operator+(const Matrix &other)const;
  Matrix operator*(const Matrix &other)const ;
  Matrix& operator*(float c);
  float& operator()(int i,int j);
  float& operator[](int i);
  Matrix(const Matrix &matrix);
  ~Matrix();
  int get_rows() const{return dim.rows;}
  int get_cols() const{return dim.cols;}
  Matrix& transpose();
  Matrix& vectorize();
  void plain_print() const;
  int argmax();
  float sum() const;
  float norm() const;
  Matrix dot(Matrix& matrix) const;
  struct dims
  {
      int rows, cols;
  };
  friend std::ostream& operator<<(std::ostream& os,Matrix& other);
  friend std::istream& operator>>( std::istream& is ,Matrix &matrix);
  friend void operator*(float c,Matrix& other);
 private:
  dims dim{};
  float **_mat;

};

#endif //MATRIX_H
