#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// the problem:
// Write a program to solve the selection problem. Let k = N/2. Draw a table showing
// the running time of your program for various values of N

using namespace std;

// Bubble sort to find the k-th smallest element
int bubbleSelect(vector<int> &arr, int k)
{
    int n = arr.size(); // Get the size of the array
    for (int i = 0; i < k; i++)
    { // Outer loop to perform k passes
        for (int j = 0; j < n - i - 1; j++)
        { // Inner loop to compare and swap adjacent elements
            if (arr[j] > arr[j + 1])
            {                             // If the current element is greater than the next
                swap(arr[j], arr[j + 1]); // Swap the elements
            }
        }
    }
    return arr[k - 1]; // Return the k-th smallest element
}

// Function to generate random array
vector<int> generateRandomArray(int size)
{
    vector<int> arr(size); // Initialize a vector of given size
    for (int i = 0; i < size; i++)
    {                              // Loop to fill the vector with random values
        arr[i] = rand() % 1000000; // Random numbers between 0 and 999999
    }
    return arr; // Return the generated random array
}

int main()
{
    srand(time(0)); // Seed the random number generator with current time

    // Table headers
    cout << "N\tRunning Time (ms)\n";
    cout << "---------------------------\n";

    vector<int> testSizes = {1000, 5000, 10000, 50000}; // Values of N to test

    for (int N : testSizes)
    {                                             // Loop through each test size
        vector<int> arr = generateRandomArray(N); // Generate a random array of size N
        int k = N / 2;                            // Find the N/2-th smallest element

        auto start = chrono::high_resolution_clock::now(); // Record the start time
        int result = bubbleSelect(arr, k);                 // Perform bubble sort to find the k-th smallest element
        auto end = chrono::high_resolution_clock::now();   // Record the end time

        chrono::duration<double, milli> duration = end - start; // Calculate the duration

        cout << N << "\t" << duration.count() << "\n"; // Print the array size and running time
    }

    return 0; // Indicate successful program termination
}
