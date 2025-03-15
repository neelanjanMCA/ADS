#include <iostream>

using namespace std;



void selectionSort(int A[], int N) {
    int k, loc, temp;


    for (k = 0; k < N - 1; k++) {
        int min = A[k];
        loc = k;

        for (int j = k + 1; j < N; j++) {
            if (A[j] < min) {
                min = A[j];
                loc = j;
            }
        }

        temp = A[k];
        A[k] = A[loc];
        A[loc] = temp;
    }
}

void displayArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {24, 22, 11, 9, 18, 10};
    int N = sizeof(A) / sizeof(A[0]);

    cout << "Original Array: ";
    displayArray(A, N);

    selectionSort(A, N);

    cout << "\nSorted Array: ";
    displayArray(A, N);

    getch();
}
