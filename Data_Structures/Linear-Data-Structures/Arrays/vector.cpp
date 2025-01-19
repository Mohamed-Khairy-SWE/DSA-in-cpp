/*
    In C++, vectors are used to store elements of similar data
    types,However,unlike arrays, the size of a vector can grow
    dynamically.

    That is, we can change the size of the vector during the
    execution of a program as per out requirements.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // Vector Declaration: vector<data type> vector_name;
    // Notice that we have not specified the size of the vector
    // during the declaration, this is because the size of a vector
    // can grow dynamically, so it is not necessary to define it.
    vector<int> numbers;
    // Vector initialization

    // initializer list
    vector<int> vector1 = {1, 2, 3, 4, 5};

    // uniform initialization
    vector<int> vector2{6, 7, 8, 9, 10};

    // method 3:
    /*
        This code creates an int vector with size 5
        and initializes the vector with the value of 12.
    */
    vector<int> vector3(5, 12);

    /*
        Basic Vector Operations:

        The vector class provides various methods to
        perform different operations on vectors.
        We will look at some commonly used
        vector operations in this tutorial:

        Add elements
        Access elements
        Change elements
        Remove elements
    */

    /*
        1. Add Elements to a Vector:
        To add a single element into a vector,
        we use the push_back() function. It inserts an
        element into the end of the vector. For example,
    */

    vector<int> num{1, 2, 3, 4, 5};

    cout << "Initial Vector: ";

    for (const int &i : num)
    {
        cout << i << "  ";
    }

    // add the integers 6 and 7 to the vector
    num.push_back(6);
    num.push_back(7);

    cout << "\nUpdated Vector: ";

    for (const int &i : num)
    {
        cout << i << "  ";
    }

    /*
        Note: We can also use the insert() and emplace()
        functions to add elements to a vector.
    */

    /*
        2. Access Elements of a Vector:
        In C++, we use the index number to access the
        vector elements. Here, we use the at() function
        to access the element from the specified index.
    */

    vector<int> num1{1, 2, 3, 4, 5};

    cout << "Element at Index 0: " << num1.at(0) << endl;
    cout << "Element at Index 2: " << num1.at(2) << endl;
    cout << "Element at Index 4: " << num1.at(4);

    /*
        Note: Like an array, we can also use the square
        brackets [] to access vector elements.
    */

    vector<int> num2{1, 2, 3};
    cout << num2[1]; // Output: 2

    // gives garbage value
    cout << num2[4];

    // throws an exception
    cout << num2.at(4);

    /*
        3. Change Vector Element:

        We can change an element of the vector using the
        same at() function.
    */
    vector<int> num3{1, 2, 3, 4, 5};

    cout << "Initial Vector: ";

    for (const int &i : num3)
    {
        cout << i << "  ";
    }

    // change elements at indexes 1 and 4
    num3.at(1) = 9;
    num3.at(4) = 7;

    cout << "\nUpdated Vector: ";

    for (const int &i : num3)
    {
        cout << i << "  ";
    }

    /*
        4. Delete Elements from C++ Vectors:

        To delete a single element from a vector,
        we use the pop_back() function.
    */

    vector<int> prime_numbers{2, 3, 5, 7};

    // initial vector
    cout << "Initial Vector: ";
    for (int i : prime_numbers)
    {
        cout << i << " ";
    }

    // remove the last element
    prime_numbers.pop_back();

    // final vector
    cout << "\nUpdated Vector: ";
    for (int i : prime_numbers)
    {
        cout << i << " ";
    }

    /*
        Initialize Vector Iterators:

        We can initialize vector iterators using
        the begin() and end() functions.
    */

    /*
        1. begin() function:

        The begin() function returns an iterator that
        points to the first element of the vector.

        2. end() function:

        The end() function points to the theoretical
        element that comes after the final element of
        the vector.
    */

    vector<int> nums{1, 2, 3, 4, 5};

    // declare iterator
    vector<int>::iterator iter;

    // initialize the iterator with the first element
    iter = nums.begin();

    // print the vector element
    cout << "num[0] = " << *iter << endl;

    // iterator points to the 3rd element
    iter = num.begin() + 2;
    cout << "num[2] = " << *iter;

    // iterator points to the last element
    iter = num.end() - 1;
    cout << "num[4] = " << *iter;

    // use iterator with for loop
    for (iter = nums.begin(); iter < nums.end() - 1; iter++)
    {
        cout << *iter << " ";
    }

    /*
        C++ Vector Functions:

        In C++, the vector header file provides
        various functions that can be used to perform
        different operations on a vector.

        Function	Description
        size()	    returns the number of elements present in the vector
        clear()	    removes all the elements of the vector
        front()	    returns the first element of the vector
        back()	    returns the last element of the vector
        empty()	    returns 1 (true) if the vector is empty
        capacity()	check the overall size of a vector
    */
    return 0;
}