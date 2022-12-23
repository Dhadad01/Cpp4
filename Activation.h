#include "Matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H
typedef Matrix(*activation_f)( const Matrix&);
// Insert activation namespace here...
namespace activation{
    Matrix relu(const Matrix& matrix);
    Matrix softmax(const Matrix& matrix);
}
#endif //ACTIVATION_H