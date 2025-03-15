#include <iostream>
using namespace std;

class Array {
private:
    int arr[100], size;
public:
    void getArray() {
        cout << "Enter size of array: ";
        cin >> size;
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void reverseArray() {
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
    }

    void displayArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array obj;
    obj.getArray();

    cout << "Original array: ";
    obj.displayArray();

    obj.reverseArray();

    cout << "Reversed array: ";
    obj.displayArray();

    return 0;
}
