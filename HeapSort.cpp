#include <iostream>
using namespace std;

// Heapify Down: Maintains the heap property
void heapify(int arr[], int n, int i)
{
    int largest = i;            // Assume current node is the largest
    int leftChild = 2 * i + 1;  // Left child index
    int rightChild = 2 * i + 2; // Right child index

    // Check if left child exists and is greater than the largest
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Check if right child exists and is greater than the largest
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If the largest is not the current node, swap and heapify
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildHeap(int arr[], int n)
{
    // Start from the last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Heap Sort Algorithm
void heapSort(int arr[], int n)
{
    // Step 1: Build a max heap
    buildHeap(arr, n);

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
