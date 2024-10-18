// modified this code in short 

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2; 

        if (arr[mid] == key) return mid;
        (key > arr[mid]) ? start = mid + 1 : end = mid - 1; 
    }
    
    return -1;  // Key not found
}

int main() {
    int even[] = {2, 4, 6, 8, 12, 18};
    int odd[] = {3, 8, 11, 14, 16};

    cout << "Index of 12 in even array: " << binarySearch(even, 6, 12) << endl;
    cout << "Index of 10 in odd array: " << binarySearch(odd, 5, 10) << endl;

    return 0;
}
