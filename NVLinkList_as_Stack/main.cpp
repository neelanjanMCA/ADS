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
int main(){
 linked l;
 int ch;

 while(1){
    cout<<"\nSTACk OPERATIONS IN LINKLIST\n";
 cout<<"\n1.Create\n2.Display\n3.push\n4.pop\n5.Exit\n";
 cout<<"Enter your choice";
 cin>>ch;
  switch (ch) {
	    case 1:
		l.create();
		break;
	    case 2:
		l.display();
		break;
	    case 3:
		l.insert_beg();
		break;
        case 4:
        l.delete_beg();
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

