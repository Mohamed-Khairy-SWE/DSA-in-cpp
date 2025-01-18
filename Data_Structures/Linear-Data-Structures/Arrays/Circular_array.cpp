/*
    An array is called circular if we consider the first element
    as next of the last element.

    Circular arrays are used to implement queue.
*/

/*
    An example problem:

    Suppose n people are sitting at a circular table with names
    A,B,C,D,...
    Given a name, we need to print all n people (in order) starting
    from that given name.

    For example, consider 6 people A B C D E F and given name
    as "D". People sitting in a circular manner starting from
    D are D E F A B C.

    A simple solution:

    is to create a auxiliary(helper) array
    of size 2*n and store it in another array. For example
    for 6 people, we create below the auxiliary array.
    A B C D E F A B C D E F
    Now for any given index, we simply print n elements strating
    from it.
    For example, we start from D then we print
    D E F A B C

    An efficient solution:

    is to deal with circular arrays using the same array.
    if a careful observation is run through the array. then
    after the n-th index, the next index always starts from 0
    so using the mod operator, we can easily access the elements
    of the elements of the circular list, if we use (i) % n and run
    the loop from i-th index to n+i-th index. and apply mod we can
    do the traversal in a circular array within the given
    array without using any extra space.
*/

#include <iostream>
#include <vector>

using namespace std;

// This approach takes of O(n) time but takes extra space of order O(n).
void auxiliary_array_solution(char arr[], int n, int given_index)
{
    // Create an auxiliary array of twice size.
    //  i used a vector here because my compilers
    //  doesn't support Variable Length Arrays (VLAs)
    // where the size is determined at runtime
    vector<char> auxiliary_arr(2 * n);

    // Copy arr[] to auxiliary_arr[] two times
    for (int i = 0; i < n; i++)
    {
        auxiliary_arr[i] = auxiliary_arr[n + i] = arr[i];
    }

    // print from given_index to (n+given_index).
    for (int i = given_index; i < n + given_index; i++)
    {
        cout << auxiliary_arr[i] << " ";
    }
    cout << "\n";
}

// this approach takes O(n) time and O(1) extra space.
void Circular_array_solution(char arr[], int n, int given_index)
{
    // print from given_index to n + given_index.
    for (int i = given_index; i < n + given_index; i++)
        cout << arr[i % n] << " ";
    cout << "\n";
}

int main()
{

    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "the simple solution:" << "\n";
    auxiliary_array_solution(arr, n, 3);
    cout << "the efficient solution:" << "\n";
    Circular_array_solution(arr, n, 3);
    return 0;
}