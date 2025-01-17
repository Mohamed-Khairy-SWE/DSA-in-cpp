/*
    A matrix is a two dimensional data object made of m rows
    and n columns, therefore having total m * n values. if
    most of the elements of the matrix have 0 value, then
    it is called sparse matrix.
*/

/*
    Why to use Sparse Matrix instead of simple matrix?

    1.Storage: There are lesser non-zero elements than zeros
    and thus lesser memory can be used to store only those
    elements.

    2.Computing time: Computing time can be saved by logically
    designing a data structure traversing only non-zero elements.

    3.Uses: Sparse matrices can be useful for computing
    large-scale applications that dense martrices connot handle,
    one such application involves solving partial differential
    equations by using the finite element method.
    the finite element method is one method of solving
    partial differential equations (PDEs).
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // Assume 4x5 sparse matrix
    int sparseMatrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};

    int size = 0; // the number of non-zero elements

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
                size++;

    /*
        number of columns in compactMatrix (size) must be
        equal to number of non-zero elements in sparseMatrix
    */

    // int compactMatrix[3][size];

    // i will use a vector because the compiler shout at me
    // for not using a constant value and the size is determind
    // at runtime

    /*
        vector<vector<int>> is used instead of vector<int> because:

        Sparse Matrix Representation:
        A sparse matrix has many zero elements.
        Using a simple vector<int> would store all elements,
        including the zeros, leading to significant memory
        waste, especially for large matrices.
    */

    vector<vector<int>> compactMatrix(3, vector<int>(size));

    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
            cout << " " << compactMatrix[i][j];

        cout << "\n";
    }

    return 0;
}