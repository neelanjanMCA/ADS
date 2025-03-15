#include <iostream>

using namespace std;


class linked{
protected:
 struct node{
	int info;
	struct node *link;
	};
 typedef struct node Node;
 Node *start;
 public:
  void create();
  void display();
  void insert_beg();
  void delete_beg();
  void delete_end();
  void delete_sp();
linked(){
 start=NULL;
 } };
void linked::create()
{
int item;
Node *ptr;
if(start==NULL){
ptr= new Node;
cout<<"\nEnter the item to the Node:";
cin>>item;
ptr->info=item;
ptr->link=NULL;
start=ptr;
}
else{
cout<<"\nLINK LIST ALREADY EXISTS\n";
}
}
void linked::display(){
 Node *ptr;
 if(start==NULL){
  cout<<"LINK LIST IS EMPTY";
  }
  else{
  ptr=start;
  while(ptr!=NULL){
   cout<<ptr->info<<"\t";
   ptr=ptr->link;
   }
   }
   }
void linked::insert_beg()
{
Node *ptr;
int item;
if(start==NULL){
ptr= new Node;
cout<<"\nEnter the item to the Node:";
cin>>item;
ptr->info=item;
ptr->link=NULL;
start=ptr;
}
else{
ptr= new Node;
cout<<"Enter the item";
cin>>item;
ptr->info=item;
ptr->link=start;
start=ptr;
}
}
void linked::delete_beg(){
if(start==NULL){
 cout<<"LIST is EMPTY";
 }
 else{
 Node *temp=start;
 start=temp->link;
 delete temp;
 cout<<"NODE DELETED";
 }
 }
 void linked::delete_end() {
        if (start == NULL) {
            cout << "List is empty!" << endl;
        } else if (start->link == NULL) {
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

void linked::delete_sp(){
Node *temp;
Node *ptr;
int y, item;
if(start== NULL){
cout<<"Link list empty";
}
else if (start!=NULL){
 temp=start;
 cout<<"Enter the element after which item has to be inserted:";
 cin>>y;
 while(temp->info!=y && temp->link !=NULL){
  temp=temp->link;
  }
  if(temp->info==y){
  ptr=temp->link;
  temp->link=temp->link->link;
  delete ptr;
  cout<<"NODE DELETED";
  }
    else{
  cout<<"Element Not found";
  }
  }
  else{
  cout<<"Element not found";
  }
  }
 int main(){
 linked l;
 int ch;

 while(1){
 cout<<"\n1.Create\n2.Inset_Beg\n3.Display\n4.Delete Begin\n5.Delete End\n6.Delete Specified\n7.Exit\n";
 cout<<"Enter your choice";
 cin>>ch;
  switch (ch) {
	    case 1:
		l.create();
		break;
	    case 2:
		l.insert_beg();
		break;
	    case 3:
		l.display();
		break;
            case 4:
                l.delete_beg();
                break;
            case 5:
                l.delete_end();
                break;
            case 6:
                l.delete_sp();
                break;
            case 7:
                exit(0);
            default:
                cout << "INVALID CHOICE" << endl;
                break;
        }
    }
 return 0;
 }


