#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
class Matrix{
    private:
        unsigned int rows;
        unsigned int cols;
        double** matrix;

    public:
    Matrix();
    Matrix(unsigned int rows,unsigned int cols,double fill);
    Matrix(const Matrix& other);
    ~Matrix();
    double** getMatrix() const{return matrix;}
    unsigned int num_rows() const{return rows;}
    unsigned int num_cols() const{return cols;}
    bool inBounds(const unsigned int row,const unsigned int col) const;
    Matrix& operator=(const Matrix& other);
    void clear();
    bool get(const unsigned int row , const unsigned int col,double& val) const;
    bool set(const unsigned int row, const unsigned int col,const double& newVal);
    void multiply_by_coefficient(const double& c);
    void swap_row(unsigned int r1, unsigned int r2);
    void transpose();
    bool add(Matrix& other);
    bool subtract(const Matrix& other);
    //sbool double_compare(const double& d1, const double& d2){return d1==d2;}
    double* get_row(const unsigned int& row);
    double* get_col(const unsigned int& col);
    Matrix* quarter() const;

};
std::ostream& operator<< (std::ostream& out, const Matrix& m);
bool operator==(const Matrix& m1, const Matrix& m2);
bool operator!=(const Matrix& m1, const Matrix& m2);
