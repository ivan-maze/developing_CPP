#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; ++j) {
        // If current element is less than or equal to pivot
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Main function
int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    cout << "Original array: ";
    printArray(data);

    quickSort(data, 0, data.size() - 1);

    cout << "Sorted array: ";
    printArray(data);

    return 0;
}
