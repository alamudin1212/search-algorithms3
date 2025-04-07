#include <iostream>
using namespace std;

// Ternary Search (Iterative)
int ternarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;
        if (key < arr[mid1]) high = mid1 - 1;
        else if (key > arr[mid2]) low = mid2 + 1;
        else { low = mid1 + 1; high = mid2 - 1; }
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 60;
    cout << "Ternary: " << ternarySearch(arr, n, key) << endl;
    cout << "Interpolation: " << interpolationSearch(arr, n, key) << endl;
    return 0;
}