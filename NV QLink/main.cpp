#include <iostream>
using namespace std;

class linked{
protected:
    struct node{
        int info;
        struct node *link;
    };
    typedef struct node Node;
    Node *front, *rear;

public:
    void create();
    void display();
    void enqueue();
    void dequeue();

    linked(){
        front = rear = NULL;
    }
};

void linked::create() {
    int item;
    Node *ptr;
    if(front == NULL) {
        ptr = new Node;
        cout << "\nEnter the item to the Node: ";
        cin >> item;
        ptr->info = item;
        ptr->link = NULL;
        front = rear = ptr;
    } else {
        cout << "\nLINK LIST ALREADY EXISTS\n";
    }
}

void linked::display() {
    Node *ptr;
    if(front == NULL) {
        cout << "LINK LIST IS EMPTY";
    } else {
        ptr = front;
        while(ptr != NULL) {
            cout << ptr->info << "\t";
            ptr = ptr->link;
        }
    }
}

void linked::enqueue() {
    Node *ptr;
    int item;
    ptr = new Node;
    cout << "\nEnter the item to add in the queue: ";
    cin >> item;
    ptr->info = item;
    ptr->link = NULL;

    if(front == NULL) {
        front = rear = ptr;
    } else {
        rear->link = ptr;
        rear = ptr;
    }
}

void linked::dequeue() {
    if(front == NULL) {
        cout << "\nQUEUE IS EMPTY";
    } else if(front == rear) {
        delete front;
        front = rear = NULL;
        cout << "\nNODE DELETED ";
    } else {
        Node *temp = front;
        front = temp->link;
        delete temp;
        cout << "\nNODE DELETED";
    }
}



int main() {
    linked l;
    int ch;

    while(1) {
        cout << "\nQUEUE OPERATIONS IN LINKLIST\n";
        cout << "\n1.Create\n2.Display\n3.Enqueue\n4.Dequeue\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                l.create();
                break;
            case 2:
                l.display();
                break;
            case 3:
                l.enqueue();
                break;
            case 4:
                l.dequeue();
                break;
            case 5:
                exit(0);
            default:
                cout << "INVALID CHOICE" << endl;
                break;
        }
    }

    return 0;
}
