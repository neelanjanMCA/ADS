#include <iostream.h>
#include<conio.h>
#include<process.h>


struct Node {
    int info;
    Node* link;
};

class LinkedList {
    Node* start;

public:
    LinkedList() {
        start = NULL;
    }

    void create() {
        int item;
        Node* ptr;
        cout << "Enter an item: ";
        cin >> item;
        ptr = new Node;
        ptr->info = item;
        ptr->link = start;
        start = ptr;
    }

    void display() {
        Node* temp = start;
        while (temp != NULL) {
            cout << temp->info << " -> ";
            temp = temp->link;
        }
        cout << "NULL" << endl;
    }

    void deleteFront() {
        if (start == NULL) {
            cout << "List is empty!" << endl;
        } else {
            Node* temp = start;
            start = start->link;
            delete temp;
            cout << "Node deleted from the front." << endl;
        }
    }

    void deleteEnd() {
        if (start == NULL) {
            cout << "List is empty!" << endl;
        } else if (start->link == NULL) { // Only one node
            delete start;
            start = NULL;
            cout << "Node deleted from the end." << endl;
        } else {
            Node* temp = start;
            while (temp->link->link != NULL) {
                temp = temp->link;
            }
            delete temp->link;
            temp->link = NULL;
            cout << "Node deleted from the end." << endl;
        }
    }

    void deleteAtPosition(int pos) {
        if (start == NULL) {
            cout << "List is empty!" << endl;
        } else if (pos == 1) {
            deleteFront();
        } else {
            Node* temp = start;
            for (int i = 1; temp != NULL && i < pos - 1; i++) {
                temp = temp->link;
            }
            if (temp == NULL || temp->link == NULL) {
                cout << "Invalid position!" << endl;
            } else {
                Node* nodeToDelete = temp->link;
                temp->link = temp->link->link;
                delete nodeToDelete;
                cout << "Node deleted at position " << pos << "." << endl;
            }
        }
    }
};

int main() {
    LinkedList list;
    int choice, pos;

    do {
        cout << "\nMenu:\n1. Create\n2. Display\n3. Delete from Front\n4. Delete from End\n5. Delete from Position\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.create();
                break;
            case 2:
                list.display();
                break;
            case 3:
                list.deleteFront();
                break;
            case 4:
                list.deleteEnd();
                break;
            case 5:
                cout << "Enter the position to delete: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
