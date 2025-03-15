#include <iostream>
using namespace std;

class MergeSort {
public:
    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2]; // Temporary arrays

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;

        // Merge the two subarrays back into arr[]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[], if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[], if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Find the middle

            mergeSort(arr, left, mid);  // Sort first half
            mergeSort(arr, mid + 1, right);  // Sort second half
            merge(arr, left, mid, right);  // Merge sorted halves
        }
    }

    void display(int arr[], int size) {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort obj;
    cout << "Original array: ";
    obj.display(arr, n);

    obj.mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    obj.display(arr, n);

    return 0;
}
