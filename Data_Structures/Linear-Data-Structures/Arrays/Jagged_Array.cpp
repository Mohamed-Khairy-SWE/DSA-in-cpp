/*
    A jagged array is an array of arrays such that member
    arrays can be of different sizes, in 2D array terms for
    each row we can have a variable number of columns. These
    types of arrays are also known as Jagged arrays
 */

/*
    Jagged Array can be implemented in C++ in two ways:

    1. Using a static array of pointers
    2. Using dynamic 2D arrays
*/

#include <iostream>

using namespace std;

int main()
{

    // 1st way: static arrays

    /*
        create 3 rows with different sizes
        (different number of columns in context of the jagged array)
    */
    int row1[] = {1, 2, 3, 4};
    int row2[] = {5, 6};
    int row3[] = {7, 8, 9};

    /*
        the jagged array will store the addresses
        of the other arrays which means that
        the jagged array type have to be pointer
    */

    int *jagged_arr[] = {row1, row2, row3};

    /*
        we will create a size array which will
        store the sizes of the arrays that in
        the jagged array so when we access an
        array in the jagged array the loop will
        be able to know how many iteration it needs.
    */

    int sizes[] = {4, 2, 3};

    cout << "elements in matrix from as follow" << endl;

    for (int i = 0; i < 3; i++)
    {

        /*
            we will make a poniter variable
            that will containe the value of
            the current index in the jagged
            which is an address of an array
        */
        int *ptr = jagged_arr[i];

        for (int j = 0; j < sizes[i]; j++)
        {

            cout << *(ptr + j) << " ";
        }

        cout << "\n";
    }

    cout << "\n";

    //----------------------------------------------------

    // 2st way: Dynamic 2D arrays

    /*
        we will create a variable row
        that will hold the size of the
        jagged array to pass it for the
        dynamic array
    */

    int row = 3;

    /*
        note: that when we make a dynamic array
        we create a pointer variable in the stack
        memory that points to the array in the heap
        memory and because that the jagged array is
        pointer type that means we are pointing to
        a pointer so we need to type two astrick **
    */

    int **jagged_arr2 = new int *[row];
    int sizes2[] = {4, 2, 3};

    for (int i = 0; i < row; i++)
    {
        /*
            we will assgin the elements
            int the jagged array with an array
        */

        *(jagged_arr2 + i) = new int[sizes2[i]];
    }

    int num = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes2[i]; j++)
        {
            // assigning elements of the arrays that in the jagged array
            jagged_arr2[i][j] = num++;
        }
    }

    cout << "elements in matrix form as follow" << "\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes2[i]; j++)
        {
            cout << jagged_arr2[i][i] << " ";
        }
        cout << endl;
    }

    return 0;
}