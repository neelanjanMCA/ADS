#include <iostream>

#define MAX 5
using namespace std;


int queue[MAX];
int front = -1, rear = -1;

void insert(int item) {
    if (rear == MAX - 1) {
        cout << "\nQueue Overflow!";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
    cout << "\nInserted: " << item;
}


int deleteElement() {
    if (front == -1 || front > rear) {
        cout << "\nQueue Underflow!";
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return item;
}


void display() {
    if (front == -1 || front > rear) {
        cout << "\nQueue is Empty!";
        return;
    }
    cout << "\nQueue Elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
}

int main() {

    int choice, item;
    while (1) {
        cout << "\n\n--- Queue Menu ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the item to insert: ";
                cin >> item;
                insert(item);
                break;
            case 2:
                item = deleteElement();
                if (item != -1) {
                    cout << "\nDeleted: " << item;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "\nExiting...";
                exit(0);
                break;

            default:
                cout << "\nInvalid choice! Try again.";
        }
    }
return 0;
}
