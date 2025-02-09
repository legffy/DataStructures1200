#include "Matrix.h"
// Creates an empty matrix object
Matrix::Matrix() : rows(0), cols(0), matrix(nullptr) {}
// Creates a Matrix obejct
// fills the matrix 2d array variable with the number of rows and columns inputted
// every index of the 2d array is given the value of the variable fill
Matrix::Matrix(unsigned int nRows,unsigned int nCols,double fill) : rows(nRows), cols(nCols), matrix(nullptr)
{
    if (rows != 0 && cols != 0)
    {
        matrix = new double *[rows];
        for (unsigned int i = 0; i < rows; i++)
        {
            matrix[i] = new double[cols];
            for (unsigned int j = 0; j < cols; j++)
            {
                matrix[i][j] = fill;
            }
        }
    }
    else
    {
        rows = 0;
        cols = 0;
    }
}
// Creates a Matrix object of the qualities of the Matrix object other
Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), matrix(nullptr)
{
    if (rows > 0 && cols > 0 && other.matrix != nullptr)
    {
        matrix = new double *[rows];
        for (unsigned int i = 0; i < rows; i++)
        {
            matrix[i] = new double[cols];
            for (unsigned int j = 0; j < cols; j++)
            {
                matrix[i][j] = other.matrix[i][j]; // Copy each value
            }
        }
    }
}
// checks if the given row and column are in bounds the given matrix
// destructor frees matrix 2d array from memory
Matrix::~Matrix()
{
    clear();
}
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        // Free existing memory
        clear();

        // Copy new data
        rows = other.rows;
        cols = other.cols;
        matrix = nullptr;

        if (rows > 0 && cols > 0 && other.matrix != nullptr)
        {
            matrix = new double *[rows];
            for (unsigned int i = 0; i < rows; i++)
            {
                matrix[i] = new double[cols];
                for (unsigned int j = 0; j < cols; j++)
                {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
    }
    return *this;
}
// gets rid of excess memory
void Matrix::clear()
{
        for (unsigned int i = 0; i < rows; i++)
        {
        if (matrix[i])  // Check if row exists before deleting
            delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    rows = 0;
    cols = 0;
}
//gets value at index and assigns it a value
bool Matrix::get(const unsigned int row, const unsigned int col, double &val) const
{
    if (row < rows && col < cols)
    {
        val = matrix[row][col];
        return true;
    }
    return false;
}
//finds value at index and assigns it to the value
bool Matrix::set(const unsigned int row, const unsigned int col, const double &newVal)
{
    if (row < rows && col < cols)
    {
        matrix[row][col] = newVal;
        return true;
    }
    return false;
}
//multiplies every value in the array by a given value
void Matrix::multiply_by_coefficient(const double &c)
{
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < cols; j++)
        {
            matrix[i][j] *= c;
        }
    }
}
//swaps two rows
//uses pointer arithemtic to avoid any errors
void Matrix::swap_row(unsigned int r1, unsigned int r2)
{
    if (r1 < rows && r2 < rows)
    {
        double *temp = matrix[r1];
        matrix[r1] = matrix[r2];
        matrix[r2] = temp;
    }
}
//swaps the cols and rows in a matrix
//so that the values are flip flopped
void Matrix::transpose()
{
    unsigned int temp = rows;
    unsigned int temp2 = cols;
    double** transposed = new double*[cols];
    for (unsigned int i = 0; i < cols; ++i) {
        transposed[i] = new double[rows];
        for (unsigned int j = 0; j < rows; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    clear();
    rows = temp2;
    cols = temp;
    matrix = transposed;
    
}
//adds all the values in one matrix to the values in another
bool Matrix::add(Matrix &other)
{
    if (rows == other.rows && cols == other.cols)
    {
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < cols; j++)
            {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return true;
    }
    return false;
}
//subtracts one matrix values from another matrixs 
bool Matrix::subtract(const Matrix &other)
{
    if (rows == other.rows && cols == other.cols)
    {
        for (unsigned int i = 0; i < rows; i++)
        {
            for (unsigned int j = 0; j < cols; j++)
            {
                matrix[i][j] -= other.matrix[i][j];
            }
        }
        return true;
    }
    return false;
}
// gets a row and returns the first index of the row so one can iterate through the row
double *Matrix::get_row(const unsigned int &row)
{
    if (row < rows)
    {
        double *nRow = new double[cols];
        for (unsigned int i = 0; i < cols; i++)
        {
            nRow[i] = matrix[row][i];
        }
        return nRow;
    }
    double *nullRow = nullptr;
    return nullRow;
}
//returns pointer to an array that contains values in a specific column 
double *Matrix::get_col(const unsigned int &col)
{
    if (col < cols)
    {
        double *column = new double[rows];
        for (unsigned int i = 0; i < rows; i++)
        {   
            column[i] = matrix[i][col];
        }
        return column;
    }
    return nullptr;
}
//splits the matrix into 4 diffferent sections and creates a point array pointing to each new object containting the new split matrixs
Matrix *Matrix::quarter() const
{
    Matrix *quart = new Matrix[4];

    unsigned int mRow = rows / 2;
    unsigned int oRow = rows % 2;

    unsigned int mCol = cols / 2;
    unsigned int oCol = cols % 2;

    // Checking for an odd amount of rows and columns in a given matrix
    if (oRow == 0 && oCol == 0)
    {
        quart[0] = Matrix(mRow, mCol, 0.0);               // UL
        quart[1] = Matrix(mRow, cols - mCol, 0.0);        // UR
        quart[2] = Matrix(rows - mRow, mCol, 0.0);        // LL
        quart[3] = Matrix(rows - mRow, cols - mCol, 0.0); // LR
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < cols; ++j)
            {
                if (i < mRow && j < mCol)
                {
                    quart[0].set(i, j, matrix[i][j]);
                }
                else if (i < mRow && j >= cols - mCol)
                {
                    quart[1].set(i, j - mCol, matrix[i][j]);
                }
                else if (i >= rows - mRow && j < mCol)
                {
                    quart[2].set(i - mRow, j, matrix[i][j]);
                }
                else
                {
                    quart[3].set(i - mRow, j - mCol, matrix[i][j]);
                }
            }
        }
    }
    else if (oRow != 0 && oCol == 0)
    {
        quart[0] = Matrix(mRow + oRow, mCol, 0.0);        // UL
        quart[1] = Matrix(mRow + oRow, cols - mCol, 0.0); // UR
        quart[2] = Matrix(rows - mRow, mCol, 0.0);        // LL
        quart[3] = Matrix(rows - mRow, cols - mCol, 0.0); // LR
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < cols; ++j)
            {
                if (i < mRow + oRow && j < mCol)
                {
                    quart[0].set(i, j, matrix[i][j]);
                }
                if (i < mRow + oRow && j >= cols - mCol)
                {
                    quart[1].set(i, j - mCol, matrix[i][j]);
                }
                if (i >= rows - mRow - oRow && j < mCol)
                {
                    quart[2].set(i - mRow, j, matrix[i][j]);
                }
                if (i >= rows - mRow - oRow && j >= cols - mCol)
                {
                    quart[3].set(i - mRow, j - mCol, matrix[i][j]);
                }
            }
        }
    }
    else if (oRow == 0 && oCol != 0)
    {
        quart[0] = Matrix(mRow, mCol + oCol, 0.0);        // UL
        quart[1] = Matrix(mRow, cols - mCol, 0.0);        // UR
        quart[2] = Matrix(rows - mRow, mCol + oCol, 0.0); // LL
        quart[3] = Matrix(rows - mRow, cols - mCol, 0.0); // LR
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < cols; ++j)
            {
                if (i < mRow && j < mCol + oCol)
                {
                    quart[0].set(i, j, matrix[i][j]);
                }
                if (i < mRow && j >= cols - mCol - oCol)
                {
                    quart[1].set(i, j - mCol, matrix[i][j]);
                }
                if (i >= rows - mRow && j < mCol + oCol)
                {
                    quart[2].set(i - mRow, j, matrix[i][j]);
                }
                if (i >= rows - mRow && j >= cols - mCol - oCol)
                {
                    quart[3].set(i - mRow, j - mCol, matrix[i][j]);
                }
            }
        }
    }
    else
    {
        quart[0] = Matrix(mRow + oRow, mCol + oCol, 0.0); // UL
        quart[1] = Matrix(mRow + oRow, cols - mCol, 0.0); // UR
        quart[2] = Matrix(rows - mRow, mCol + oCol, 0.0); // LL
        quart[3] = Matrix(rows - mRow, cols - mCol, 0.0); // LR
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < cols; ++j)
            {
                if (i < mRow + oRow && j < mCol + oCol)
                {
                    quart[0].set(i, j, matrix[i][j]);
                }
                if (i < mRow + oRow && j >= cols - mCol - oCol)
                {
                    quart[1].set(i, j - mCol, matrix[i][j]);
                }
                if (i >= rows - mRow - oRow && j < mCol + oCol)
                {
                    quart[2].set(i - mRow, j, matrix[i][j]);
                }
                if (i >= rows - mRow - oRow && j >= cols - mCol - oCol)
                {
                    quart[3].set(i - mRow, j - mCol, matrix[i][j]);
                }
            }
        }
    }
    return quart;
}
/*Non member functions*/


// Checks if one matrix object is equal to another
bool operator==(const Matrix &m1, const Matrix &m2)
{
    if (m1.num_rows() == m2.num_rows() && m1.num_cols() == m2.num_cols())
    {
        for (unsigned int i = 0; i < m1.num_rows(); i++)
        {
            for (unsigned int j = 0; j < m1.num_cols(); j++)
            {
                if (m1.getMatrix()[i][j] != m2.getMatrix()[i][j])
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
// Checks if on matrix object is not equal to another
bool operator!=(const Matrix &m1, const Matrix &m2)
{
    return !(m1 == m2);
}
//prints info about the matrix 
std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    os << m.num_rows() << " x " << m.num_cols() << " matrix:\n[ ";
    for (unsigned int i = 0; i < m.num_rows(); i++)
    {
        for (unsigned int j = 0; j < m.num_cols(); j++)
        {
            os <<std::setw(3) << m.getMatrix()[i][j] << " ";
        }
        if (i == m.num_rows() - 1)
        {
            os << "]";
        }
        os << "\n  ";
    }
    return os;
}
