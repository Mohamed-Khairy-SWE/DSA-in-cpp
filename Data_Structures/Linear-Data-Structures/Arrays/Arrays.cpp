/*
    In C++, an array is a data structure that is used to
    store multiple values of similar data types in
     a contiguous memory location.
 */

/*
    For example:

    if we have to store the marks of 4 or 5 students then
    we can easily store them by creating 5 different
    variables but what if we want to store marks of
    100 students or say 500 students then it becomes
    very challenging to create that numbers of variable
    and manage them. Now, arrays come into the picture
    that can do it easily by just creating an array of
    the required size.
 */

#include <iostream>
using namespace std;

int main()
{

    /*
        One-Dimensional Arrays:

        A one-dimensional array stores a sequence of
        elements of the same type in contiguous memory
        locations.
     */

    int arr1[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\n";

    //-----------------------------------------------------

    /*
        Two-Dimensional Arrays:

        A two-dimensional array is like a matrix where
        data is stored in rows and columns.
     */

    int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
    }

    cout << "\n";

    //-----------------------------------------------------

    /*
        Multi-Dimensional Arrays:

        A multi-dimensional array extends beyond two dimensions.
    */

    int arr3[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << arr3[i][j][k] << " ";
            }
        }
    }

    cout << "\n";

    //-----------------------------------------------------

    /*
        Dynamic Arrays:

        dynamic arrays use memory allocation at runtime, this
        means that the data of the array is stored on the heap
        and we point at it from the stack by using the keyword
        (new) to store on the heap and we need to use the keyword
        (delete) after we are finished with the array to not cause
        a memory leak.
    */

    // Allocate memory for the array on the heap
    int *dyna_arr = new int[5];

    for (int i = 0; i < 5; i++)
    {
        dyna_arr[i] = i + 1; // Assigning values
    }

    for (int i = 0; i < 5; i++)
    {
        cout << dyna_arr[i] << " ";
    }

    // Deallocate memory to prevent memory leaks
    delete[] dyna_arr;

    cout << "\n";

    //----------------------------------------------------

    /*
        Arrays of structures:

        Arrays can hold user-defined types like structures.
     */

    struct Student
    {
        string name;
        int age;
    };

    Student student[2] = {{"alice", 30}, {"bob", 55}};

    for (int i = 0; i < 2; i++)
    {
        cout << student[i].name << "is" << student[i].age << " , ";
    }

    cout << "\n";

    //------------------------------------------------------

    /*
        Arrays of Pointers:

        Arrays can hold pointers.
     */

    int a = 10, b = 20;

    int *ptr_arr[2] = {&a, &b};

    for (int i = 0; i < 2; i++)
    {
        cout << *ptr_arr[i] << " ";
    }

    cout << "\n";

    //-----------------------------------------------------

    /*
        Arrays of Strings:

        An array can store strings.
     */

    string arr[] = {"hello", "world"};

    for (int i = 0; i < 2; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";

    //-----------------------------------------------------

    class Person
    {
    public:
        string name;
        Person(string n) : name(n) {}
        void Display() { cout << name << " "; }
    };

    Person obj_arr[2] = {Person("mo"), Person("bob")};

    for (int i = 0; i < 2; i++)
    {
        obj_arr[i].Display();
    }

    cout << "\n";

    //-----------------------------------------------------

    return 0;
}
