#include <iostream>
#include <vector>

using namespace std;

// Function to perform iterative binary search
int binarySearch(const vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        // Calculate the middle index safely to avoid overflow
        int middle = left + (right - left) / 2;

        // Check if the middle element is the target
        if (array[middle] == target) {
            return middle; // Target found
        }

        // If the target is greater, ignore the left half
        if (array[middle] < target) {
            left = middle + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = middle - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    // Example sorted array
    vector<int> numbers = {2, 4, 6, 8, 10, 12, 14};

    // Value to search for
    int targetValue = 10;

    // Perform binary search
    int resultIndex = binarySearch(numbers, targetValue);

    // Output the result
    if (resultIndex != -1) {
        cout << "Target found at index: " << resultIndex << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
